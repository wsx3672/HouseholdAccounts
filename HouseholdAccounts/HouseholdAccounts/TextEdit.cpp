#include "TextEdit.h"
#include "HouseholdAccountsForm.h"
#include "Row.h"
#include "SingleByteCharacter.h"

BEGIN_MESSAGE_MAP(TextEdit, CWnd)
	ON_WM_CREATE()
	ON_WM_PAINT()
	ON_WM_KEYDOWN()
	ON_WM_CLOSE()
	ON_WM_CHAR()
END_MESSAGE_MAP()

TextEdit::TextEdit(HouseholdAccountsForm *householdAccountsForm) {
	this->householdAccountsForm = householdAccountsForm;
	this->row = NULL;
}
void TextEdit::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) {
	
}
void TextEdit::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags) {
	char nChar1 = nChar;

	SingleByteCharacter singleByteCharacter(nChar1);
	this->row->Add(static_cast<Character*>(&singleByteCharacter));

	this->Invalidate();
}
void TextEdit::OnPaint() {
	CPaintDC dc(this);
	CFont font;
	font.CreatePointFont(80,_T("±Ã¼­Ã¼"));
	dc.SelectObject(font);
	Long i = 0;
	Long length = this->row->GetLength();
	while (i < length) {
		Character *character = this->row->GetAt(i);
		char test = static_cast<SingleByteCharacter*>(character)->GetCharacter();
		dc.TextOut(10 + i * 3, 10, test);
		i++;
	}
	CWnd::OnPaint();
}
int TextEdit::OnCreate(LPCREATESTRUCT lpCreateStruct) {
	CWnd::OnCreate(lpCreateStruct);
	CWnd::SetFocus();

	this->row = new Row();
	return 0;
}
void TextEdit::OnClose() {
	CWnd::OnClose();
}
