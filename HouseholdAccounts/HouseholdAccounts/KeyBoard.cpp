#include "Keyboard.h"
#include "KeyAction.h"
#include "EnterKey.h"
#include "KoreanEnglishChangeKey.h"
#include "BackSpaceKey.h"
#include "LeftArrowKey.h"
#include "RightArrowKey.h"
#include "UpArrowKey.h"
#include "DownArrowKey.h"
#include "HomeKey.h"
#include "EndKey.h"
#include "DeleteKey.h"
#include "ShiftAndLeftArrowKey.h"
#include "SelectedBackSpaceKey.h"
#include "TextEdit.h"
#include "TextAreaSelected.h"
#include "ShiftAndRightArrowKey.h"
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
	Long selectedLength = textEdit->textAreaSelected->GetLength();
	switch (nChar)
	{
	case VK_RETURN:this->keyAction = new EnterKey; break;
	case VK_BACK:
		if (selectedLength > 0) {
			this->keyAction = new SelectedBackSpaceKey; break;
		}
		else {
			this->keyAction = new BackSpaceKey; break;
		}
	case 229:this->keyAction = new KoreanEnglishChangeKey; break; //�ѿ�Ű
	case VK_LEFT:
		if (nFlags && GetKeyState(VK_SHIFT) >= 0) {
			this->keyAction = new LeftArrowKey; break;
		}
		else {
			this->keyAction = new ShiftAndLeftArrowKey; break;
		}
	case VK_RIGHT:	
		if (nFlags && GetKeyState(VK_SHIFT) >= 0) {
			this->keyAction = new RightArrowKey; break;
		}
		else {
			this->keyAction = new ShiftAndRightArrowKey; break;
		}
	case VK_UP:this->keyAction = new UpArrowKey; break;
	case VK_DOWN:this->keyAction = new DownArrowKey; break;
	case VK_HOME:this->keyAction = new HomeKey; break;
	case VK_END:this->keyAction = new EndKey; break;
	case VK_DELETE:this->keyAction = new DeleteKey; break;
	default: break;
	}
	return this->keyAction;
}