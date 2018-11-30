#include "AppIO.h"

#include <stdio.h>
#include <conio.h>

char AppIO_in_charDirectlyFromKeyboard()
{ // 사용자의 키보드로부터 입력받은 문자를 엔터 필요없이 바로 저장한다.
	printf(">문자를 입력하시오 : ");
	char charDirectlyFromKeyboard = getCharDirectlyFromKeyboard();
	AppIO_out_newLine();
	return charDirectlyFromKeyboard;
}

char AppIO_in_charDirectlyFromKeyboard_remove1()
{ // 사용자의 키보드로부터 입력받은 문자를 엔터 필요없이 바로 저장한다.
	printf("삭제할 객체의 Key 값을 입력하시오 : ");
	char charDirectlyFromKeyboard = getCharDirectlyFromKeyboard();
	AppIO_out_newLine();
	return charDirectlyFromKeyboard;
}

char AppIO_in_charDirectlyFromKeyboard_search()
{ // 사용자의 키보드로부터 입력받은 문자를 엔터 필요없이 바로 저장한다.
	printf("검색할 객체의 Key 값을 입력하시오 : ");
	char charDirectlyFromKeyboard = getCharDirectlyFromKeyboard();
	AppIO_out_newLine();
	return charDirectlyFromKeyboard;
}

char getCharDirectlyFromKeyboard(void)
{ /*기존 엔터를 누르는 방식이 아닌 키보드에서
  누르는 순간 바로 인식하도록 하는 함수*/
	char charFromKeyboard;
	charFromKeyboard = _getch();
	return charFromKeyboard;
}


void AppIO_out_queueIsFullAgainstPush(char aChar)
{
	printf("[Full] 큐가 꽉 차서 원소 \'%c\' 는 삽입이 불가능합니다.\n", aChar);
}
void AppIO_out_addedElementInQueue(char KeyValue, int objectValue)
{
	printf("[Add] 삽입된 키-객체 쌍은 <'%c' %d> 입니다.\n", KeyValue, objectValue);
}
void AppIO_out_noElementInQueue()
{
	printf("[Empty] 큐에 삭제할 원소가 없습니다.\n");
}
void AppIO_out_removed1ElementFromQueue(char c, int value)
{
	printf("[삭제] <%c, %d> 이 성공적으로 삭제되었습니다.", c, value);
}

void AppIO_out_searchedElementFromQueue(char c, int value)
{
	printf("[검색] <%c, %d> 쌍이 사전에 존재합니다.", c, value);
}
void AppIO_out_nodeletedElementFromQueue()
{
	printf("[삭제] 주어진 키가 사전에 존재하지 않습니다.");
}
void AppIO_out_nosearchedElementFromQueue()
{
	printf("[검색] 주어진 키가 사전에 존재하지 않습니다.");
}

void AppIO_out_queueIsEmptyAgainstPops()
{
	printf("[Empty] 큐에 더 이상 삭제할 원소가 없습니다.\n");
}

void AppIO_out_noFrontElement()
{
	printf("[Empty] 현재 큐는 비어 있습니다.\n");
}

void AppIO_out_newLine()
{
	printf("\n");
}
void AppIO_out_queueSize(int stackSize)
{
	printf("[Size] 현재 큐의 크기는 %d 입니다.\n", stackSize);
}
void AppIO_out_ignoredChar()
{
	printf("[Ignore] 의미 없는 문자가 입력되었습니다.\n");
}

void AppIO_out_startProgram()
{
	printf("<<< 사전 활용 프로그램을 시작합니다 >>>\n ");
	AppIO_out_newLine();
}
void AppIO_out_endProgram()
{
	AppIO_out_newLine();
	printf(" <<< 사전 활용 프로그램을 종료합니다 >>>\n ");
}

void AppIO_out_numberOfElements(int numberOfChars) {
	printf("[Size] 큐에는 현재 %d개의 원소가 있습니다.\n", numberOfChars);
}
void AppIO_out_tree() {
	printf("[Tree]\n");
}