#include "SelectedBackSpaceKey.h"
#include "TextEdit.h"
#include "TextAreaSelected.h"
#include "Text.h"
#include "Caret.h"
#include "SelectedRemoveProcess.h"
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
	SelectedRemoveProcess selectedRemoveProcess;

	selectedRemoveProcess.SelectedRemove(textEdit);
	Long length = textEdit->text->GetLength();
	if (length == 0) {
		Row *row = new Row();
		textEdit->text->Add(row);
	}
	Long startRowIndex = textEdit->textAreaSelected->GetStartRowIndex();
	Long currentRowIndex = textEdit->caret->GetCurrentRowIndex();
	Long characterIndex = textEdit->caret->GetCharacterIndex();
	TextComponent *textComponent = textEdit->text->GetAt(currentRowIndex - 1);
	TextComposite *textComposite = textComponent->GetComposite();
	CString cString;
	CFont font;
	textEdit->caret->FontSetting(&font);
	CClientDC dc(textEdit);
	dc.SelectObject(font);
	Long startCharacterIndex = textEdit->textAreaSelected->GetStartCharacterIndex();
	if ( startRowIndex == currentRowIndex && startCharacterIndex < characterIndex) {
		cString = textComposite->MakeCString(startCharacterIndex);
		textEdit->caret->SetCharacterIndex(startCharacterIndex);
	}
	else if (startRowIndex == currentRowIndex && startCharacterIndex > characterIndex) {
		cString = textComposite->MakeCString(characterIndex);
		textEdit->caret->SetCharacterIndex(characterIndex);
	}
	else if (startRowIndex > currentRowIndex) {
		cString = textComposite->MakeCString(characterIndex);
		textEdit->caret->SetCharacterIndex(characterIndex);
	}
	else{
		cString = textComposite->MakeCString(characterIndex);
		textEdit->caret->SetCharacterIndex(characterIndex);
	}
	CSize size = dc.GetTextExtent(cString);
	textEdit->caret->SetCurrentX(size.cx);
	textEdit->selectedArea = false;
	textEdit->caret->CreateCaret();
}
