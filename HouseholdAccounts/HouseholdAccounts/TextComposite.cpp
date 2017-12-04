#include "TextComposite.h"

TextComposite::TextComposite(Long capacity) : textComponents(capacity) {
	this->capacity = capacity;
	this->length = 0;
}
TextComposite::~TextComposite() {
}
TextComposite::TextComposite(const TextComposite& source) : textComponents(source.textComponents) {
	this->capacity = source.capacity;
	this->length = source.length; 
}
TextComposite& TextComposite::operator= (const TextComposite& source) {
	this->textComponents = source.textComponents;
	this->capacity = source.capacity;
	this->length = source.length;
	return *this;
}
TextComposite* TextComposite::GetComposite() {
	return this;
}
Long TextComposite::Add(TextComponent *textComponent) {
	if (this->length < this->capacity) {
		this->textComponents.Store(this->length, textComponent);
	}
	else {
		this->textComponents.AppendFromRear(textComponent);
		this->capacity++;
	}
	this->length++;
	return this->length;
}
TextComponent* TextComposite::GetAt(Long index) {
	return this->textComponents.GetAt(index);
}
TextComponent* TextComposite::operator[](Long index) {
	return this->textComponents[index];
}
Long TextComposite::Remove(TextComponent *textComponent) {
	Long i = 0;
	Long index = 0;
	while (i < this->length && this->textComponents.GetAt(i) != textComponent) {
		i++;
	}
	if (i < this->length) {
		this->textComponents.Delete(i);
		this->capacity--;
		this->length--;
		index = -1;
	}
	return index;
}
/*
#include <iostream>
#include "SingleByteCharacter.h"
using namespace std;

int main(int agrc, char *argv[]) {
	TextComposite textComposite;
	SingleByteCharacter singleByteCharacter('A');
	TextComposite *test = textComposite.GetComposite();

	textComposite.Add(&singleByteCharacter);
	if (test == 0) {
		cout << "¸»´Ü °´Ã¼ÀÓ " << endl;
	}
	else {
		cout << "º¹ÇÕ °´Ã¼ÀÓ " << endl;
	}
	TextComposite composite(textComposite);
	
	Long compositeLength = composite.GetLength();
	Long compositeCapacity = composite.GetCapacity();

	Long i = 0;
	while (i < compositeLength) {
		TextComponent *component = composite.GetAt(i);
		char test = static_cast<SingleByteCharacter*>(component)->GetCharacter();
		cout << endl << test << endl;
		i++;
	}
	textComposite.Remove(&singleByteCharacter);
	Long length = textComposite.GetLength();
	Long capacity = textComposite.GetCapacity();
	
	cout << capacity << "    " << length << endl;
	return 0;
}
*/