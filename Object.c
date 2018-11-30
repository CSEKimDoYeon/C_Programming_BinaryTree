#include "Object.h"

// ObjectValue�� ���� �ڷ����� ���뿡 ���� �޶��� ���̴�.
Object* Object_new(void) {
	Object* _this = NewObject(Object);
	_this->_value = NULL;
	return  _this;
}// �⺻ ������

Object* Object_newWith(ObjectValue aValue) {
	Object* _this = NewObject(Object);
	_this->_value = aValue;
	return  _this;
}
// Object ���� �־����� ������


void Object_delete(Object* _this) {
	free(_this);
}

void Object_setValue(Object* _this, ObjectValue newValue) {
	_this->_value = newValue;
}

ObjectValue Object_value(Object* _this) {
	return _this->_value;
}