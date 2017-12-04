#include "TextEdit.h"
#include "HouseholdAccountsForm.h"
#include "Text.h"
#include "Row.h"
#include "SingleByteCharacter.h"
#include "TextComposite.h"
BEGIN_MESSAGE_MAP(TextEdit, CWnd)
	ON_WM_CREATE()
	ON_WM_PAINT()
	ON_WM_KEYDOWN()
	ON_WM_CLOSE()
	ON_WM_CHAR()
END_MESSAGE_MAP()

TextEdit::TextEdit(HouseholdAccountsForm *householdAccountsForm) {
	this->householdAccountsForm = householdAccountsForm;
	this->text = NULL;
}
void TextEdit::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) {
	
}
void TextEdit::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags) {
	char nChar1 = nChar;

	if (nChar != VK_RETURN) {
		TextComponent *textComponent = this->text->GetAt(0);
		SingleByteCharacter *singleByteCharacter = new SingleByteCharacter(nChar1);
		textComponent->Add(static_cast<Character*>(singleByteCharacter));
	}
	this->Invalidate();
}
void TextEdit::OnPaint() {
	CPaintDC dc(this);
	CFont font;
	font.CreateFont(17, 0, 0, 0, FW_NORMAL, FALSE, FALSE, 0, DEFAULT_CHARSET,
		OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_SWISS, "±Ã¼­Ã¼");
	SetFont(&font, TRUE);
	dc.SelectObject(font);
	Long i = 0;
	Long length = this->text->GetLength();
	while (i < length) {
		TextComponent *textComponent = this->text->GetAt(0);
		TextComposite *textComposite = textComponent->GetComposite();
		Long textCompositeLength = textComposite->GetLength();
		Long j = 0;
		while (j < textCompositeLength) {
			TextComponent *textComponent = textComposite->GetAt(j);
			char temp = static_cast<SingleByteCharacter*>(textComponent)->GetCharacter();
			CString test = temp;
			dc.TextOut(10 + j * 9, 10, test);
			j++;
		}
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
	return 0;
}
void TextEdit::OnClose() {
	CWnd::OnClose();
}
