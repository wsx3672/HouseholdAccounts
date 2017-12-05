#include "TextEdit.h"
#include "HouseholdAccountsForm.h"
#include "Text.h"
#include "Row.h"
#include "SingleByteCharacter.h"
#include "TextComposite.h"
#include "KeyBoard.h"
#include "KeyAction.h"
#include <cstring>
using namespace std;
BEGIN_MESSAGE_MAP(TextEdit, CWnd)
	ON_WM_CREATE()
	ON_WM_PAINT()
	ON_WM_KEYDOWN()
	ON_WM_CLOSE()
	ON_WM_CHAR()
END_MESSAGE_MAP()

TextEdit::TextEdit(HouseholdAccountsForm *householdAccountsForm) {
	this->householdAccountsForm = householdAccountsForm;
	this->keyBoard = NULL;
	this->text = NULL;
}
void TextEdit::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) {
	
}
void TextEdit::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags) {
	char nChar1 = nChar;
	Long check = -1;
	KeyAction *keyAction = this->keyBoard->Action(this, nChar, nRepCnt, nFlags);
	if (keyAction != NULL) {
		check = 1;
		keyAction->Action(this);
	}
	if (check < 0  ) {
		Long length = this->text->GetLength();
		TextComponent *textComponent = this->text->GetAt(length -1);
		SingleByteCharacter *singleByteCharacter = new SingleByteCharacter(nChar1);
		textComponent->Add(static_cast<Character*>(singleByteCharacter));
	}
	
	this->Invalidate();
}
void TextEdit::OnPaint() {
	CPaintDC dc(this);
	CRect rect;
	this->GetClientRect(rect);
	dc.FillSolidRect(rect, RGB(255, 255, 255));
	CFont font;
	font.CreateFont(17, 0, 0, 0, FW_NORMAL, FALSE, FALSE, 0, DEFAULT_CHARSET,
		OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_SWISS, "±Ã¼­Ã¼");
	SetFont(&font, TRUE);
	dc.SelectObject(font);
	Long i = 0;
	Long length = this->text->GetLength();
	while (i < length) {
		TextComponent *textComponent = this->text->GetAt(i);
		TextComposite *textComposite = textComponent->GetComposite();
		CString cString = textComposite->MakeCString();
		dc.TextOut(10  ,i *17 ,cString);
		i++;
	}
	CWnd::OnPaint();
}
int TextEdit::OnCreate(LPCREATESTRUCT lpCreateStruct) {
	CWnd::OnCreate(lpCreateStruct);
	CWnd::SetFocus();

	this->text = new Text();
	Row *row = new Row();
	this->text->Add(row);
	this->keyBoard = new KeyBoard();
	return 0;
}
void TextEdit::OnClose() {
	CWnd::OnClose();
}
