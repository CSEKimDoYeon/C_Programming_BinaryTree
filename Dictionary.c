#include "Dictionary.h"
#include "AppController.h"
#include "Traverse.h"
#include "BinaryNode.h"
#include "AppIO.h"

Dictionary* Dictionary_new(void) {
	Dictionary* _this = NewObject(Dictionary);
	_this->_root = NULL;
	_this->_size = 0;
	return  _this;
} // 기본 생성자

void Dictionary_delete(Dictionary* _this) {
	Dictionary_deleteBinaryNodes(_this, _this->_root);
	free(_this);
} // 사전 객체를 삭제한다, deleteBinaryNode를 실행하여 순차적으로 지운다.

void Dictionary_deleteBinaryNodes(Dictionary* _this, BinaryNode * aNode)
{
	if (aNode != NULL) {
		Dictionary_deleteBinaryNodes(_this, BinaryNode_left(aNode));
		Dictionary_deleteBinaryNodes(_this, BinaryNode_right(aNode));
		BinaryNode_delete(aNode);
	}
	// 왼쪽 노드와 오른쪽 노드 삭제를 재귀적으로 삭제한다.
}

Boolean Dictionary_isEmpty(Dictionary* _this) {
	return (_this->_root == NULL);
	// root가 null 일 경우를 체크한다.
}

Boolean Dictionary_isFull(Dictionary* _this) {
	return (FALSE);
	// 사전은 항상 꽉 차있으므로 항상 false를 반환한다.
}

int Dictionary_size(Dictionary* _this) {
	return (_this->_size);
	// 사전의 사이즈를 반환한다.
}

Boolean Dictionary_keyDoesExist(Dictionary* _this, Key* aKey) {
	return (Dictionary_searchTreeRecursively(_this, aKey, _this->_root) != NULL);
} // 해당 파라미터의 키값을 재귀적으로 검색한다.

Object* Dictionary_objectForKey(Dictionary* _this, Key* aKey) {
	return (Dictionary_searchTreeRecursively(_this, aKey, _this->_root));
} // 해당 키값으로 오브젝트를 반환한다.

Object* Dictionary_searchTreeRecursively(Dictionary* _this, Key* aKey, BinaryNode* aNode)
{ // 해딩 키값으로 검색을 실행한다.
	if (aNode == NULL) {
		return NULL;
	}
	else {
		if (Key_compareTo(BinaryNode_key(aNode), aKey) == 0) {
			// 키값과 파라미터의 값이 같을 경우
			return (BinaryNode_object(aNode)); // 반환한다.
		}
		else if (Key_compareTo(BinaryNode_key(aNode), aKey) < 0) {
			// 파라미터가 더 작을 경우 왼쪽 노드를 검색한다.
			return (Dictionary_searchTreeRecursively(_this, aKey, BinaryNode_left(aNode)));
		}
		else {
			// 파라미터가 더 클 경우 오른쪽 노드를 검색한다.
			return (Dictionary_searchTreeRecursively(_this, aKey, BinaryNode_right(aNode)));
		}
	}
}

Boolean Dictionary_addKeyAndObject(Dictionary* _this, Key* aKey, Object* anObject) {
	if (_this->_root == NULL) {
		_this->_root = BinaryNode_newWith(aKey, anObject, NULL, NULL);
		_this->_size++;
		// 루트가 null일 경우 새로운 바이너리 트리를 생성한다.
		return (TRUE);
	}
	else {
		// 같은 노드를 찾으면 replace 메시지 띄운다.
		if (Dictionary_replaceObjectForKey(_this, aKey, anObject) == TRUE) { // 만약 같은 노드를 찾으면
			printf("[Replace] key <'%c'> 의 object를 <%d> 로 대체합니다.\n", Key_value(aKey), Object_value(anObject));
			return FALSE;
		}
		else {
			_this->_size++;
			return (Dictionary_addToTree(_this, aKey, anObject, _this->_root));
		}
	}
}

