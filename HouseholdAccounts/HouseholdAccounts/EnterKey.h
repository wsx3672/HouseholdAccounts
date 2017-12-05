#ifndef _ENTERKEY_H
#define _ENTERKEY_H
#include "KeyAction.h"
class TextEdit;
class EnterKey : public KeyAction{
public:
	EnterKey();
	virtual ~EnterKey();
	EnterKey(const EnterKey& source);

	EnterKey& operator= (const EnterKey& source);
	virtual void Action(TextEdit *textEidt);
};
#endif // !_ENTERKEY_H
