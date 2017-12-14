#ifndef _SELECTEDBACKSPACEKEY_H
#define _SELECTEDBACKSPACEKEY_H

#include "KeyAction.h"
class TextEdit;
class SelectedBackSpaceKey : public KeyAction {
public:
	SelectedBackSpaceKey();
	virtual ~SelectedBackSpaceKey();
	SelectedBackSpaceKey(const SelectedBackSpaceKey& source);

	SelectedBackSpaceKey& operator= (const SelectedBackSpaceKey& source);
	virtual void Action(TextEdit *textEdit);
};
#endif // !_SELECTEDBACKSPACEKEY_H
