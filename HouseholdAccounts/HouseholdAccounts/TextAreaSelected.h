#ifndef _TEXTAREASELECTED_H
#define _TEXTAREASELECTED_H
typedef signed long int Long;

#include "Array.h"
#include "TextComposite.h"

class TextAreaSelected : TextComposite{
public:
	TextAreaSelected(Long capacity = 50000);
	TextAreaSelected(const TextAreaSelected& source);
	~TextAreaSelected();

	TextAreaSelected& operator= (const TextAreaSelected& source);
	TextComponent* operator[](Long index);

	virtual Long Add(TextComponent *textComponent);
	virtual Long Remove(TextComponent *textComponent);
	virtual Long Remove(Long index);
	virtual Long Modify(Long index, TextComponent *textComponent);
	virtual Long Insert(Long index, TextComponent *textComponent);

	//Long Add(TextComponent *textComponent);
	
	TextComponent* GetAt(Long index);
public:
	Long GetCapacity() const;
	Long GetLength() const;

};

inline Long TextAreaSelected::GetCapacity() const {
	return this->capacity;
}
inline Long TextAreaSelected::GetLength() const {
	return this->length;
}
#endif // !_TEXTAREASELECTED_H
