#include "EnterKey.h"
#include "Row.h"
#include "Text.h"
#include "TextComponent.h"
#include "TextComposite.h"
#include "TextEdit.h"
#include "SingleByteCharacter.h"
EnterKey::EnterKey() {
}
EnterKey::~EnterKey() {
}
EnterKey::EnterKey(const EnterKey& source) {
}
EnterKey& EnterKey::operator=(const EnterKey& source) {
	return *this;
}
void EnterKey::Action(TextEdit *textEidt) {
	Long length = textEidt->text->GetLength();
	TextComponent *textComponent = textEidt->text->GetAt(length - 1);
	TextComposite *textComposite = textComponent->GetComposite();
	SingleByteCharacter *singleByteCharacter = new SingleByteCharacter('\n');
	textComposite->Add(singleByteCharacter);
	Row *row = new Row();
	textEidt->text->Add(row);
}
