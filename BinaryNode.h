#pragma once
#include "key.h"
#include "Object.h"

typedef struct  _BinaryNode  BinaryNode;

struct  _BinaryNode {
	Key* _key;
	Object* _object;
	BinaryNode* _left;
	BinaryNode* _right;
};

BinaryNode* BinaryNode_new(void); // 기본 생성자
BinaryNode* BinaryNode_newWith(Key* aKey, Object* anObject, BinaryNode* aLeft, BinaryNode* aRight);
// 속성 값이 주어지는 생성자
void BinaryNode_delete(BinaryNode* _this);
void BinaryNode_setKey(BinaryNode* _this, Key* aKey);
Key* BinaryNode_key(BinaryNode* _this);
void BinaryNode_setObject(BinaryNode* _this, Object* anObject);
Object* BinaryNode_object(BinaryNode* _this);
void BinaryNode_setLeft(BinaryNode* _this, BinaryNode* aLeft);
BinaryNode* BinaryNode_left(BinaryNode* _this);
void BinaryNode_setLeft(BinaryNode* _this, BinaryNode* aRight);
BinaryNode* BinaryNode_right(BinaryNode* _this);
