#ifndef _TEXTEDIT_H
#define _TEXTEDIT_H

#include <afxwin.h>
class HouseholdAccountsForm;
class Text;
class KeyBoard;
class TextEdit : public CWnd {
public:
	TextEdit(HouseholdAccountsForm *householdAccountsForm);
public:
	afx_msg void OnClose();
protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnPaint();
	afx_msg void OnKeyDown(UINT nChar,UINT nRepCnt,UINT nFlags);
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	DECLARE_MESSAGE_MAP()
private:
	HouseholdAccountsForm *householdAccountsForm;
public:
	Text *text;
	KeyBoard *keyBoard;
};
#endif // !_TEXTEDIT_H
