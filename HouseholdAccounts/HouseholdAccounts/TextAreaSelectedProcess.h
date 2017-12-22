#ifndef _TEXTAREASELECTEDPROCESS_H
#define _TEXTAREASELECTEDPROCESS_H

typedef signed long int Long;
class TextEdit;
class CDC;
class TextComposite;
class TextAreaSelectedProcess {
public:
	TextAreaSelectedProcess();
	~TextAreaSelectedProcess();
	TextAreaSelectedProcess(const TextAreaSelectedProcess& source);
	TextAreaSelectedProcess& operator= (const TextAreaSelectedProcess& source);

	void AllRowAreaSelected(TextEdit *textEdit,CDC *pDC, TextComposite *textComposite, Long index);
	void SingleRowAreaSelected(TextEdit *textEdit, CDC *pDC, TextComposite *textComposite, Long index , Long length ,Long rowIndex);
	void FirstRowAreaSelected(TextEdit *textEdit, CDC *pDC, TextComposite *textComposite, Long index, Long length, Long rowIndex);
	void LastRowAreaSelected(TextEdit *textEdit, CDC *pDC, TextComposite *textComposite, Long index, Long length, Long rowIndex);
};
#endif // !_TEXTAREASELECTEDPROCESS_H

