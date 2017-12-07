#include "LeftArrowKey.h"
#include "TextEdit.h"
#include "Caret.h"
LeftArrowKey::LeftArrowKey() {
}
LeftArrowKey::~LeftArrowKey() {
}
LeftArrowKey::LeftArrowKey(const LeftArrowKey& source) {
}
LeftArrowKey& LeftArrowKey::operator=(const LeftArrowKey& source) {
	return *this;
}
void LeftArrowKey::Action(TextEdit *textEdit) {
	textEdit->caret->LeftArrowKeyMovingCaret();
}