#include "ShiftAndRightArrowKey.h"
#include "TextEdit.h"
#include "TextAreaSelected.h"
#include "Text.h"
#include "Caret.h"
#include "Character.h"
#include "SingleByteCharacter.h"
#include "DoubleByteCharacter.h"
ShiftAndRightArrowKey::ShiftAndRightArrowKey() {
}
ShiftAndRightArrowKey::~ShiftAndRightArrowKey() {
}
ShiftAndRightArrowKey::ShiftAndRightArrowKey(const ShiftAndRightArrowKey& source) {
}
ShiftAndRightArrowKey& ShiftAndRightArrowKey::operator=(const ShiftAndRightArrowKey& source) {
	return *this;
}
void ShiftAndRightArrowKey::Action(TextEdit *textEdit) {
	if (textEdit->selectedArea == false) {
		textEdit->textAreaSelected->Setting(textEdit->caret);
		textEdit->selectedArea = true;
	}
	Long currentRowIndex = textEdit->caret->GetCurrentRowIndex();
	TextComponent *textComponent = textEdit->text->GetAt(currentRowIndex - 1);
	TextComposite *textComposite = textComponent->GetComposite();
	Long characterIndex = textEdit->caret->GetCharacterIndex();
	TextComponent *getTextComponent = textComposite->GetAt(characterIndex);
	Long length = textEdit->textAreaSelected->GetLength();
	TextComponent *compareTextComponent = textEdit->textAreaSelected->GetAt(length - 1);
	if (getTextComponent == compareTextComponent) {
		textEdit->textAreaSelected->Remove(length - 1);
		textEdit->caret->RightArrowKeyMovingCaret();
	}
	else {
		textEdit->textAreaSelected->Add(getTextComponent);
		textEdit->caret->ShiftAndRightArrowCaretMoving(getTextComponent);
	}
}