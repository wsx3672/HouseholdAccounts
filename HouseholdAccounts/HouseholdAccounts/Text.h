#ifndef _TEXT_H
#define _TEXT_H

typedef signed long int Long;
#include "Array.h"
#include "Row.h"
#include "TextComposite.h"
class Text : public TextComposite{
public:
	Text(Long capacity = 10000);
	~Text();
	Text(const Text& source);
	Text& operator= (const Text& source);

	Long Add(Row *row);
	TextComponent* GetAt(Long index);
	TextComponent* operator[](Long index);
	Long GetCapacity();
	Long GetLength();
};
inline Long Text::GetCapacity() {
	return this->capacity;
}
inline Long Text::GetLength() {
	return this->length;
}
#endif // !_TEXT_H
