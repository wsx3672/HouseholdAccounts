#include "TextEdit.h"
#include "HouseholdAccountsForm.h"


BEGIN_MESSAGE_MAP(TextEdit, CWnd)
	ON_WM_CREATE()
	ON_WM_PAINT()
	ON_WM_KEYDOWN()
	ON_WM_CLOSE()
END_MESSAGE_MAP()

TextEdit::TextEdit(HouseholdAccountsForm *householdAccountsForm) {
	this->householdAccountsForm = householdAccountsForm;
}
void TextEdit::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) {
	this->Invalidate();
}
void TextEdit::OnPaint() {
	CPaintDC dc(this);
	CWnd::OnPaint();
}
int TextEdit::OnCreate(LPCREATESTRUCT lpCreateStruct) {
	CWnd::OnCreate(lpCreateStruct);
	CWnd::SetFocus();
	return 0;
}
void TextEdit::OnClose() {
	CWnd::OnClose();
}
