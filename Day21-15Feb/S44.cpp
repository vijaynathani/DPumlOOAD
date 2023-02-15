//Keep things that vary separate from things that are constant.
class Resource {
	public: virtual int getFree() = 0;
    virtual void markFree(int r) = 0;
};
class File1 : public  Resource {
	public: int getFree() {return 0;}
    void markFree(int r){}
};
class Database1 : public  Resource {
	public: int getFree() {return 0;}
    void markFree(int r){}
};
class ra2{
	public: int allocate(Resource &r) {
    	return r.getFree();
    }
    void free(Resource &r, int resourceId)  {
    	r.markFree(resourceId);
    }
};

