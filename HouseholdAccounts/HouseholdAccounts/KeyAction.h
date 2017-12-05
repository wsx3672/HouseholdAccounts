#ifndef _KEYACTION_H
#define _KEYACTION_H
class TextEdit;
class KeyAction {
public:
	KeyAction();
	virtual ~KeyAction();
	KeyAction(const  KeyAction& source);

	virtual  void Action(TextEdit *textEdit);

	KeyAction& operator= (const  KeyAction& source);
};
#endif // !_KEYACTION_H
