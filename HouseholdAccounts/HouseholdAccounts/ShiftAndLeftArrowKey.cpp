#include "ShiftAndLeftArrowKey.h"
#include "TextEdit.h"
#include "TextAreaSelected.h"
#include "Text.h"
#include "Caret.h"
#include "Character.h"
#include "SingleByteCharacter.h"
#include "DoubleByteCharacter.h"
ShiftAndLeftArrowKey::ShiftAndLeftArrowKey() {
}
ShiftAndLeftArrowKey::~ShiftAndLeftArrowKey() {
}
ShiftAndLeftArrowKey::ShiftAndLeftArrowKey(const ShiftAndLeftArrowKey& source) {
}
ShiftAndLeftArrowKey& ShiftAndLeftArrowKey::operator=(const ShiftAndLeftArrowKey& source) {
	return *this;
}
void ShiftAndLeftArrowKey::Action(TextEdit *textEdit) {
	Long currentRowIndex = textEdit->caret->GetCurrentRowIndex();
	TextComponent *textComponent = textEdit->text->GetAt(currentRowIndex - 1);
	TextComposite *textComposite = textComponent->GetComposite();
	Long characterIndex = textEdit->caret->GetCharacterIndex();
	TextComponent *addTextComponent = textComposite->GetAt(characterIndex-1);
	textEdit->textAreaSelected->Add(addTextComponent);
	textEdit->caret->ShiftAndLeftArrowCaretMoving(addTextComponent);
	//textEdit->caret->LeftArrowKeyMovingCaret();
}