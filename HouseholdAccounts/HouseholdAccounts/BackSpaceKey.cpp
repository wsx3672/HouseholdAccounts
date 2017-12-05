#include "BackSpaceKey.h"
#include "Row.h"
#include "Text.h"
#include "TextComponent.h"
#include "TextComposite.h"
#include "TextEdit.h"
BackSpaceKey::BackSpaceKey() {
}
BackSpaceKey::~BackSpaceKey() {
}
BackSpaceKey::BackSpaceKey(const BackSpaceKey& source) {
}
BackSpaceKey& BackSpaceKey::operator=(const BackSpaceKey& source) {
	return *this;
}
void BackSpaceKey::Action(TextEdit *textEidt) {
	Long length = textEidt->text->GetLength();
	TextComposite *textComposite = static_cast<TextComposite*>(textEidt->text->GetAt(length - 1));
	Long rowLength = textComposite->GetLength();
	TextComponent *textComponent = textComposite->GetAt(rowLength - 1);
	if (textComponent != 0) {
		textComposite->Remove(textComponent);
	}
}