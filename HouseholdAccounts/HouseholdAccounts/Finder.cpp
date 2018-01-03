#include "Finder.h"
#include "TextEdit.h"
#include "Text.h"
#include "TextComponent.h"
#include "TextComposite.h"
#include "Caret.h"
Finder::Finder(TextEdit *textEdit) {
	this->textEdit = textEdit;
}
Finder::Finder(const Finder& source) {
	this->textEdit = source.textEdit;
}
Finder::~Finder() {
}
Finder& Finder::operator=(const Finder& source) {
	this->textEdit = source.textEdit;
	return *this;
}
void Finder::MouseLButtonClick(Long startX, Long startY) {
	Long rowIndex = startY / 17;
	Long length = this->textEdit->text->GetLength();
	rowIndex++;
	if (length < rowIndex) {
		rowIndex = length;
	}
	TextComponent *currentTextComponent = this->textEdit->text->GetAt(rowIndex -1);
	TextComposite *currentTextComposite = currentTextComponent->GetComposite();
	Long rowLength = currentTextComposite->GetLength();
	Long i = 0;
	CSize size;
	CFont font;
	this->textEdit->caret->FontSetting(&font);
	CClientDC dc(this->textEdit);
	dc.SelectObject(font);
	CString cString;
	Long characterIndex;
	Long x = 0;
	Long previousX = 0; 
	while (i < rowLength && x < startX) {
		cString = currentTextComposite->MakeCString(i+1);
		size = dc.GetTextExtent(cString); 
		previousX = x;
		x = size.cx;
		i++;
	}
	if (x < startX) {
		previousX = x;
		characterIndex = rowLength;
	}
	else {
		characterIndex = i-1;
	}
	this->textEdit->caret->SetCharacterIndex(characterIndex);
	this->textEdit->caret->SetCurrentRowIndex(rowIndex);
	this->textEdit->caret->SetCurrentY((rowIndex-1) * 17);
	this->textEdit->caret->SetCurrentX(previousX);
}
