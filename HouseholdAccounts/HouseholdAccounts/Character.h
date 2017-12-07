#ifndef _CHARACTER_H
#define _CHARACTER_H
#include "TextComponent.h"

class Character : public TextComponent {
public:

	Character();
	virtual ~Character() ;
	Character(const Character& source);
	Long CheckingSingleAndDouble();
};
#endif // !_CHARACTER_H
