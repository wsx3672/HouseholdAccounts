#include "SelectedBackSpaceKey.h"
#include "TextEdit.h"
#include "TextAreaSelected.h"
#include "Text.h"
#include "Caret.h"
SelectedBackSpaceKey::SelectedBackSpaceKey() {
}
SelectedBackSpaceKey::~SelectedBackSpaceKey() {
}
SelectedBackSpaceKey::SelectedBackSpaceKey(const SelectedBackSpaceKey& source) {
}
SelectedBackSpaceKey& SelectedBackSpaceKey::operator=(const SelectedBackSpaceKey& source) {
	return *this;
}
void SelectedBackSpaceKey::Action(TextEdit *textEdit) {
	Long j;
	Long i;
	Long startRowIndex = textEdit->textAreaSelected->GetStartRowIndex();
	Long currentRowIndex = textEdit->caret->GetCurrentRowIndex();
	Long characterIndex = textEdit->caret->GetCharacterIndex();
	TextComponent *textComponent;//= textEdit->text->GetAt(currentRowIndex - 1);
	TextComposite *textComposite;//= textComponent->GetComposite();
	Long length;//= textComposite->GetLength();
	Long selectedLength = textEdit->textAreaSelected->GetLength();
	TextComponent *compareTextComponent = 0;
	Long firstRowIndex;
	Long secondRowIndex;
	Long first;
	Long second;
	if (startRowIndex > currentRowIndex) {
		first = currentRowIndex;
		second = startRowIndex;
	}
	else {
		first = startRowIndex;
		second = currentRowIndex;
	}//¼öÁ¤
	while (selectedLength != 0) {
		TextComponent *temp = textEdit->textAreaSelected->GetAt(0);
		firstRowIndex = first;
		secondRowIndex = second;
		while (firstRowIndex <= secondRowIndex) {
			textComponent = textEdit->text->GetAt(firstRowIndex - 1);
			textComposite = textComponent->GetComposite();
			length = textComposite->GetLength();
			i = 0;
			compareTextComponent = 0;
			while (i < length && temp != compareTextComponent) {
					compareTextComponent = textComposite->GetAt(i);
					i++;
				}
				if (temp == compareTextComponent) {
					textComposite->Remove(compareTextComponent);
					textEdit->textAreaSelected->Remove(compareTextComponent);
				}
			firstRowIndex++;
		}
		selectedLength = textEdit->textAreaSelected->GetLength();
	}

	/*
	while(firstRowIndex <= secondRowIndex && selectedLength != 0){
		textComponent= textEdit->text->GetAt(firstRowIndex - 1);
		textComposite= textComponent->GetComposite();
		length = textComposite->GetLength();
		i = 0;
		while (i < length ) {
			TextComponent *temp = textEdit->textAreaSelected->GetAt(0);
			j = 0;
			while (j < length && temp != compareTextComponent) {
				compareTextComponent = textComposite->GetAt(j);
				j++;
			}
			if (temp == compareTextComponent) {
				textComposite->Remove(compareTextComponent);
				textEdit->textAreaSelected->Remove(compareTextComponent);
			}
			i++;
		}
		selectedLength = textEdit->textAreaSelected->GetLength();
		firstRowIndex++;
	}
	*/
	Long startCharacterIndex = textEdit->textAreaSelected->GetStartCharacterIndex();
	if (startCharacterIndex < characterIndex) {
		CString cString = textComposite->MakeCString(startCharacterIndex);
		CFont font;
		textEdit->caret->FontSetting(&font);
		CClientDC dc(textEdit);
		dc.SelectObject(font);
		CSize size = dc.GetTextExtent(cString);
		textEdit->caret->SetCurrentX(size.cx );
		textEdit->caret->SetCharacterIndex(startCharacterIndex);
	}
	textEdit->selectedArea = false;
	textEdit->caret->CreateCaret();
}