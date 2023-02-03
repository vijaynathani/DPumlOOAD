#include <iostream>
#include <vector>
using namespace std;
//Improve the code
class Point {
	//x,y co-ordinates
};
class Shape {
    int shapeType;

    //starting point of the line.
    //lower left corner of the rectangle.
    //center of the circle.
    Point *p1;

    //ending point of the line.
    //upper right corner of the rectangle.
    //not used for the circle.
    Point *p2;

    int radius;
	public:
    static const int TYPELINE = 0;
    static const int TYPERECTANGLE = 1;
    static const int TYPECIRCLE = 2;
	int getType() { return shapeType; }
	//...
};
class Graphics {
	//...
};
class CADApp {
    void drawShapes(Graphics graphics, vector<Shape *> *shapes) {
        for (unsigned int i = 0; i < shapes->size(); i++) {
            switch (shapes->at(i)->getType()) {
			case Shape::TYPELINE:
                graphics.drawLine(*(shapes->at(i)->getP1()), 
						*(shapes->at(i)->getP2()));
                break;
			case Shape::TYPERECTANGLE:
                //draw the four edges.
                graphics.drawLine(...);
                graphics.drawLine(...);
                graphics.drawLine(...);
                graphics.drawLine(...);
                break;
			case Shape::TYPECIRCLE:
                graphics.drawCircle(*(shapes->at(i)->.getP1()),
                       shapes->at(i)->getRadius());
                break;
            }
        }
    }
};
