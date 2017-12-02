#ifndef _TEXTEDIT_H
#define _TEXTEDIT_H

#include <afxwin.h>
class HouseholdAccountsForm;
class TextEdit : public CWnd {
public:
	TextEdit(HouseholdAccountsForm *householdAccountsForm);
public:
	afx_msg void OnClose();
protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnPaint();
	afx_msg void OnKeyDown(UINT nChar,UINT nRepCnt,UINT nFlags);
	DECLARE_MESSAGE_MAP()
public:
	HouseholdAccountsForm *householdAccountsForm;
};
#endif // !_TEXTEDIT_H