Boolean Dictionary_addToTree(Dictionary* _this, Key* aKey, Object* anObject, BinaryNode* parent)
{ // 사전에 새로운 바이너리 트리를 삽입한다.
	if (Key_compareTo(BinaryNode_key(parent), aKey) < 0) {
	// 파라미터가 더 작을 경우
		if (BinaryNode_left(parent) == NULL) {
			BinaryNode_setLeft(parent, BinaryNode_newWith(aKey, anObject, NULL, NULL));
			return TRUE; // 왼쪽 노드에 새로 추가한다.
		}
		else {
			return Dictionary_addToTree(_this, aKey, anObject, BinaryNode_left(parent));
		}
	}
	else if (Key_compareTo(BinaryNode_key(parent), aKey) > 0) {
		// 파라미터가 더 클 경우 오른쪽 노드에 새로 추가한다.
		if (BinaryNode_right(parent) == NULL) {
			BinaryNode_setRight(parent, BinaryNode_newWith(aKey, anObject, NULL, NULL));
			return TRUE;
		}
		else {
			return Dictionary_addToTree(_this, aKey, anObject, BinaryNode_right(parent));
		}
	}
	else {
		return (FALSE);
	}
}

Object* Dictionary_removeObjectForKey(Dictionary* _this, Key* aKey) {
	if (Dictionary_isEmpty(_this)) { // 키 값으로 오브젝트를 삭제한다.
		return (NULL);
	}
	else {
		/*없을때 삭제*/
		if (Key_compareTo(aKey,BinaryNode_key(_this->_root)) != 0) {
			return Dictionary_removeFromTreeRecursively(_this,aKey,_this->_root);
		}
		else {
			BinaryNode* removedNode = _this->_root;
			if (BinaryNode_left(_this->_root) == NULL) {
				// 왼쪽 노드가 비었을 경우 오른쪽 노드로 넘어간다.
				_this->_root = BinaryNode_right(_this->_root);
			}
			else if (BinaryNode_right(_this->_root) == NULL) {
				// 오른쪽 노드가 비었을 경우 왼쪽 노드로 넘어간다.
				_this->_root = BinaryNode_left(_this->_root);
			}
			else {
				BinaryNode* rightmost = Dictionary_removeRightmostNodeOfLeftSubtree(_this, removedNode);
				BinaryNode_setLeft(rightmost, BinaryNode_left(removedNode));
				BinaryNode_setRight(rightmost, BinaryNode_right(removedNode));
				_this->_root = rightmost;
			}
			Object* removedObject = BinaryNode_object(removedNode);
			BinaryNode_setObject(removedNode, NULL);
			BinaryNode_setLeft(removedNode, NULL);
			BinaryNode_setRight(removedNode, NULL);
			BinaryNode_delete(removedNode);
			_this->_size--;
			return (removedObject);
		}
	}
}

void Dictionary_scanInSortedOrder(Dictionary* _this, Traverse* aTraverse) {
	{	// Traverse 함수를 활용하여 inorder를 구한다.
		Dictionary_inorder(_this, aTraverse, _this->_root, 1);
	}
}

void Dictionary_inorder(Dictionary* _this, Traverse* aTraverse, BinaryNode* aRoot, int aDepth)
{ // inoder를 바탕으로 깊이를 추가해준다.
	if (aRoot != NULL) {
		Dictionary_inorder(_this, aTraverse, BinaryNode_left(aRoot), aDepth + 1);
		Traverse_visit(aTraverse, BinaryNode_key(aRoot), BinaryNode_object(aRoot), aDepth);
		Dictionary_inorder(_this, aTraverse, BinaryNode_right(aRoot), aDepth + 1);
	}
}

Boolean Dictionary_replaceObjectForKey(Dictionary* _this, Key* aKey, Object* anObject) {
	if (Dictionary_searchTreeRecursively(_this, aKey, _this->_root) != NULL) {
		return TRUE;
	}
	// 널이 아니라면 같은 키값을 가진 아이템이 존재하는것이다.
	return FALSE;
}


