#ifndef _BACKSPACEKEY_H
#define _BACKSPACEKEY_H

#include "KeyAction.h"
class TextEdit;
class BackSpaceKey : public KeyAction {
public:
	BackSpaceKey();
	virtual ~BackSpaceKey();
	BackSpaceKey(const BackSpaceKey& source);

	BackSpaceKey& operator= (const BackSpaceKey& source);
	virtual void Action(TextEdit *textEdit);
};
#endif // !_BACKSPACEKEY_H
