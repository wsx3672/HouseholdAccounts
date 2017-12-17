#ifndef _TEXTEDIT_H
#define _TEXTEDIT_H

#include <afxwin.h>
#include <imm.h>
typedef signed long int  Long;
class HouseholdAccountsForm;
class Text;
class KeyBoard;
class Caret;
class TextAreaSelected;
class TextEdit : public CWnd {
public:
	TextEdit(HouseholdAccountsForm *householdAccountsForm);
public:
	afx_msg void OnClose();
protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnPaint();
	afx_msg void OnKeyDown(UINT nChar,UINT nRepCnt,UINT nFlags);
	afx_msg Long OnComposition(WPARAM wParam, LPARAM lParam);
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	DECLARE_MESSAGE_MAP()
private:
	HouseholdAccountsForm *householdAccountsForm;
public:
	Text *text;
	KeyBoard *keyBoard;	
	Caret *caret;
	TextAreaSelected *textAreaSelected;
	bool writingKoreanState;
	bool selectedArea;
	Long keyDownCheck;
};
#endif // !_TEXTEDIT_H
