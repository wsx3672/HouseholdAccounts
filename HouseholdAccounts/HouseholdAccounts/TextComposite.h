#ifndef _TEXTCOMPOSITE_H
#define _TEXTCOMPOSITE_H
typedef signed long int Long;

#include "TextComponent.h"
#include "Array.h"


class TextComposite : public TextComponent {
public:
	virtual ~TextComposite();
	TextComposite(const TextComposite& source);
	TextComposite& operator=(const TextComposite& source);

	virtual TextComposite* GetComposite();
	virtual Long Add(TextComponent *textComponent);
	virtual Long Remove(TextComponent *textComponent);

	Long GetCapacity();
	Long GetLength();
	TextComponent* GetAt(Long index);
	TextComponent* operator[](Long ingex);
	TextComposite(Long capacity = 10000 );
protected:
	Array<TextComponent*> textComponents;
	Long capacity;
	Long length;
};
inline Long TextComposite::GetCapacity() {
	return this->capacity;
}
inline Long TextComposite::GetLength() {
	return this->length;
}
#endif // !_TEXTCOMPOSITE_H