Object* Dictionary_removeFromTreeRecursively(Dictionary* _this, Key* aKey, BinaryNode* parent)
{ // 트리를 재귀를 사용하여 삭제한다.
	if (Key_compareTo(BinaryNode_key(parent), aKey) < 0) {
		BinaryNode* leftChild = BinaryNode_left(parent);
		if (leftChild == NULL) {
			return NULL;
			// 파라미터가 더 작을 경우 
		}
		if (Key_compareTo(BinaryNode_key(leftChild), aKey) == 0) {
			// 파라미터가 같을 경우
			BinaryNode* removedNode = leftChild;
			if (BinaryNode_left(removedNode) == NULL) {
				BinaryNode_setLeft(parent, BinaryNode_right(removedNode));
			}
			else if (BinaryNode_right(removedNode) == NULL) {
				BinaryNode_setLeft(parent, BinaryNode_left(removedNode));
			}
			else {
				BinaryNode* rightmost = Dictionary_removeRightmostNodeOfLeftSubtree(_this, removedNode);
				BinaryNode_setLeft(rightmost, BinaryNode_left(removedNode));
				BinaryNode_setRight(rightmost, BinaryNode_right(removedNode));
				BinaryNode_setLeft(parent, rightmost);
			}
			Object* removedObject = BinaryNode_object(removedNode);
			BinaryNode_setObject(removedNode, NULL);
			BinaryNode_setLeft(removedNode, NULL);
			BinaryNode_setRight(removedNode, NULL);
			BinaryNode_delete(removedNode);
			_this->_size--;
			return (removedObject);
		}
		else {
			return (Dictionary_removeFromTreeRecursively(_this, aKey, leftChild));
		}
	}
	else if(Key_compareTo(BinaryNode_key(parent), aKey) > 0) {
		BinaryNode* rightChild = BinaryNode_right(parent);
		if (rightChild == NULL) {
			return NULL;
		}
		if (Key_compareTo(BinaryNode_key(rightChild), aKey) == 0) {
			BinaryNode* removedNode = rightChild;
			if (BinaryNode_right(removedNode) == NULL) {
				BinaryNode_setRight(parent, BinaryNode_left(removedNode));
			}
			else if (BinaryNode_left(removedNode) == NULL) {
				BinaryNode_setRight(parent, BinaryNode_right(removedNode));
			}
			else {
				BinaryNode* leftmost = Dictionary_removeLeftmostNodeOfRightSubtree(_this, removedNode);
				BinaryNode_setRight(leftmost, BinaryNode_right(removedNode));
				BinaryNode_setLeft(leftmost, BinaryNode_left(removedNode));
				BinaryNode_setRight(parent, leftmost);
			}
			Object* removedObject = BinaryNode_object(removedNode);
			BinaryNode_setObject(removedNode, NULL);
			BinaryNode_setRight(removedNode, NULL);
			BinaryNode_setLeft(removedNode, NULL);
			BinaryNode_delete(removedNode);
			_this->_size--;
			return (removedObject);
		}
		else {
			return (Dictionary_removeFromTreeRecursively(_this, aKey, rightChild));
		}
	}
else {
	AppIO_out_nodeletedElementFromQueue();
	}
}

Object* Dictionary_removeRightmostNodeOfLeftSubtree(Dictionary* _this, BinaryNode* rootOfLeftSubtree)
{
	BinaryNode* rightmost = NULL;
	BinaryNode* leftOfRoot = BinaryNode_left(rootOfLeftSubtree);
	rightmost = leftOfRoot;
	if (BinaryNode_right(leftOfRoot) == NULL) {
		BinaryNode_setLeft(rootOfLeftSubtree, BinaryNode_left(leftOfRoot));
	}
	else {
		BinaryNode* parentOfRightmost = NULL;
		do {
			parentOfRightmost = rightmost;
			rightmost = BinaryNode_right(rightmost);
		} while (BinaryNode_right(rightmost) != NULL);
		BinaryNode_setRight(parentOfRightmost, BinaryNode_left(rightmost));
	}
	BinaryNode_setLeft(rightmost, NULL);
	BinaryNode_setRight(rightmost, NULL);
	return rightmost;
}



Object* Dictionary_removeLeftmostNodeOfRightSubtree(Dictionary* _this, BinaryNode* rootOfRightSubtree)
{
	BinaryNode* leftmost = NULL;
	BinaryNode* rightOfRoot = BinaryNode_right(rootOfRightSubtree);
	leftmost = rightOfRoot;
	if (BinaryNode_left(rightOfRoot) == NULL) {
		BinaryNode_setRight(rootOfRightSubtree, BinaryNode_right(rightOfRoot));
	}
	else {
		BinaryNode* parentOfLeftmost = NULL;
		do {
			parentOfLeftmost = leftmost;
			leftmost = BinaryNode_left(leftmost);
		} while (BinaryNode_left(leftmost) != NULL);
		BinaryNode_setLeft(parentOfLeftmost, BinaryNode_right(leftmost));
	}
	BinaryNode_setRight(leftmost, NULL);
	BinaryNode_setLeft(leftmost, NULL);
	return leftmost;
}

