#include "AppController.h"
#include "AppIO.h"

int array[100];
int arraycount = 0;

void AppController_run(AppController* _this) { // ���α׷� ���� �Լ�.
	AppIO_out_startProgram();
	//AppController_initCountingChars(_this);
	AppIO_out_newLine();
	char c = AppIO_in_charDirectlyFromKeyboard();
	// Ű����� �Է¹��� ���ڸ� ���� ����.

	while (c != Esc) { // Esc�� �Է� �� �� ���� ����.
					   //AppController_countInputChars(_this);
		if (isAlpha(c)) {
			AppController_add(_this, c);
			// ���ĺ��ϰ�� ť�� Add
		}
		else if (c == '-') {
			AppController_remove1(_this);
			// - �� ��� �ϳ��� Remove
		}
		else if (c == '#') {
			AppController_showSize(_this);
			// # �� ��� ť�� ������ ���.
		}
		else if (c == '/') {
			AppController_showAll(_this);
			// '/' �� ��� ť�� front���� rear���� ���.
		}
		else if (c == '?') {
			AppController_search(_this);
			// '/' �� ��� ť�� front���� rear���� ���.
		}
		else {
			AppController_ignore(_this);
			// �̿��� ���ڴ� ���� ó��.
		}
		AppIO_out_newLine();
		c = AppIO_in_charDirectlyFromKeyboard();
	}
	AppIO_out_endProgram();
}

AppController* AppController_new() {
	// AppController ��ü ����.
	AppController* _this;
	_this = NewObject(AppController);
	_this->_dictionary = Dictionary_new();

	return (_this);
}

void AppController_delete(AppController* _this) {
	// AppController ��ü ����.
	Dictionary_delete(_this->_dictionary);
	free(_this);
}

void AppController_add(AppController* _this, char aChar) {

	char KeyValue = aChar; // ������ Ű ���
	int objectValue = (int)aChar; // ������ ������Ʈ ���
	 
	Key* aKey = Key_newWith(KeyValue); // ���ο� Ű�� �����Ѵ�.
	Object* anObject = Object_newWith(objectValue); // ���ο� ������Ʈ�� �����Ѵ�.
	
	if (Dictionary_addKeyAndObject(_this->_dictionary, aKey, anObject) == TRUE) {
		array[arraycount] = objectValue; // ������Ʈ ����� array�� �ӽ������Ѵ�.
		AppIO_out_addedElementInQueue(KeyValue, objectValue); 
	}
}

void AppController_remove1(AppController* _this) {
	if (Dictionary_isEmpty(_this->_dictionary)) {
		AppIO_out_noElementInQueue(); // ������ ������� ��� ���� �޽��� ���.
	}
	else {
		char c = AppIO_in_charDirectlyFromKeyboard_remove1(); // ������ Ű�� �Է¹޴´�.
		Key* aKey = Key_newWith(c); // �Է¹��� Ű������ ���ο� Ű�� ����.

		Object* removedObject = Dictionary_removeObjectForKey(_this->_dictionary, aKey);
		if(removedObject!=NULL){ // �����ϰ��� �ϴ� ������Ʈ�� ������ ���.
			AppIO_out_removed1ElementFromQueue(c, Object_value(removedObject));
			// �ش� ������Ʈ�� �����Ѵ�.
		}
		else if (removedObject == NULL) { // ���� ������Ʈ�� ���� ���
			AppIO_out_nodeletedElementFromQueue();
			// ���� �޽��� ���.
		}
	}
}

void AppController_search(AppController* _this) {
	if (Dictionary_isEmpty(_this->_dictionary)) {
		AppIO_out_noElementInQueue();
	}
	else {
		char c = AppIO_in_charDirectlyFromKeyboard_search(); // ������ Ű�� �Է¹޴´�.
		Key* aKey = Key_newWith(c); // �Է¹��� Ű������ ���ο� Ű�� ����.

		Object* searchedObject = Dictionary_searchTreeRecursively(_this->_dictionary, aKey, _this->_dictionary->_root);

		if (searchedObject != NULL) { // ������Ʈ�� ������ ���
			AppIO_out_searchedElementFromQueue(c, Object_value(searchedObject));
			// �˻��� �����Ѵ�.
		}
		else
			AppIO_out_nosearchedElementFromQueue();
	}
}

void AppController_showSize(AppController* _this) {
	// ���� ������ size�� ����Ѵ�.
	int size = Dictionary_size(_this->_dictionary);
	AppIO_out_numberOfElements(size);
}

void AppController_ignore(AppController* _this) {
	// ������ ���� �̿��� ���� ��ȿó���Ѵ�.
	AppIO_out_ignoredChar();
}

void AppController_showInternalShapeOfBinaryTree(AppController* _this, Traverse* aTraverse)
{
	Dictionary_scanInSortedOrder(_this->_dictionary, aTraverse);
}

void AppController_showAll(AppController* _this) {
	Traverse* t = Traverse_new();
	// ���ο� traverse ����ü ����.
	AppIO_out_tree(); // Ʈ���� ����Ѵ�.
	AppController_showInternalShapeOfBinaryTree(_this, t);
	// ������ Ʈ�� ������� ����Ѵ�.
}