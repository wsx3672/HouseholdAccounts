#include "Keyboard.h"
#include "KeyAction.h"
#include "EnterKey.h"
#include "BackSpaceKey.h"
KeyBoard::KeyBoard() {
	this->keyAction = 0;
}
KeyBoard::~KeyBoard() {
}
KeyBoard::KeyBoard(const KeyBoard& source) {
	this->keyAction = source.keyAction;
}
KeyBoard& KeyBoard::operator=(const KeyBoard& source) {
	this->keyAction = source.keyAction;
	return *this;
}
KeyAction* KeyBoard::Action(TextEdit *textEdit, UINT nChar, UINT nRepCnt, UINT nFlags) {
	if (this->keyAction != 0) {
		delete this->keyAction;
		this->keyAction = 0;
	}
	switch (nChar)
	{
	case VK_RETURN:this->keyAction = new EnterKey; break;
	case VK_BACK:this->keyAction = new BackSpaceKey; break;
	default: break;
	}
	return this->keyAction;
}