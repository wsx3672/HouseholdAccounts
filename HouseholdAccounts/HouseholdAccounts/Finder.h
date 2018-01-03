#ifndef _FINDER_H
#define _FINDER_H

typedef signed long int Long;

class TextEdit;
class Finder {
public:
	Finder(TextEdit *textEdit);
	Finder(const Finder& source);
	~Finder();
	Finder& operator = (const Finder& source);

	void MouseLButtonClick(Long startX, Long startY);
	void MouseLButtonDrag(Long currentX, Long currentY);
private:
	TextEdit *textEdit;
};
#endif // !_FINDER_H

