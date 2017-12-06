#include "Caret.h"
#include "TextEdit.h"
#include "Text.h"
#include "Row.h"
#include "TextComponent.h"
#include "TextComposite.h"
#include "SingleByteCharacter.h"
#include "DoubleByteCharacter.h"
#include <afxwin.h>
Caret::Caret(TextEdit *textEdit) {
	this->textEdit = textEdit;
	this->currentX = 10;
	this->currentY = 0;
}
Caret::Caret(const Caret& source) {
	this->textEdit = source.textEdit;
}
Caret::~Caret() {
}
Caret& Caret::operator=(const Caret& source) {
	this->textEdit = source.textEdit;
	return *this;
}
void Caret::CreateCaret(Long width , Long height ) {
	this->textEdit->CreateSolidCaret(width, height);
	CPoint cPoint(this->currentX, this->currentY);
	this->textEdit->SetCaretPos(cPoint);
	this->textEdit->ShowCaret();
}
void Caret::ChangeCaretWidth() {
	this->textEdit->CreateSolidCaret(2, 16);
}
void Caret::RightMovingCaret() {
	Long length = this->textEdit->text->GetLength();
	CClientDC  dc(this->textEdit);
	CSize size;
	CFont font;
	this->FontSetting(&font);
	dc.SelectObject(font);
	TextComponent *textComponent = this->textEdit->text->GetAt(length - 1);
	CString cString = static_cast<Row*>(textComponent)->MakeCString();
	size = dc.GetTextExtent(cString);
	this->currentX = size.cx +10;
	CPoint cPoint(this->currentX, this->currentY);
	this->textEdit->SetCaretPos(cPoint);
}
void Caret::LeftMovingCaret() {
	Long length = this->textEdit->text->GetLength();
	CClientDC  dc(this->textEdit);
	CSize size;
	CFont font;
	this->FontSetting(&font);
	dc.SelectObject(font);
	TextComponent *textComponent = this->textEdit->text->GetAt(length - 1);
	TextComposite *textComposite = textComponent->GetComposite();
	CString cString = textComposite->MakeCString();
	size = dc.GetTextExtent(cString);
	this->currentX = size.cx + 10;
	CPoint cPoint(this->currentX, this->currentY);
	this->textEdit->SetCaretPos(cPoint);
}
void Caret::IncludeDoubleByteCharacter() {
	Long length = this->textEdit->text->GetLength();
	CClientDC  dc(this->textEdit);
	CSize size;
	CFont font;
	this->FontSetting(&font);
	dc.SelectObject(font);
	TextComponent *textComponent = this->textEdit->text->GetAt(length - 1);
	TextComposite *textComposite = textComponent->GetComposite();
	Long rowLenght = textComposite->GetLength();
	DoubleByteCharacter *doubleByteCharacter = static_cast<DoubleByteCharacter*>(textComposite->GetAt(rowLenght - 1));
	char *temps = doubleByteCharacter->GetCharacter();
	temps[2] = '\0';
	size = dc.GetTextExtent(temps);
	this->CreateCaret(size.cx , 16);
}
void Caret::FontSetting(CFont *font) {
	font->CreateFont(17, 0, 0, 0, FW_NORMAL, FALSE, FALSE, 0, DEFAULT_CHARSET,
		OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_SWISS, "∞ÌµÒ√º");
}