#ifndef _LEFTARROWKEY_H
#define _LEFTARROWKEY_H

#include "KeyAction.h"
class TextEdit;
class LeftArrowKey : public KeyAction {
public:
	LeftArrowKey();
	virtual ~LeftArrowKey();
	LeftArrowKey(const LeftArrowKey& source);

	LeftArrowKey& operator= (const LeftArrowKey& source);
	virtual void Action(TextEdit *textEdit);
};
#endif // !_LEFTARROWKEY_H
