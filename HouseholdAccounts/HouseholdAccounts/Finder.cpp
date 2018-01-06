#include "Finder.h"
#include "TextEdit.h"
#include "Text.h"
#include "TextComponent.h"
#include "TextComposite.h"
#include "Caret.h"
#include "TextAreaSelected.h"
#include "Character.h"
#include "SingleByteCharacter.h"
#include "DoubleByteCharacter.h"
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
void Finder::MouseLButtonDrag(Long currentX, Long currentY) {
	if (this->textEdit->selectedArea == false) {
		this->textEdit->textAreaSelected->Setting(this->textEdit->caret);
	}
	Long startX = this->textEdit->textAreaSelected->GetStartX();
	Long startY = this->textEdit->textAreaSelected->GetStartY();
	Long currentCharacterIndex = this->textEdit->caret->GetCharacterIndex();
	Long startRowIndex = startY / 17;
	Long currentRowIndex = 1 + (currentY / 17);
	Long length = this->textEdit->text->GetLength();
	if (currentRowIndex > length) {
		currentRowIndex = length;
	}
	TextComponent *currentTextComponent = this->textEdit->text->GetAt(currentRowIndex - 1);
	TextComposite *currentTextComposite = currentTextComponent->GetComposite();
	TextComponent *textComponent = 0;
	CClientDC  dc(this->textEdit);
	CSize size;
	CSize stringSize;
	CFont font;
	CString cString;
	this->textEdit->caret->FontSetting(&font);
	dc.SelectObject(font);
	char temp;
	char *temps;
	cString = currentTextComposite->MakeCString(currentCharacterIndex);
	stringSize = dc.GetTextExtent(cString);

	if (startX > currentX && currentCharacterIndex != 0) {
		textComponent = currentTextComposite->GetAt(currentCharacterIndex - 1);
		Character *character = static_cast<Character*>(textComponent);
		Long ret = character->CheckingSingleAndDouble();
		if (ret == 0) {
			SingleByteCharacter *singleByteCharacter = static_cast<SingleByteCharacter*>(character);
			temp = singleByteCharacter->GetCharacter();
			size = dc.GetTextExtent(temp);
		}
		else {
			DoubleByteCharacter *doubleByteCharacter = static_cast<DoubleByteCharacter*>(character);
			temps = doubleByteCharacter->GetCharacter();
			temps[2] = '\0';
			size = dc.GetTextExtent(temps);
		}
		if (stringSize.cx - (size.cx / 2) > currentX) {
			this->textEdit->textAreaSelected->Add(textComponent);
			this->textEdit->caret->LeftArrowKeyMovingCaret();
		}
	}
	length = this->textEdit->textAreaSelected->GetLength();
	if (length != 0) {
		this->textEdit->selectedArea = true;
	}
}
