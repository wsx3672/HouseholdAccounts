#include "RightArrowKey.h"
#include "TextEdit.h"
#include "Caret.h"
RightArrowKey::RightArrowKey() {
}
RightArrowKey::~RightArrowKey() {
}
RightArrowKey::RightArrowKey(const RightArrowKey& source) {
}
RightArrowKey& RightArrowKey::operator=(const RightArrowKey& source) {
	return *this;
}
void RightArrowKey::Action(TextEdit *textEdit) {
	textEdit->caret->RightArrowKeyMovingCaret();
}