#include "key.h"

// KeyValue의 실제 자료형은 응용에 따라 달라질 것이다.
Key* Key_new(void) {
	Key* _this = NewObject(Key);
	_this->_value = NULL;
	return  _this;
}// 기본 생성자
Key* Key_newWith(KeyValue aValue) {
	Key* _this = NewObject(Key);
	_this->_value = aValue;
	return  _this;
}
// 키 값이 주어지는 생성자
void Key_delete(Key* _this) {
	free(_this);
}
void Key_setValue(Key* _this, KeyValue newValue) {
	_this->_value = newValue;
}
KeyValue Key_value(Key* _this) {
	return _this->_value;
}
int Key_compareTo(Key* aKey, Key* _this) {
	if (_this->_value < aKey->_value)
		return -1;
	else if (_this->_value == aKey->_value)
		return 0;
	else
		return +1;
}
// _this 객체의 키 값과 aKey 객체의 키 값을 비교한다.
// _this 객체의 키 값이 더 작으면 -1, 같으면 0, 더 크면 +1을 얻는다.