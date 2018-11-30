#include "Object.h"

// ObjectValue의 실제 자료형은 응용에 따라 달라질 것이다.
Object* Object_new(void) {
	Object* _this = NewObject(Object);
	_this->_value = NULL;
	return  _this;
}// 기본 생성자

Object* Object_newWith(ObjectValue aValue) {
	Object* _this = NewObject(Object);
	_this->_value = aValue;
	return  _this;
}
// Object 값이 주어지는 생성자


void Object_delete(Object* _this) {
	free(_this);
}

void Object_setValue(Object* _this, ObjectValue newValue) {
	_this->_value = newValue;
}

ObjectValue Object_value(Object* _this) {
	return _this->_value;
}