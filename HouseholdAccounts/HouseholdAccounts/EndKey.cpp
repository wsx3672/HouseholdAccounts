#include "EndKey.h"
#include "TextEdit.h"
#include "Caret.h"
EndKey::EndKey() {
}
EndKey::~EndKey() {
}
EndKey::EndKey(const EndKey& source) {
}
EndKey& EndKey::operator=(const EndKey& source) {
	return *this;
}
void EndKey::Action(TextEdit *textEdit) {
	textEdit->caret->EndKeyMovingCaret();
}