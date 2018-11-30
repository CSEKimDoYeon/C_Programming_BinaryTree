#pragma once


char AppIO_in_charDirectlyFromKeyboard();
char AppIO_in_charDirectlyFromKeyboard_remove1();
char AppIO_in_charDirectlyFromKeyboard_search();
char getCharDirectlyFromKeyboard(void);

void AppIO_out_queueIsFullAgainstPush(char anElementForPush);
void AppIO_out_addedElementInQueue(char KeyValue, int objectValue);
void AppIO_out_noElementInQueue();
void AppIO_out_removed1ElementFromQueue(char c, int value);

void AppIO_out_searchedElementFromQueue();
void AppIO_out_nosearchedElementFromQueue();

void AppIO_out_queueIsEmptyAgainstPops();
void AppIO_out_noFrontElement();

void AppIO_out_newLine();
void AppIO_out_queueSize(int stackSize);
void AppIO_out_ignoredChar();

void AppIO_out_startProgram();
void AppIO_out_endProgram();
void AppIO_out_numberOfElements(int numberOfChars);
void AppIO_out_nodeletedElementFromQueue();
void AppIO_out_tree();