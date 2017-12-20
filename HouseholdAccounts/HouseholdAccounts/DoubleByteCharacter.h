#ifndef _DOUBLEBYTECHARACTER_H
#define _DOUBLEBYTECHARACTER_H

#include "Character.h"

class DoubleByteCharacter : public Character{
public:
	DoubleByteCharacter();
	DoubleByteCharacter(char *(characters));
	virtual ~DoubleByteCharacter();
	DoubleByteCharacter(const DoubleByteCharacter& source);


	virtual TextComponent* Clone() const;


	DoubleByteCharacter& operator= (const DoubleByteCharacter& source);
	char* GetCharacter() const;
private:
	char characters[2];
};

inline char* DoubleByteCharacter::GetCharacter()const {
	return const_cast<char*>(this->characters);
	//반환이 char* 뒤에 const라면 const_cast해줘야함
}
#endif // !_DOUBLEBYTECHARACTER_H

