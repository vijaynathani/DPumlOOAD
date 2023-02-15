class Font {//..
};
class JFrame {//..
	public: virtual void previewWithFont(Font *font);
};
class JDialog { //...
};

class WordProcessorMainFrame; 
class FontChangeListener {
	public: virtual void onFontChanged(Font *newFont) = 0;
};
class ChooseFontDialog :public JDialog {
	FontChangeListener *fontChangeListener;
	Font *selectedFont;
	public: ChooseFontDialog(FontChangeListener *fontChangeListener) {
		this->fontChangeListener = fontChangeListener;
	}
	bool showOnScreen() { //...
	} 
	Font *getSelectedFontFromUI() {
		//...
	}
	Font *getSelectedFont() {
		return selectedFont;
	}
	void onSelectedFontChange() {
		selectedFont = getSelectedFontFromUI();
		fontChangeListener->onFontChanged(selectedFont);
	}
};
class WordProcessorMainFrame : public JFrame {
	class FontChanged : public FontChangeListener {
		JFrame *m;
		public: FontChanged(JFrame *m) { this->m = m; }
		void onFontChanged(Font *newFont) {
			m->previewWithFont(newFont);
		}
	};
	void onChangeFont() {
		FontChanged fc(this);
		ChooseFontDialog chooseFontDialog(&fc);
		if (chooseFontDialog.showOnScreen()) {
			Font *newFont = chooseFontDialog.getSelectedFont();
			//show the contents using this new font.
		} else {
			//show the contents using the existing font.
		}
	}
	void previewWithFont(Font font) {
		//show the contents using this preview font.
	}
};
