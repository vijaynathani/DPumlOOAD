#include <iostream>
#include <vector>
using namespace std;
class Point {
	//x,y co-ordinates
};
class Graphics {
	//...
};
class Shape {
	public:
        virtual draw(Graphics &gr) = 0;
};
class Line : public Shape {
    Point *start, *end;
	public:
        draw(Graphics &gr) { gr.drawLine(*start, *end); }
};
class Rectangle : public Shape {
    Point *lowerLeftCorner, *upperRightCorner;
	public:
        draw(Graphics &gr) { gr.drawLine(...)); <<4 times>> }
};
class Circle : public Shape {
    Point *center;
    int radius;
   	public:
        draw(Graphics &gr) { gr.drawCircle(*center, radius); }
};

class CADApp {
    void drawShapes(Graphics graphics, vector<Shape *> *shapes) {
        for (unsigned int i = 0; i < shapes->size(); i++) 
            shapes->at(i)->draw(graphics);
    }
};
