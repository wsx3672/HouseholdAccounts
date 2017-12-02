#include "HouseholdAccountsForm.h"
#include "TextEdit.h"
BEGIN_MESSAGE_MAP(HouseholdAccountsForm, CFrameWnd)
	ON_WM_CREATE()
	ON_WM_LBUTTONDBLCLK()
	ON_WM_PAINT()
	ON_WM_CHAR()
	ON_WM_CLOSE()
END_MESSAGE_MAP()
HouseholdAccountsForm::HouseholdAccountsForm() {
	this->textEdit = NULL;
}
int HouseholdAccountsForm::OnCreate(LPCREATESTRUCT lpCreateStruct) {
	CFrameWnd::OnCreate(lpCreateStruct);
	
	return 0;
}
void HouseholdAccountsForm::OnLButtonDblClk(UINT, CPoint) {
	this->textEdit = new TextEdit(this);
	this->textEdit->Create(NULL, "TextEdit", WS_CHILD | WS_VISIBLE, CRect(10, 20, 30, 40), this, NULL);
}
void HouseholdAccountsForm::OnPaint() {
	CPaintDC cPaintDC(this);
}
void HouseholdAccountsForm::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags) {

}
void HouseholdAccountsForm::OnClose() {
	CFrameWnd::OnClose();
}