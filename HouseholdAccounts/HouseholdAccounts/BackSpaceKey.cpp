#include "BackSpaceKey.h"
#include "Row.h"
#include "Text.h"
#include "TextComponent.h"
#include "TextComposite.h"
#include "TextEdit.h"
#include "Caret.h"
BackSpaceKey::BackSpaceKey() {
}
BackSpaceKey::~BackSpaceKey() {
}
BackSpaceKey::BackSpaceKey(const BackSpaceKey& source) {
}
BackSpaceKey& BackSpaceKey::operator=(const BackSpaceKey& source) {
	return *this;
}	
void BackSpaceKey::Action(TextEdit *textEdit) {
	Long length = textEdit->text->GetLength();
	TextComposite *textComposite = static_cast<TextComposite*>(textEdit->text->GetAt(length - 1));
	Long rowLength = textComposite->GetLength();
	TextComponent *textComponent = 0;
	if (rowLength == 0 && length != 1) {
		textEdit->text->Remove(textComposite);
		Long currentRowIndex = textEdit->caret->GetCurrentRowIndex();
		currentRowIndex--;
		textEdit->caret->SetCurrentRowIndex(currentRowIndex);
		textEdit->caret->PreviousRowMovingCaret();
		length = textEdit->text->GetLength();
		textComposite = static_cast<TextComposite*>(textEdit->text->GetAt(length - 1));
		rowLength = textComposite->GetLength();
		textEdit->caret->SetCharacterIndex(rowLength);

	}
	if (rowLength != 0) {
		textComponent = textComposite->GetAt(rowLength - 1);
	}
	if (textComponent != 0) {
		textComposite->Remove(textComponent);
		textEdit->caret->BackSpaceKeyMovingCaret();
	}
}