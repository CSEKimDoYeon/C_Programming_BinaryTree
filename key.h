#pragma once
#include "Common.h"

typedef struct _Key Key;
//typedef int KeyValue;
typedef char KeyValue;


struct _Key {
	KeyValue _value;
};
// KeyValue의 실제 자료형은 응용에 따라 달라질 것이다.
Key* Key_new(void); // 기본 생성자
Key* Key_newWith(KeyValue aValue); // 키 값이 주어지는 생성자
void Key_delete(Key* _this);
void Key_setValue(Key* _this, KeyValue newValue);
KeyValue Key_value(Key* _this);
int Key_compareTo(Key* _this, Key* aKey);
// _this 객체의 키 값과 aKey 객체의 키 값을 비교한다.
// _this 객체의 키 값이 더 작으면 -1, 같으면 0, 더 크면 +1을 얻는다.