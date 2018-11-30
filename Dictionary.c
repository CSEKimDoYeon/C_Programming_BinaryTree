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
} // �⺻ ������

void Dictionary_delete(Dictionary* _this) {
	Dictionary_deleteBinaryNodes(_this, _this->_root);
	free(_this);
} // ���� ��ü�� �����Ѵ�, deleteBinaryNode�� �����Ͽ� ���������� �����.

void Dictionary_deleteBinaryNodes(Dictionary* _this, BinaryNode * aNode)
{
	if (aNode != NULL) {
		Dictionary_deleteBinaryNodes(_this, BinaryNode_left(aNode));
		Dictionary_deleteBinaryNodes(_this, BinaryNode_right(aNode));
		BinaryNode_delete(aNode);
	}
	// ���� ���� ������ ��� ������ ��������� �����Ѵ�.
}

Boolean Dictionary_isEmpty(Dictionary* _this) {
	return (_this->_root == NULL);
	// root�� null �� ��츦 üũ�Ѵ�.
}

Boolean Dictionary_isFull(Dictionary* _this) {
	return (FALSE);
	// ������ �׻� �� �������Ƿ� �׻� false�� ��ȯ�Ѵ�.
}

int Dictionary_size(Dictionary* _this) {
	return (_this->_size);
	// ������ ����� ��ȯ�Ѵ�.
}

Boolean Dictionary_keyDoesExist(Dictionary* _this, Key* aKey) {
	return (Dictionary_searchTreeRecursively(_this, aKey, _this->_root) != NULL);
} // �ش� �Ķ������ Ű���� ��������� �˻��Ѵ�.

Object* Dictionary_objectForKey(Dictionary* _this, Key* aKey) {
	return (Dictionary_searchTreeRecursively(_this, aKey, _this->_root));
} // �ش� Ű������ ������Ʈ�� ��ȯ�Ѵ�.

Object* Dictionary_searchTreeRecursively(Dictionary* _this, Key* aKey, BinaryNode* aNode)
{ // �ص� Ű������ �˻��� �����Ѵ�.
	if (aNode == NULL) {
		return NULL;
	}
	else {
		if (Key_compareTo(BinaryNode_key(aNode), aKey) == 0) {
			// Ű���� �Ķ������ ���� ���� ���
			return (BinaryNode_object(aNode)); // ��ȯ�Ѵ�.
		}
		else if (Key_compareTo(BinaryNode_key(aNode), aKey) < 0) {
			// �Ķ���Ͱ� �� ���� ��� ���� ��带 �˻��Ѵ�.
			return (Dictionary_searchTreeRecursively(_this, aKey, BinaryNode_left(aNode)));
		}
		else {
			// �Ķ���Ͱ� �� Ŭ ��� ������ ��带 �˻��Ѵ�.
			return (Dictionary_searchTreeRecursively(_this, aKey, BinaryNode_right(aNode)));
		}
	}
}

Boolean Dictionary_addKeyAndObject(Dictionary* _this, Key* aKey, Object* anObject) {
	if (_this->_root == NULL) {
		_this->_root = BinaryNode_newWith(aKey, anObject, NULL, NULL);
		_this->_size++;
		// ��Ʈ�� null�� ��� ���ο� ���̳ʸ� Ʈ���� �����Ѵ�.
		return (TRUE);
	}
	else {
		// ���� ��带 ã���� replace �޽��� ����.
		if (Dictionary_replaceObjectForKey(_this, aKey, anObject) == TRUE) { // ���� ���� ��带 ã����
			printf("[Replace] key <'%c'> �� object�� <%d> �� ��ü�մϴ�.\n", Key_value(aKey), Object_value(anObject));
			return FALSE;
		}
		else {
			_this->_size++;
			return (Dictionary_addToTree(_this, aKey, anObject, _this->_root));
		}
	}
}

Boolean Dictionary_addToTree(Dictionary* _this, Key* aKey, Object* anObject, BinaryNode* parent)
{ // ������ ���ο� ���̳ʸ� Ʈ���� �����Ѵ�.
	if (Key_compareTo(BinaryNode_key(parent), aKey) < 0) {
	// �Ķ���Ͱ� �� ���� ���
		if (BinaryNode_left(parent) == NULL) {
			BinaryNode_setLeft(parent, BinaryNode_newWith(aKey, anObject, NULL, NULL));
			return TRUE; // ���� ��忡 ���� �߰��Ѵ�.
		}
		else {
			return Dictionary_addToTree(_this, aKey, anObject, BinaryNode_left(parent));
		}
	}
	else if (Key_compareTo(BinaryNode_key(parent), aKey) > 0) {
		// �Ķ���Ͱ� �� Ŭ ��� ������ ��忡 ���� �߰��Ѵ�.
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
	if (Dictionary_isEmpty(_this)) { // Ű ������ ������Ʈ�� �����Ѵ�.
		return (NULL);
	}
	else {
		/*������ ����*/
		if (Key_compareTo(aKey,BinaryNode_key(_this->_root)) != 0) {
			return Dictionary_removeFromTreeRecursively(_this,aKey,_this->_root);
		}
		else {
			BinaryNode* removedNode = _this->_root;
			if (BinaryNode_left(_this->_root) == NULL) {
				// ���� ��尡 ����� ��� ������ ���� �Ѿ��.
				_this->_root = BinaryNode_right(_this->_root);
			}
			else if (BinaryNode_right(_this->_root) == NULL) {
				// ������ ��尡 ����� ��� ���� ���� �Ѿ��.
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
	{	// Traverse �Լ��� Ȱ���Ͽ� inorder�� ���Ѵ�.
		Dictionary_inorder(_this, aTraverse, _this->_root, 1);
	}
}

void Dictionary_inorder(Dictionary* _this, Traverse* aTraverse, BinaryNode* aRoot, int aDepth)
{ // inoder�� �������� ���̸� �߰����ش�.
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
	// ���� �ƴ϶�� ���� Ű���� ���� �������� �����ϴ°��̴�.
	return FALSE;
}


Object* Dictionary_removeFromTreeRecursively(Dictionary* _this, Key* aKey, BinaryNode* parent)
{ // Ʈ���� ��͸� ����Ͽ� �����Ѵ�.
	if (Key_compareTo(BinaryNode_key(parent), aKey) < 0) {
		BinaryNode* leftChild = BinaryNode_left(parent);
		if (leftChild == NULL) {
			return NULL;
			// �Ķ���Ͱ� �� ���� ��� 
		}
		if (Key_compareTo(BinaryNode_key(leftChild), aKey) == 0) {
			// �Ķ���Ͱ� ���� ���
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

