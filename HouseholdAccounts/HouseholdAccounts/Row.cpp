#include "Row.h"

Row::Row(Long capacity) : TextComposite(capacity){
	this->capacity = capacity;
	this->length = 0;
}
Row::~Row() {
}
Row::Row(const Row& source) : TextComposite(source) {
	this->textComponents = source.textComponents;
	this->capacity = source.capacity;
	this->length = source.length;
}
Row& Row::operator=(const Row& source) {
	this->textComponents = source.textComponents;
	this->capacity = source.capacity;
	this->length = source.length;
	return *this;
}
Long Row::Add(TextComponent *textComponent) {
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
TextComponent* Row::GetAt(Long index) {
	return this->textComponents.GetAt(index);
}
TextComponent* Row::operator[] (Long index) {
	return this->textComponents[index];
}
/*
#include <iostream>
#include "SingleByteCharacter.h"
#include "DoubleByteCharacter.h"
using namespace std;
int main(int argc, char *argv[]) {
	Row row;
	//SingleByteCharacter *singleByteCharacter = new SingleByteCharacter('A');
	//DoubleByteCharacter *doubleByteCharacter = new DoubleByteCharacter("วั");

	SingleByteCharacter singleByteCharacter('A');
	DoubleByteCharacter doubleByteCharacter("วั");

	row.Add(static_cast<Character*>(&singleByteCharacter));
	row.Add(static_cast<Character*>(&doubleByteCharacter));

	Character *character = row[0];
	Character *character1 = row[1];

	char test = static_cast<SingleByteCharacter*>(character)->GetCharacter();
	char *test1 = static_cast<DoubleByteCharacter*>(character1)->GetCharacter();

	test1[2] = '\0';

	cout << test << test1 << endl;

	Long capacity = row.GetCapacity();
	Long length = row.GetLength();
	cout << capacity << "  " << length << endl;

	return 0;
}
*/