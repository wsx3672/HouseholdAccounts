#ifndef _ROW_H
#define _ROW_H

typedef signed long int Long;

#include "Array.h"
class Character;
class Row {
public:
	Row(Long capacity = 1028);
	~Row();
	Row(const Row& source);

	Row& operator= (const Row& source);
	Long Add(Character *character);
	Character* GetAt(Long index);
	Character* operator [] (Long index);
	Long GetCapacity()const;
	Long GetLength()const;
private:
	Array<Character*> characters;
	Long capacity;
	Long length;
};
inline Long Row::GetCapacity()const {
	return this->capacity;
}
inline Long Row::GetLength()const {
	return this->length;
}
#endif // !_ROW_H
