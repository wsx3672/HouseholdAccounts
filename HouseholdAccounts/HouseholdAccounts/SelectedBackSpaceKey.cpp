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
	Long currentRowIndex = textEdit->caret->GetCurrentRowIndex();
	Long characterIndex = textEdit->caret->GetCharacterIndex();
	TextComponent *textComponent = textEdit->text->GetAt(currentRowIndex - 1);
	TextComposite *textComposite = textComponent->GetComposite();
	Long length = textComposite->GetLength();
	Long selectedLength = textEdit->textAreaSelected->GetLength();
	TextComponent *compareTextComponent = 0;
	while (selectedLength > 0 ) {
		TextComponent *temp = textEdit->textAreaSelected->GetAt(0);
		j = 0;
		while (j < length && temp !=compareTextComponent) {
			compareTextComponent = textComposite->GetAt(j);
			j++;
		}
		if ( temp == compareTextComponent) {
			textComposite->Remove(compareTextComponent);
			textEdit->textAreaSelected->Remove(compareTextComponent);
		}
		selectedLength--;
	}
	textEdit->caret->CreateCaret();
}