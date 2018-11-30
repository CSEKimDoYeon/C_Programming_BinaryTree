#include "AppIO.h"

#include <stdio.h>
#include <conio.h>

char AppIO_in_charDirectlyFromKeyboard()
{ // ������� Ű����κ��� �Է¹��� ���ڸ� ���� �ʿ���� �ٷ� �����Ѵ�.
	printf(">���ڸ� �Է��Ͻÿ� : ");
	char charDirectlyFromKeyboard = getCharDirectlyFromKeyboard();
	AppIO_out_newLine();
	return charDirectlyFromKeyboard;
}

char AppIO_in_charDirectlyFromKeyboard_remove1()
{ // ������� Ű����κ��� �Է¹��� ���ڸ� ���� �ʿ���� �ٷ� �����Ѵ�.
	printf("������ ��ü�� Key ���� �Է��Ͻÿ� : ");
	char charDirectlyFromKeyboard = getCharDirectlyFromKeyboard();
	AppIO_out_newLine();
	return charDirectlyFromKeyboard;
}

char AppIO_in_charDirectlyFromKeyboard_search()
{ // ������� Ű����κ��� �Է¹��� ���ڸ� ���� �ʿ���� �ٷ� �����Ѵ�.
	printf("�˻��� ��ü�� Key ���� �Է��Ͻÿ� : ");
	char charDirectlyFromKeyboard = getCharDirectlyFromKeyboard();
	AppIO_out_newLine();
	return charDirectlyFromKeyboard;
}

char getCharDirectlyFromKeyboard(void)
{ /*���� ���͸� ������ ����� �ƴ� Ű���忡��
  ������ ���� �ٷ� �ν��ϵ��� �ϴ� �Լ�*/
	char charFromKeyboard;
	charFromKeyboard = _getch();
	return charFromKeyboard;
}


void AppIO_out_queueIsFullAgainstPush(char aChar)
{
	printf("[Full] ť�� �� ���� ���� \'%c\' �� ������ �Ұ����մϴ�.\n", aChar);
}
void AppIO_out_addedElementInQueue(char KeyValue, int objectValue)
{
	printf("[Add] ���Ե� Ű-��ü ���� <'%c' %d> �Դϴ�.\n", KeyValue, objectValue);
}
void AppIO_out_noElementInQueue()
{
	printf("[Empty] ť�� ������ ���Ұ� �����ϴ�.\n");
}
void AppIO_out_removed1ElementFromQueue(char c, int value)
{
	printf("[����] <%c, %d> �� ���������� �����Ǿ����ϴ�.", c, value);
}

void AppIO_out_searchedElementFromQueue(char c, int value)
{
	printf("[�˻�] <%c, %d> ���� ������ �����մϴ�.", c, value);
}
void AppIO_out_nodeletedElementFromQueue()
{
	printf("[����] �־��� Ű�� ������ �������� �ʽ��ϴ�.");
}
void AppIO_out_nosearchedElementFromQueue()
{
	printf("[�˻�] �־��� Ű�� ������ �������� �ʽ��ϴ�.");
}

void AppIO_out_queueIsEmptyAgainstPops()
{
	printf("[Empty] ť�� �� �̻� ������ ���Ұ� �����ϴ�.\n");
}

void AppIO_out_noFrontElement()
{
	printf("[Empty] ���� ť�� ��� �ֽ��ϴ�.\n");
}

void AppIO_out_newLine()
{
	printf("\n");
}
void AppIO_out_queueSize(int stackSize)
{
	printf("[Size] ���� ť�� ũ��� %d �Դϴ�.\n", stackSize);
}
void AppIO_out_ignoredChar()
{
	printf("[Ignore] �ǹ� ���� ���ڰ� �ԷµǾ����ϴ�.\n");
}

void AppIO_out_startProgram()
{
	printf("<<< ���� Ȱ�� ���α׷��� �����մϴ� >>>\n ");
	AppIO_out_newLine();
}
void AppIO_out_endProgram()
{
	AppIO_out_newLine();
	printf(" <<< ���� Ȱ�� ���α׷��� �����մϴ� >>>\n ");
}

void AppIO_out_numberOfElements(int numberOfChars) {
	printf("[Size] ť���� ���� %d���� ���Ұ� �ֽ��ϴ�.\n", numberOfChars);
}
void AppIO_out_tree() {
	printf("[Tree]\n");
}