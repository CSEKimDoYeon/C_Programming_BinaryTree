#include "BinaryNode.h"

BinaryNode* BinaryNode_new(void) {
	BinaryNode* _this = NewObject(BinaryNode);
	_this->_key = NULL;
	_this->_object = NULL;
	_this->_left = NULL;
	_this->_right = NULL;
	return  _this; // �Ϲ� �����ڴ� ��� ���Ҹ� NULL ó���Ѵ�.
}// �⺻ ������


BinaryNode* BinaryNode_newWith(Key* aKey, Object* anObject, BinaryNode* aLeft, BinaryNode* aRight) {
	BinaryNode* _this = NewObject(BinaryNode);
	_this->_key = aKey;
	_this->_object = anObject;
	_this->_left = aLeft;
	_this->_right = aRight;
	return  _this;
}
// �Ӽ� ���� �־����� ������


void BinaryNode_delete(BinaryNode* _this) {
	free(_this); // ������带 �����Ѵ�.
}


void BinaryNode_setKey(BinaryNode* _this, Key* aKey) {
	_this->_key = aKey; // ��������� Ű�� �����Ѵ�.
}


Key* BinaryNode_key(BinaryNode* _this) {
	return _this->_key; // ��������� Ű�� �ݳ��Ѵ�.
}


void BinaryNode_setObject(BinaryNode* _this, Object* anObject) {
	_this->_object = anObject; // ��������� ������Ʈ�� �����Ѵ�.
}

Object* BinaryNode_object(BinaryNode* _this) {
	return _this->_object; // ��������� ������Ʈ�� �ݳ��Ѵ�.
}


void BinaryNode_setLeft(BinaryNode* _this, BinaryNode* aLeft) {
	_this->_left = aLeft; // ��������� ������ ��带 �����Ѵ�.
}

BinaryNode* BinaryNode_left(BinaryNode* _this) {
	return _this->_left; // �̺����� ���� ��带 ��ȯ�Ѵ�.
}

void BinaryNode_setRight(BinaryNode* _this, BinaryNode* aRight) {
	_this->_right = aRight; // ��������� ������ ��带 �����Ѵ�.
}

BinaryNode* BinaryNode_right(BinaryNode* _this) {
	return _this->_right; // ��������� ������ ��带 ��ȯ�Ѵ�.
}