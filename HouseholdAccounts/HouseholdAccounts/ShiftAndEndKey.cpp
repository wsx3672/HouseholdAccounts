#include "ShiftAndEndKey.h"
#include "TextEdit.h"
#include "TextAreaSelected.h"
#include "Text.h"
#include "Caret.h"
#include "TextComponent.h"
#include "TextComposite.h"
ShiftAndEndKey::ShiftAndEndKey() {
}
ShiftAndEndKey::~ShiftAndEndKey() {
}
ShiftAndEndKey::ShiftAndEndKey(const ShiftAndEndKey& source) {
}
ShiftAndEndKey& ShiftAndEndKey::operator=(const ShiftAndEndKey& source) {
	return *this;
}
void ShiftAndEndKey::Action(TextEdit *textEdit) {
	if (textEdit->selectedArea == false) {
		textEdit->textAreaSelected->Setting(textEdit->caret);
		textEdit->selectedArea = true;
	}
	Long currentRowIndex = textEdit->caret->GetCurrentRowIndex();
	Long currentCharacterIndex = textEdit->caret->GetCharacterIndex();
	Long startCharacterIndex = textEdit->textAreaSelected->GetStartCharacterIndex();
	Long length = textEdit->text->GetLength();
	TextComponent *currentTextComponent = textEdit->text->GetAt(currentRowIndex - 1);
	TextComposite *currentTextComposite = currentTextComponent->GetComposite();
	Long currentRowLength = currentTextComposite->GetLength();
	if (length != currentRowIndex) {
		currentRowLength--;
	}
	TextComponent *textComponent = 0;
	while (currentCharacterIndex < startCharacterIndex) {
		textComponent = currentTextComposite->GetAt(currentCharacterIndex);
		textEdit->textAreaSelected->Remove(textComponent);
		currentCharacterIndex++;
	}
	while (currentCharacterIndex < currentRowLength) {
		textComponent = currentTextComposite->GetAt(currentCharacterIndex);
		textEdit->textAreaSelected->Add(textComponent);
		currentCharacterIndex++;
	}
	textEdit->caret->EndKeyMovingCaret();
	currentCharacterIndex = textEdit->caret->GetCharacterIndex();
	if (startCharacterIndex == currentCharacterIndex) {
		textEdit->selectedArea = false;
	}
}