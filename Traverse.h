#pragma once
#include "key.h"
#include "Object.h"

typedef struct _Traverse Traverse;

struct _Traverse {
	// something if necessary
	int a; // 임시저장
};

Traverse* Traverse_new(void); // 생성자
void Traverse_delete(Traverse* _this); // 소멸자
void Traverse_visit(Traverse* _this, Key* aKey, Object* anObject, int aDepth);
// 사전을 traverse 하는 동안,
// Dictionary 객체 내의 노드를 visit 할 때마다의 할 일을 정의한다.
// 이 함수의 정의는 응용에 따라 달라질 수 있다. (매개변수, 하는 일)
// <aKey, anObject> : 현재 방문하는 key-object 쌍
// aDepth: 이진트리에서 <aKey, anObject> 쌍을 가지고 있는 노드의 깊이