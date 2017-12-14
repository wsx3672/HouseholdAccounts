#include "HomeKey.h"
#include "TextEdit.h"
#include "Caret.h"
HomeKey::HomeKey() {
}
HomeKey::~HomeKey() {
}
HomeKey::HomeKey(const HomeKey& source) {
}
HomeKey& HomeKey::operator=(const HomeKey& source) {
	return *this;
}
void HomeKey::Action(TextEdit *textEdit) {
	textEdit->caret->HomeKeyMovingCaret();
}