#include <iostream>
#include <stdexcept>
#include <thread>
#include <chrono>
#include <boost/thread.hpp>

using namespace std;

class Runnable {
public: 
	virtual void run() = 0;
	virtual ~Runnable() {}
};
static const int TEN_SECONDS_DEFAULT_TIMEOUT = 10;
class Timed_out_exception : public exception {
};
class CircuitBreaker {
	int timeout_in_seconds;
	boost::thread *thread;
public:
	Runnable* volatile task;
	CircuitBreaker() :
		timeout_in_seconds(TEN_SECONDS_DEFAULT_TIMEOUT),
		task(0), thread(0) {}
	void set_time_limit(int seconds) {
		timeout_in_seconds = seconds;
	}
	void make_call(Runnable* r);
};
static void initialize_thread(CircuitBreaker* data) {
	data->task->run();
}
void CircuitBreaker::make_call(Runnable* r) {
	task = r;
	thread = new boost::thread(initialize_thread, this);
	if (thread->timed_join(boost::posix_time::seconds(timeout_in_seconds)))
		return;
	thread->interrupt();
	throw Timed_out_exception();
}

//Main program for testing purposes only
class My_task : public Runnable {		
public: 
	void run() {
		cout << "Task started\n";
		this_thread::sleep_for(chrono::seconds(11));
			//If the sleep value is above 10, task will be aborted.
		cout << "Task ended\n";
	}
};
void circuitBreakerMain() {
	CircuitBreaker c;
	My_task t;
	try {
		c.make_call(&t);
	}
	catch (Timed_out_exception&) {
		cout << "Timeout exception thrown\n";
	}
}
