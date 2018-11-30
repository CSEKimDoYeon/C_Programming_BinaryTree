#include "AppController.h"

int main(void)
{
	AppController* appController = AppController_new();
	// 새로운 AppController 객체 선언.
	AppController_run(appController); // AppController 에서 run 함수 실행.
	AppController_delete(appController); // AppController 를 메모리에서 삭제한다.
	system("pause");
	// 프로그램이 종료되기 전에 일시정지한다.
	return 0;
}