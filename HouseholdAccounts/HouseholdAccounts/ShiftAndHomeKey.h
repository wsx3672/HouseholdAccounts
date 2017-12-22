#ifndef _SHIFTANDHOMEKEY_H
#define _SHIFTANDHOMEKEY_H

#include "KeyAction.h"
class TextEdit;
class ShiftAndHomeKey : public KeyAction {
public:
	ShiftAndHomeKey();
	virtual ~ShiftAndHomeKey();
	ShiftAndHomeKey(const ShiftAndHomeKey& source);

	ShiftAndHomeKey& operator= (const ShiftAndHomeKey& source);
	virtual void Action(TextEdit *textEdit);
};
#endif // !_SHIFTANDHOMEKEY_H
