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

class Button {
	//...
	public: void addActionListener(ActionListener *listener) {
		//...
	} 
	virtual void paint(Graphics *graphics) = 0;
};
class LabelButton : public Button {
	Font labelFont;
	string labelText;
	public: void paint(Graphics *graphics) {
		//draw the label text on the graphics using the label's font.
	}
};
class BitmapButton : public Button {
	Bitmap bitmap;
	public: void paint(Graphics *graphics) {
		//draw the bitmap on the graphics.
	}
};
