#ifndef _WRITINGKOREAN_H
#define _WRITINGKOREAN_H

typedef signed long int Long;
#pragma comment(lib,"imm32")
#include <afxwin.h>
class TextEdit;
class WritingKorean {
public:
	WritingKorean();
	~WritingKorean();
	WritingKorean(const WritingKorean& source);
	WritingKorean& operator=(const WritingKorean& source);
	void WritingHanguel(WPARAM wParam, LPARAM lParam, HIMC hIMC, TextEdit *textEdit);
};
#endif // !_WRITINGKOREAN_H
