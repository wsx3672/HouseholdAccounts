#ifndef _KOREANENGLISHCHANGEKEY_H
#define _KOREANENGLISHCHANGEKEY_H

#include "KeyAction.h"
class TextEdit;
class KoreanEnglishChangeKey : public KeyAction {
public:
	KoreanEnglishChangeKey();
	virtual ~KoreanEnglishChangeKey();
	KoreanEnglishChangeKey(const KoreanEnglishChangeKey& source);

	KoreanEnglishChangeKey& operator= (const KoreanEnglishChangeKey& source);
	virtual void Action(TextEdit *textEdit);
};
#endif // !_KOREANENGLISHCHANGEKEY_H
