#pragma once
#include "Dictionary.h"

#define Esc 27
#define isDigit(CHAR) (('0'<= CHAR) && (CHAR <='9'))
#define isAlpha(CHAR) ((('a' <= CHAR) && (CHAR <= 'z')) || (('A' <= CHAR) && (CHAR <= 'Z')))

typedef struct _AppController AppController;

struct _AppController {
	Dictionary* _dictionary;
};

void AppController_run(AppController* _this);
AppController* AppController_new();
void AppController_delete(AppController* _this);
void AppController_add(AppController* _this, char aChar);
void AppController_remove1(AppController* _this);

void AppController_showSize(AppController* _this);
void AppController_showAll(AppController* _this);
void AppController_ignore(AppController* _this);

void AppController_showInternalShapeOfBinaryTree(AppController* _this, Traverse* aTraverse);
void AppController_search(AppController* _this);