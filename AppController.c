#include "AppController.h"
#include "AppIO.h"

int array[100];
int arraycount = 0;

void AppController_run(AppController* _this) { // 프로그램 실행 함수.
	AppIO_out_startProgram();
	//AppController_initCountingChars(_this);
	AppIO_out_newLine();
	char c = AppIO_in_charDirectlyFromKeyboard();
	// 키보드로 입력받은 문자를 직접 삽입.

	while (c != Esc) { // Esc가 입력 될 때 까지 진행.
					   //AppController_countInputChars(_this);
		if (isAlpha(c)) {
			AppController_add(_this, c);
			// 알파벳일경우 큐에 Add
		}
		else if (c == '-') {
			AppController_remove1(_this);
			// - 일 경우 하나를 Remove
		}
		else if (c == '#') {
			AppController_showSize(_this);
			// # 일 경우 큐의 사이즈 출력.
		}
		else if (c == '/') {
			AppController_showAll(_this);
			// '/' 일 경우 큐의 front부터 rear까지 출력.
		}
		else if (c == '?') {
			AppController_search(_this);
			// '/' 일 경우 큐의 front부터 rear까지 출력.
		}
		else {
			AppController_ignore(_this);
			// 이외의 문자는 무시 처리.
		}
		AppIO_out_newLine();
		c = AppIO_in_charDirectlyFromKeyboard();
	}
	AppIO_out_endProgram();
}

AppController* AppController_new() {
	// AppController 객체 생성.
	AppController* _this;
	_this = NewObject(AppController);
	_this->_dictionary = Dictionary_new();

	return (_this);
}

void AppController_delete(AppController* _this) {
	// AppController 객체 삭제.
	Dictionary_delete(_this->_dictionary);
	free(_this);
}

void AppController_add(AppController* _this, char aChar) {

	char KeyValue = aChar; // 저장할 키 밸류
	int objectValue = (int)aChar; // 저장할 오브젝트 밸류
	 
	Key* aKey = Key_newWith(KeyValue); // 새로운 키를 생성한다.
	Object* anObject = Object_newWith(objectValue); // 새로운 오브젝트를 생성한다.
	
	if (Dictionary_addKeyAndObject(_this->_dictionary, aKey, anObject) == TRUE) {
		array[arraycount] = objectValue; // 오브젝트 밸류를 array에 임시저장한다.
		AppIO_out_addedElementInQueue(KeyValue, objectValue); 
	}
}

void AppController_remove1(AppController* _this) {
	if (Dictionary_isEmpty(_this->_dictionary)) {
		AppIO_out_noElementInQueue(); // 사전이 비어있을 경우 에러 메시지 출력.
	}
	else {
		char c = AppIO_in_charDirectlyFromKeyboard_remove1(); // 삭제할 키를 입력받는다.
		Key* aKey = Key_newWith(c); // 입력받은 키값으로 새로운 키를 생성.

		Object* removedObject = Dictionary_removeObjectForKey(_this->_dictionary, aKey);
		if(removedObject!=NULL){ // 삭제하고자 하는 오브젝트가 존재할 경우.
			AppIO_out_removed1ElementFromQueue(c, Object_value(removedObject));
			// 해당 오브젝트를 삭제한다.
		}
		else if (removedObject == NULL) { // 삭제 오브젝트가 없을 경우
			AppIO_out_nodeletedElementFromQueue();
			// 에러 메시지 출력.
		}
	}
}

void AppController_search(AppController* _this) {
	if (Dictionary_isEmpty(_this->_dictionary)) {
		AppIO_out_noElementInQueue();
	}
	else {
		char c = AppIO_in_charDirectlyFromKeyboard_search(); // 삭제할 키를 입력받는다.
		Key* aKey = Key_newWith(c); // 입력받은 키값으로 새로운 키를 생성.

		Object* searchedObject = Dictionary_searchTreeRecursively(_this->_dictionary, aKey, _this->_dictionary->_root);

		if (searchedObject != NULL) { // 오브젝트가 존재할 경우
			AppIO_out_searchedElementFromQueue(c, Object_value(searchedObject));
			// 검색을 시작한다.
		}
		else
			AppIO_out_nosearchedElementFromQueue();
	}
}

void AppController_showSize(AppController* _this) {
	// 현재 사전의 size를 출력한다.
	int size = Dictionary_size(_this->_dictionary);
	AppIO_out_numberOfElements(size);
}

void AppController_ignore(AppController* _this) {
	// 지정된 문자 이외의 것을 무효처리한다.
	AppIO_out_ignoredChar();
}

void AppController_showInternalShapeOfBinaryTree(AppController* _this, Traverse* aTraverse)
{
	Dictionary_scanInSortedOrder(_this->_dictionary, aTraverse);
}

void AppController_showAll(AppController* _this) {
	Traverse* t = Traverse_new();
	// 새로운 traverse 구조체 선언.
	AppIO_out_tree(); // 트리를 출력한다.
	AppController_showInternalShapeOfBinaryTree(_this, t);
	// 사전을 트리 모양으로 출력한다.
}