#include "TextAreaSelectedProcess.h"
#include "TextEdit.h"
#include "TextComposite.h"
#include "Caret.h"
#include <afxwin.h>


TextAreaSelectedProcess::TextAreaSelectedProcess() {
}
TextAreaSelectedProcess::~TextAreaSelectedProcess() {
}
TextAreaSelectedProcess::TextAreaSelectedProcess(const TextAreaSelectedProcess& source) {
}
TextAreaSelectedProcess& TextAreaSelectedProcess::operator=(const TextAreaSelectedProcess& source) {
	return *this;
}
void TextAreaSelectedProcess::AllRowAreaSelected(TextEdit *textEdit, CDC *pDC, TextComposite *textComposite , Long index) {
	CString cString = textComposite->MakeCString();
	CSize size = pDC->GetTextExtent(cString);
	CRect rect(0, index * 17, size.cx, size.cx + (index * 17) + size.cy);
	pDC->DrawText(cString, &rect, DT_EXPANDTABS);
}
void TextAreaSelectedProcess::PartRowAreaSelected(TextEdit *textEdit, CDC *pDC, TextComposite *textComposite, Long index, Long length , Long rowIndex) {
	CString cString = textComposite->MakeCString(index,length);
	CSize size = pDC->GetTextExtent(cString);
	CString indexCString = textComposite->MakeCString(index);
	CSize indexSize = pDC->GetTextExtent(indexCString);
	CRect rect(indexSize.cx, (rowIndex-1) * 17,textEdit->caret->GetCurrentX(), size.cx + (rowIndex -1)* 17 + size.cy);
	pDC->DrawText(cString, &rect, DT_EXPANDTABS);
}