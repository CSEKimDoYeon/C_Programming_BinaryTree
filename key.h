#pragma once
#include "Common.h"

typedef struct _Key Key;
//typedef int KeyValue;
typedef char KeyValue;


struct _Key {
	KeyValue _value;
};
// KeyValue�� ���� �ڷ����� ���뿡 ���� �޶��� ���̴�.
Key* Key_new(void); // �⺻ ������
Key* Key_newWith(KeyValue aValue); // Ű ���� �־����� ������
void Key_delete(Key* _this);
void Key_setValue(Key* _this, KeyValue newValue);
KeyValue Key_value(Key* _this);
int Key_compareTo(Key* _this, Key* aKey);
// _this ��ü�� Ű ���� aKey ��ü�� Ű ���� ���Ѵ�.
// _this ��ü�� Ű ���� �� ������ -1, ������ 0, �� ũ�� +1�� ��´�.