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
	TextComponent *textComponent = textComposite->GetAt(rowLength - 1);
	if (textComponent != 0) {
		textComposite->Remove(textComponent);
		textEdit->caret->LeftMovingCaret();
	}
}