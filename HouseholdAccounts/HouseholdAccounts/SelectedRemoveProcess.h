#ifndef _SELECTEDREMOVEPROCESS_H
#define _SELECTEDREMOVEPROCESS_H
 
typedef signed long int Long;

class TextEdit;
class SelectedRemoveProcess {
public:
	SelectedRemoveProcess();
	~SelectedRemoveProcess();
	SelectedRemoveProcess(const SelectedRemoveProcess& source);

	void SelectedRemove(TextEdit *textEdit);
	void SelectedRemoveAfterSetCaret(TextEdit *textEdit);
};
#endif // !_SELECTEDREMOVEPROCESS_H
