#include "UpArrowKey.h"
#include "TextEdit.h"
#include "Caret.h"
UpArrowKey::UpArrowKey() {
}
UpArrowKey::~UpArrowKey() {
}
UpArrowKey::UpArrowKey(const UpArrowKey& source) {
}
UpArrowKey& UpArrowKey::operator=(const UpArrowKey& source) {
	return *this;
}
void UpArrowKey::Action(TextEdit *textEdit) {
	textEdit->caret->UpArrowKeyMovingCaret();
}