#ifndef _SHIFTANDDOWNARROWKEY_H
#define _SHIFTANDDOWNARROWKEY_H

#include "KeyAction.h"
class TextEdit;
class ShiftAndDownArrowKey : public KeyAction {
public:
	ShiftAndDownArrowKey();
	virtual ~ShiftAndDownArrowKey();
	ShiftAndDownArrowKey(const ShiftAndDownArrowKey& source);

	ShiftAndDownArrowKey& operator= (const ShiftAndDownArrowKey& source);
	virtual void Action(TextEdit *textEdit);
};
#endif // !_SHIFTANDDOWNARROWKEY_H
