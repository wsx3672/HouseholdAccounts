//MouseDragMovingCaret.h

/*
���ϸ� : MouseDragMovingCaret.h
��� : ���콺�巡�׽� ĳ���̵��� �����ϴ� Ŭ����
�ۼ��� : �ڻ��
�ۼ����� : 2018�� 01�� 08��
*/
#ifndef _MOUSEDRAGMOVINGCARET_H
#define _MOUSEDRAGMOVINGCARET_H

typedef signed long int Long;
class TextEdit;
class TextComposite;

class MouseDragMovingCaret {
	MouseDragMovingCaret();
	~MouseDragMovingCaret();
	MouseDragMovingCaret(const MouseDragMovingCaret& souce);

	void LeftMovingCaret(TextEdit *textEdit , TextComposite *currentTextComposite);
	void RightMovingCaret(TextEdit *textEdit, TextComposite *currentTextComposite);
	
};
#endif // !_MOUSEDRAGMOVINGCARET_H
