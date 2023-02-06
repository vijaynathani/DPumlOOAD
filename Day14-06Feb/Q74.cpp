#include <iostream>
#include <string>
using namespace std;
class Font { //...
};
class ActionListener { //..
};
class Graphics { //...
};
class Bitmap { //...
};

//remove the problem in code below
class Button {
    Font labelFont;
    string labelText;
    //...
	public: void addActionListener(ActionListener *listener) {
        //...
    } 
    void paint(Graphics *graphics) {
        //draw the label text on the graphics using the label's font.
    }
};
class BitmapButton : Button {
    Bitmap bitmap;
	public: void paint(Graphics *graphics) {
        //draw the bitmap on the graphics.
    }
};
