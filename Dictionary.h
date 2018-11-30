#pragma once
#include "Common.h"
#include "BinaryNode.h"
#include "Object.h"
#include "key.h"
#include "Traverse.h"

typedef struct  _Dictionary  Dictionary;

struct  _Dictionary {
	BinaryNode* _root;
	int _size;
};

Dictionary* Dictionary_new(void);
void Dictionary_delete(Dictionary* _this);
void Dictionary_deleteBinaryNodes(Dictionary* _this, BinaryNode * aNode);
Boolean Dictionary_isEmpty(Dictionary* _this);
Boolean Dictionary_isFull(Dictionary* _this);
int Dictionary_size(Dictionary* _this);
Boolean Dictionary_keyDoesExist(Dictionary* _this, Key* aKey);
Object* Dictionary_objectForKey(Dictionary* _this, Key* aKey);
Object* Dictionary_searchTreeRecursively(Dictionary* _this, Key* aKey, BinaryNode* aNode);
Boolean Dictionary_addKeyAndObject(Dictionary* _this, Key* aKey, Object* anObject);
Boolean Dictionary_addToTree(Dictionary* _this, Key* aKey, Object* anObject, BinaryNode* parent);
Object* Dictionary_removeObjectForKey(Dictionary* _this, Key* aKey);
void Dictionary_scanInSortedOrder(Dictionary* _this, Traverse* aTraverse);
void Dictionary_inorder(Dictionary* _this, Traverse* aTraverse, BinaryNode* aRoot, int aDepth);
Boolean Dictionary_replaceObjectForKey(Dictionary* _this, Key* aKey, Object* anObject);
Object* Dictionary_removeFromTreeRecursively(Dictionary* _this, Key* aKey, BinaryNode* parent);
Object* Dictionary_removeRightmostNodeOfLeftSubtree(Dictionary* _this, BinaryNode* rootOfLeftSubtree);
Object* Dictionary_removeLeftmostNodeOfRightSubtree(Dictionary* _this, BinaryNode* rootOfRightSubtree);
