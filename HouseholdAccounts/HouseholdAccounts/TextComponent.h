#ifndef _TEXTCOMPONENT_H
#define _TEXTCOMPONENT_H
typedef signed long int Long;

class TextComposite;
class TextComponent {
protected:
	TextComponent();
public:
	virtual ~TextComponent();
	TextComponent(const TextComponent& source);
	TextComponent& operator= (const TextComponent& source);

	virtual Long Add(TextComponent *textComponent);
	virtual Long Remove(TextComponent *textComponent);
	virtual TextComposite* GetComposite();

};
#endif // !_TEXTCOMPONENT_H
