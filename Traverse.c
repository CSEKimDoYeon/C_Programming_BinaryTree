#include "Traverse.h"

Traverse* Traverse_new(void) {
	Traverse* _this = NewObject(Traverse);
	_this->a = NULL;
	return  _this;
} // 持失切

void Traverse_delete(Traverse* _this) {
	free(_this);
} // 社瑚切


void Traverse_visit(Traverse* _this, Key* aKey, Object* anObject, int aDepth)
{
	for (int i = 0; i < aDepth; i++) {
		printf(" ");
	}
		printf("%c\n", Key_value(aKey));
	
}