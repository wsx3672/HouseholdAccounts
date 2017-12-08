#include "DownArrowKey.h"
#include "TextEdit.h"
#include "Caret.h"
DownArrowKey::DownArrowKey() {
}
DownArrowKey::~DownArrowKey() {
}
DownArrowKey::DownArrowKey(const DownArrowKey& source) {
}
DownArrowKey& DownArrowKey::operator=(const DownArrowKey& source) {
	return *this;
}
void DownArrowKey::Action(TextEdit *textEdit) {
	textEdit->caret->DownArrowKeyMovingCaret();
}