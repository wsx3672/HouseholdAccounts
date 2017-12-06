#ifndef _CARET_H
#define _CARET_H
typedef signed long int Long;
class TextEdit;
class CFont;
typedef signed long int Long;
class Caret {
public:
	Caret(TextEdit *textEdit);
	Caret(const Caret& source);
	~Caret();
	Caret& operator= (const Caret& source);
	void CreateCaret(Long width = 2 ,Long height = 16);
	void ChangeCaretWidth();
	void FontSetting(CFont *font);
	void IncludeDoubleByteCharacter();
	void RightMovingCaret();
	void LeftMovingCaret();
private:
	TextEdit *textEdit;
	Long currentX;
	Long currentY;
};
#endif // !_CARET_H
