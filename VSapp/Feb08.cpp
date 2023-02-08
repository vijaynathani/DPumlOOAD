#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
using namespace std;
namespace feb08 {
	class Point1 {
	private:
		int x, y;
	public:
		Point1(int x1, int y1) : x(x1), y(y1) {}
		int getX() const { return x; }
		int getY() const { return y; }
		void setX(int x1) { x = x1; }
		void setY(int y1) { y = y1; }
		void move(int dx, int dy) {
			x += dx;
			y += dy;
		}
	};
	class Point2 {
	private:
		const int x, y;
	public:
		Point2(int x1, int y1) : x(x1), y(y1) {}  
		int getX() const { return x; }
		int getY() const { return y; }
		Point2* move(int dx, int dy) const {
			return new Point2(x + dx, y + dy);
		}
	};
}
using namespace feb08;
void feb08Main() {
	Point1 p1(1,2);
	p1.move(1, 5);
	Point2 p2(3, 4);
	Point2* p2moved = p2.move(1, 5);
	//...
	delete p2moved;
}