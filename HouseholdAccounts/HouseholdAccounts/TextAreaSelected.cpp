#include "TextAreaSelected.h"
TextAreaSelected::TextAreaSelected(Long capacity) : TextComposite(capacity){
	this->length = 0;
	this->capacity = capacity;
}
TextAreaSelected::TextAreaSelected(const TextAreaSelected& source): TextComposite(source) {
	this->length = source.length;
	this->capacity = source.capacity;
}
TextAreaSelected::~TextAreaSelected() {
}
TextAreaSelected& TextAreaSelected::operator=(const TextAreaSelected& source) {
	this->textComponents = source.textComponents;
	this->length = source.length;
	this->capacity = source.capacity;
	return *this;
}
Long TextAreaSelected::Add(TextComponent *textComponent) {
	Long position = TextComposite::Add(textComponent);
	return position;
}
Long TextAreaSelected::Remove(TextComponent *textComponent) {
	Long position = TextComposite::Remove(textComponent);
	return position;
}
Long TextAreaSelected::Remove(Long index) {
	Long position = TextComposite::Remove(index);
	return position;
}
Long TextAreaSelected::Modify(Long index, TextComponent *textComponent) {
	Long position = TextComposite::Modify(index, textComponent);
	return position;
}
Long TextAreaSelected::Insert(Long index, TextComponent *textComponent) {
	Long position = TextComposite::Insert(index, textComponent);
	return position;
}
/*
Long TextAreaSelected::Add(TextComponent *textComponent) {
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
*/
TextComponent* TextAreaSelected::GetAt(Long index) {
	return this->textComponents.GetAt(index);
}
TextComponent* TextAreaSelected::operator[](Long index) {
	return this->textComponents[index];
}
/*
#include <iostream>
#include "SingleByteCharacter.h"
#include "DoubleByteCharacter.h"
using namespace std;
int main(int argc, char *argv[]) {
	TextAreaSelected textAreaSelected;
	SingleByteCharacter *singleByteCharacter = new SingleByteCharacter('H');
	DoubleByteCharacter *doubleByteCharacter = new DoubleByteCharacter("วั");
	textAreaSelected.Add(singleByteCharacter);
	textAreaSelected.Add(doubleByteCharacter);

	Long i = 0;
	Long length = textAreaSelected.GetLength();
	Long capacity = textAreaSelected.GetCapacity();
	Long ret;
	char temp;
	char *temps;
	while (i < length) {
		Character *character = static_cast<Character*>(textAreaSelected.GetAt(i));
		ret = character->CheckingSingleAndDouble();
		if (ret == 0) {
			temp = static_cast<SingleByteCharacter*>(character)->GetCharacter();
			cout << temp << endl;
		}
		else {
			temps = static_cast<DoubleByteCharacter*>(character)->GetCharacter();
			temps[2] = '\0';
			cout << temps << endl;
		}
		i++;
	}
	cout << length << "    " << capacity << endl;
	return 0;
}
*/