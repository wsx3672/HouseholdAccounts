#include "DeleteKey.h"
#include "TextEdit.h"
#include "Text.h"
#include "Caret.h"

#include "TextComponent.h"
#include "TextComposite.h"
DeleteKey::DeleteKey() {
}
DeleteKey::~DeleteKey() {
}
DeleteKey::DeleteKey(const DeleteKey& source) {
}
DeleteKey& DeleteKey::operator=(const DeleteKey& source) {
	return *this;
}
void DeleteKey::Action(TextEdit *textEdit) {
	Long currentRowIndex = textEdit->caret->GetCurrentRowIndex();
	Long characterIndex = textEdit->caret->GetCharacterIndex();
	TextComponent *textComponent = textEdit->text->GetAt(currentRowIndex - 1);
	TextComposite *textComposite = textComponent->GetComposite();
	Long length = textComposite->GetLength();
	TextComponent *deleteTextComponent = 0;
	if (length > characterIndex) {
		deleteTextComponent = textComposite->GetAt(characterIndex);
	}
	if (deleteTextComponent != 0) {
		textComposite->Remove(deleteTextComponent);
	}
}