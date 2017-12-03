#ifndef _SINGLEBYTECHARACTER_H
#define _SINGLEBYTECHARACTER_H

#include "Character.h"

class SingleByteCharacter : public Character {
public:
	SingleByteCharacter();
	SingleByteCharacter(char character);
	virtual ~SingleByteCharacter();
	SingleByteCharacter(const SingleByteCharacter& source);

	SingleByteCharacter& operator= (const SingleByteCharacter& source);
	char GetCharacter() const;
private:
	char character;
};
inline char SingleByteCharacter::GetCharacter() const {
	return this->character;
}
#endif // !_SINGLEBYTECHARACTER_H
