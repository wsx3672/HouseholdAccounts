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
	void CreateCaret(Long width = 2 ,Long height = 17);
	void ChangeCaretWidth();
	void FontSetting(CFont *font);
	void IncludeDoubleByteCharacter();
	void RightMovingCaret();
	void BackSpaceKeyMovingCaret();
	void NextRowMovingCaret();
	void PreviousRowMovingCaret();
	void LeftArrowKeyMovingCaret();
	void RightArrowKeyMovingCaret();
	void UpArrowKeyMovingCaret();
	void DownArrowKeyMovingCaret();
	Long GetCurrentX() const;
	Long GetCurrentY() const;
	Long GetCurrentRowIndex() const;
	Long SetCurrentRowIndex(Long currentRowIndex);
	Long SetCharacterIndex(Long characterIndex);
	Long GetCharacterIndex() const;
private:
	TextEdit *textEdit;
	Long currentX;
	Long currentY;
	Long currentRowIndex;
	Long characterIndex;
};
inline Long Caret::GetCurrentX() const {
	return this->currentX;
}
inline Long Caret::GetCurrentY() const {
	return this->currentY;
}
inline Long Caret::GetCurrentRowIndex() const {
	return this->currentRowIndex;
}
inline Long Caret::GetCharacterIndex() const {
	return this->characterIndex;
}
#endif // !_CARET_H
