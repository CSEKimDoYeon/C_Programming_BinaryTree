#pragma once
#include "Common.h"

typedef struct _Object Object;
typedef int ObjectValue;

struct _Object {
	ObjectValue _value;
};
// ObjectValue�� ���� �ڷ����� ���뿡 ���� �޶��� ���̴�.
Object* Object_new(void); // �⺻ ������
Object* Object_newWith(ObjectValue aValue);
// Object ���� �־����� ������
void Object_delete(Object* _this);
void Object_setValue(Object* _this, ObjectValue newValue);
ObjectValue Object_value(Object* _this);