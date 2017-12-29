#ifndef _CTRLANDAKEY_H
#define _CTRLANDAKEY_H

#include "KeyAction.h"
class TextEdit;
class CtrlAndAKey : public KeyAction {
public:
	CtrlAndAKey();
	virtual ~CtrlAndAKey();
	CtrlAndAKey(const CtrlAndAKey& source);

	CtrlAndAKey& operator= (const CtrlAndAKey& source);
	virtual void Action(TextEdit *textEdit);
};
#endif // !_CTRLANDAKEY_H
