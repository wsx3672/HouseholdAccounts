#ifndef _UPARROWKEY_H
#define _RIGHTARRO_UPARROWKEY_HWKEY_H

#include "KeyAction.h"
class TextEdit;
class UpArrowKey : public KeyAction {
public:
	UpArrowKey();
	virtual ~UpArrowKey();
	UpArrowKey(const UpArrowKey& source);

	UpArrowKey& operator= (const UpArrowKey& source);
	virtual void Action(TextEdit *textEdit);
};
#endif // !_UPARROWKEY_H
