#ifndef _DELETEKEYPROCESS_H
#define _DELETEKEYPROCESS_H

class TextEdit;
class DeleteKeyProcess {
public:
	DeleteKeyProcess();
	~DeleteKeyProcess();
	DeleteKeyProcess(const DeleteKeyProcess& source);
	DeleteKeyProcess& operator=(const DeleteKeyProcess& source);

	void SelectionDelete(TextEdit *textEdit);
	void Delete(TextEdit *textEdit);
};
#endif // !_DELETEKEYPROCESS_H
