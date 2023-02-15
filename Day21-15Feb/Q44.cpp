//We need exclusive access to FILE1 and DATABASE1.
//New resources will be added later on. The design should be able
//accomodate these new resource allocation/deallocation easily.

enum ResourceType { FILE1, DATABASE1 };
class ra1{
	public: int allocate(ResourceType r) {
        int resourceId = 0;
        switch (r) {
        case FILE1:
            resourceId = getFreeFile();
            break;
        case DATABASE1:
            resourceId = getFreeDatabase();
        }
        return resourceId;
    }

    void free(ResourceType r, int resourceId)  {
        switch (r) {
        case FILE1:
            markFileFree(resourceId);
            break;
        case DATABASE1:
            markDatabaseFree(resourceId);
        }
    }
	private: void markDatabaseFree(int a){}
    void markFileFree(int a) {}
    int getFreeFile() {return 0;}
    int getFreeDatabase() {return 0;}
};
