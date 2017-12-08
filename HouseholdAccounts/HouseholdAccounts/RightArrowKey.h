#ifndef _RIGHTARROWKEY_H
#define _RIGHTARROWKEY_H

#include "KeyAction.h"
class TextEdit;
class RightArrowKey : public KeyAction {
public:
	RightArrowKey();
	virtual ~RightArrowKey();
	RightArrowKey(const RightArrowKey& source);

	RightArrowKey& operator= (const RightArrowKey& source);
	virtual void Action(TextEdit *textEdit);
};
#endif // !_RIGHTARROWKEY_H
