#include "TextAreaSelected.h"
#include "TextEdit.h"
#include "Character.h"
#include "SingleByteCharacter.h"
#include "Caret.h"
#include "Text.h"
#include "DoubleByteCharacter.h"
#include <afxwin.h>
TextAreaSelected::TextAreaSelected(Long capacity) : TextComposite(capacity){
	this->length = 0;
	this->capacity = capacity;
	this->startRowIndex = -1;
	this->startCharacterIndex = -1;
	this->startX = -1;
	this->startY = -1;
}
void TextAreaSelected::Setting(Caret *caret) {
	this->startRowIndex = caret->GetCurrentRowIndex();
	this->startCharacterIndex = caret->GetCharacterIndex();
	this->startX = caret->GetCurrentX();
	this->startY = caret->GetCurrentY();
}
TextAreaSelected::TextAreaSelected(const TextAreaSelected& source): TextComposite(source) {
	this->length = source.length;
	this->capacity = source.capacity;
}
TextAreaSelected::~TextAreaSelected() {
}
TextAreaSelected& TextAreaSelected::operator=(const TextAreaSelected& source) {
	this->textComponents = source.textComponents;
	this->length = source.length;
	this->capacity = source.capacity;
	return *this;
}
Long TextAreaSelected::Add(TextComponent *textComponent) {
	Long position = TextComposite::Add(textComponent);
	return position;
}
Long TextAreaSelected::Remove(TextComponent *textComponent) {
	Long position = TextComposite::Remove(textComponent);
	return position;
}
Long TextAreaSelected::Remove(Long index) {
	Long position = TextComposite::Remove(index);
	return position;
}
Long TextAreaSelected::Modify(Long index, TextComponent *textComponent) {
	Long position = TextComposite::Modify(index, textComponent);
	return position;
}
Long TextAreaSelected::Insert(Long index, TextComponent *textComponent) {
	Long position = TextComposite::Insert(index, textComponent);
	return position;
}
void TextAreaSelected::SelectedTextArea(TextEdit *textEdit, CDC *pDC) {
	CString cString;
	CSize size;
	Long length = textEdit->textAreaSelected->GetLength();
	Long currnetRowIndex = textEdit->caret->GetCurrentRowIndex();
	TextComponent *textComponent = textEdit->text->GetAt(currnetRowIndex - 1);
	TextComposite *textComposite = textComponent->GetComposite();
	pDC->SetTextColor(RGB(255, 255, 255));
	pDC->SetBkColor(RGB(51, 153, 255));
	pDC->SetBkMode(OPAQUE);//텍스트 배경을 SetBkColor 사용
	Long startCharacterIndex = textEdit->textAreaSelected->GetStartCharacterIndex();
	Long currentCharacterIndex = textEdit->caret->GetCharacterIndex();
	CRect rect;
	if (startCharacterIndex > currentCharacterIndex) {
		cString = textComposite->MakeCString(currentCharacterIndex, startCharacterIndex);
		size = pDC->GetTextExtent(cString);
		rect.left = textEdit->caret->GetCurrentX();
		rect.top = 17 * (this->startRowIndex - 1);
		rect.right = size.cx + textEdit->caret->GetCurrentX();
		rect.bottom = size.cx + textEdit->caret->GetCurrentX() + this->startY + size.cy;
	}
	else {
		cString = textComposite->MakeCString(startCharacterIndex, currentCharacterIndex);
		size = pDC->GetTextExtent(cString);
		rect.left = textEdit->caret->GetCurrentX() - size.cx;
		rect.top = 17 * (this->startRowIndex - 1);
		rect.right = textEdit->caret->GetCurrentX();
		rect.bottom = textEdit->caret->GetCurrentX() + size.cy; 

	}
	size = pDC->GetTextExtent(cString);
	pDC->DrawText(cString, &rect, DT_EXPANDTABS);

	/*
	while (i < length)	{
		Character *character = static_cast<Character*>(textEdit->textAreaSelected->GetAt(i));
		ret = character->CheckingSingleAndDouble();
		if (ret == 0) {
			temp = static_cast<SingleByteCharacter*>(character)->GetCharacter();
			cString = temp;
			size = pDC->GetTextExtent(temp);
		}
		else {
			temps = static_cast<DoubleByteCharacter*>(character)->GetCharacter();
			temps[2] = '\0';
			cString = temps;
			size = pDC->GetTextExtent(temps);
		}
		TextComposite *textComposite = static_cast<TextComposite*>(textEdit->text->GetAt(this->startRowIndex - 1));
		CString string = textComposite->MakeCString(this->startCharacterIndex);
		CSize tempSize = pDC->GetTextExtent(string);
		CRect rect(textEdit->caret->GetCurrentX(),17*(this->startRowIndex - 1), tempSize.cx + textEdit->caret->GetCurrentX()  , tempSize.cx + textEdit->caret->GetCurrentX() + this->startY+tempSize.cy);
	
		pDC->DrawText(cString, &rect, DT_EXPANDTABS);
		i++;
	}
	*/

}
TextComponent* TextAreaSelected::GetAt(Long index) {
	return this->textComponents.GetAt(index);
}
TextComponent* TextAreaSelected::operator[](Long index) {
	return this->textComponents[index];
}
TextComponent* TextAreaSelected::Clone() const {
	return new TextAreaSelected(*this);
}
/*
#include <iostream>
#include "SingleByteCharacter.h"
#include "DoubleByteCharacter.h"
using namespace std;
int main(int argc, char *argv[]) {
	TextAreaSelected textAreaSelected;
	SingleByteCharacter *singleByteCharacter = new SingleByteCharacter('H');
	DoubleByteCharacter *doubleByteCharacter = new DoubleByteCharacter("한");
	textAreaSelected.Add(singleByteCharacter);
	textAreaSelected.Add(doubleByteCharacter);

	Long i = 0;
	Long length = textAreaSelected.GetLength();
	Long capacity = textAreaSelected.GetCapacity();
	Long ret;
	char temp;
	char *temps;
	while (i < length) {
		Character *character = static_cast<Character*>(textAreaSelected.GetAt(i));
		ret = character->CheckingSingleAndDouble();
		if (ret == 0) {
			temp = static_cast<SingleByteCharacter*>(character)->GetCharacter();
			cout << temp << endl;
		}
		else {
			temps = static_cast<DoubleByteCharacter*>(character)->GetCharacter();
			temps[2] = '\0';
			cout << temps << endl;
		}
		i++;
	}
	cout << length << "    " << capacity << endl;
	return 0;
}
*/