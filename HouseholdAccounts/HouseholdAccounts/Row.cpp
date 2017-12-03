#include "Row.h"

Row::Row(Long capacity) : characters(capacity){
	this->capacity = capacity;
	this->length = 0;
}
Row::~Row() {
	Long i = 0;
	while (i < this->length) {
		if (this->characters.GetAt(i) != 0) {
			this->characters.Delete(i);
		}
		i++;
	}
}
Row::Row(const Row& source) : characters(source.characters) {
	this->capacity = source.capacity;
	this->length = source.length;
}
Row& Row::operator=(const Row& source) {
	this->characters = source.characters;
	return *this;
}
Long Row::Add(Character *character) {
	if (this->length < this->capacity) {
		this->characters.Store(this->length, character);
	}
	else {
		this->characters.AppendFromRear(character);
		this->capacity++;
	}
	this->length++;
	return this->length;
}
Character* Row::GetAt(Long index) {
	return this->characters.GetAt(index);
}
Character* Row::operator[] (Long index) {
	return this->characters[index];
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