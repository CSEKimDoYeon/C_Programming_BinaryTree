#include "BinaryNode.h"

BinaryNode* BinaryNode_new(void) {
	BinaryNode* _this = NewObject(BinaryNode);
	_this->_key = NULL;
	_this->_object = NULL;
	_this->_left = NULL;
	_this->_right = NULL;
	return  _this; // 일반 생성자는 모든 원소를 NULL 처리한다.
}// 기본 생성자


BinaryNode* BinaryNode_newWith(Key* aKey, Object* anObject, BinaryNode* aLeft, BinaryNode* aRight) {
	BinaryNode* _this = NewObject(BinaryNode);
	_this->_key = aKey;
	_this->_object = anObject;
	_this->_left = aLeft;
	_this->_right = aRight;
	return  _this;
}
// 속성 값이 주어지는 생성자


void BinaryNode_delete(BinaryNode* _this) {
	free(_this); // 이진노드를 삭제한다.
}


void BinaryNode_setKey(BinaryNode* _this, Key* aKey) {
	_this->_key = aKey; // 이진노드의 키를 세팅한다.
}


Key* BinaryNode_key(BinaryNode* _this) {
	return _this->_key; // 이진노드의 키를 반납한다.
}


void BinaryNode_setObject(BinaryNode* _this, Object* anObject) {
	_this->_object = anObject; // 이진노드의 오브젝트를 세팅한다.
}

Object* BinaryNode_object(BinaryNode* _this) {
	return _this->_object; // 이진노드의 오브젝트를 반납한다.
}


void BinaryNode_setLeft(BinaryNode* _this, BinaryNode* aLeft) {
	_this->_left = aLeft; // 이진노드의 오른쪽 노드를 세팅한다.
}

BinaryNode* BinaryNode_left(BinaryNode* _this) {
	return _this->_left; // 이빈노드의 왼쪽 노드를 반환한다.
}

void BinaryNode_setRight(BinaryNode* _this, BinaryNode* aRight) {
	_this->_right = aRight; // 이진노드의 오른쪽 노드를 세팅한다.
}

BinaryNode* BinaryNode_right(BinaryNode* _this) {
	return _this->_right; // 이진노드의 오른쪽 노드를 반환한다.
}