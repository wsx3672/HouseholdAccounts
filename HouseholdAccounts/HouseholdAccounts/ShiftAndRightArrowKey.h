#ifndef _SHIFTANDRIGHTARROWKEY_H
#define _SHIFTANDRIGHTARROWKEY_H

#include "KeyAction.h"
class TextEdit;
class ShiftAndRightArrowKey : public KeyAction {
public:
	ShiftAndRightArrowKey();
	virtual ~ShiftAndRightArrowKey();
	ShiftAndRightArrowKey(const ShiftAndRightArrowKey& source);

	ShiftAndRightArrowKey& operator= (const ShiftAndRightArrowKey& source);
	virtual void Action(TextEdit *textEdit);
};
#endif // !_SHIFTANDRIGHTARROWKEY_H
