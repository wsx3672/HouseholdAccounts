#include "TextEdit.h"
#include "HouseholdAccountsForm.h"
#include "Text.h"
#include "Row.h"
#include "SingleByteCharacter.h"
#include "TextComposite.h"
#include "KeyBoard.h"
#include "WritingKorean.h"
#include "DoubleByteCharacter.h"
#include "KeyAction.h"
#include "Caret.h"
#include <cstring>
using namespace std;
BEGIN_MESSAGE_MAP(TextEdit, CWnd)
	ON_WM_CREATE()
	ON_WM_PAINT()
	ON_MESSAGE(WM_IME_COMPOSITION, OnComposition)
	ON_WM_KEYDOWN()
	ON_WM_CLOSE()
	ON_WM_CHAR()
END_MESSAGE_MAP()

TextEdit::TextEdit(HouseholdAccountsForm *householdAccountsForm) {
	this->householdAccountsForm = householdAccountsForm;
	this->keyBoard = NULL;
	this->text = NULL;
	this->caret = NULL;
	this->keyDownCheck = -1;
	this->WritingKoreanState = false;
}
void TextEdit::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) {
	this->keyDownCheck = -1;
	KeyAction *keyAction = this->keyBoard->Action(this, nChar, nRepCnt, nFlags);
	if (keyAction != NULL) {
		this->keyDownCheck = 1;
		keyAction->Action(this);
	}
}
void TextEdit::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags) {
	char nChar1 = nChar;
	if (this->keyDownCheck < 0 && this->WritingKoreanState == false) {
		SingleByteCharacter *singleByteCharacter = new SingleByteCharacter(nChar1);
		Long currentRowIndex = this->caret->GetCurrentRowIndex();
		TextComponent *textComponent = this->text->GetAt(currentRowIndex - 1);
		TextComposite *textComposite = textComponent->GetComposite();
		Long rowLegnth = textComposite->GetLength();
		Long position;
		Long characterIndex = this->caret->GetCharacterIndex();
		if (rowLegnth == characterIndex) {
			position = textComponent->Add(singleByteCharacter);
			this->caret->SetCharacterIndex(position);
		}
		else {
		    position = textComponent->Insert(characterIndex , singleByteCharacter);
			this->caret->SetCharacterIndex(position +1);
		}
		this->caret->CreateCaret();
		this->caret->RightMovingCaret();
	}
	this->Invalidate();
}
Long TextEdit::OnComposition(WPARAM wParam, LPARAM lParam) {
	HIMC hIMC = ImmGetContext(GetSafeHwnd());

	WritingKorean *writingKorean = new WritingKorean();
	writingKorean->WritingHanguel(wParam, lParam, hIMC, this);

	if (writingKorean != NULL) {
		delete writingKorean;
	}
	ImmReleaseContext(GetSafeHwnd(), hIMC);
	this->Invalidate();
	return 0;
}
void TextEdit::OnPaint() {
	CPaintDC dc(this);
	CRect rect;
	this->GetClientRect(rect);
	dc.FillSolidRect(rect, RGB(255, 255, 255));
	CFont font;
	font.CreateFont(17, 0, 0, 0, FW_NORMAL, FALSE, FALSE, 0, DEFAULT_CHARSET,
		OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_SWISS, "°íµñÃ¼");
	SetFont(&font, TRUE);
	dc.SelectObject(font);
	Long i = 0;
	Long length = this->text->GetLength();
	while (i < length) {
		TextComponent *textComponent = this->text->GetAt(i);
		TextComposite *textComposite = textComponent->GetComposite();
		CString cString = textComposite->MakeCString();
		dc.TextOut(0  ,i *17 ,cString);
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
	this->caret = new Caret(this);
	this->caret->CreateCaret();
	return 0;
}
void TextEdit::OnClose() {
	if (this->text != NULL) {
		delete this->text;
	}
	if (this->keyBoard != NULL) {
		delete this->keyBoard;
	}
	if (this->caret != NULL) {
		delete this->caret;
	}
	CWnd::OnClose();
}
