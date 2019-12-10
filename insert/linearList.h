#pragma once
#ifndef LINEARLIST_H
#define LINEARLIST_H
#include"Word.h"
#define MAXLEN 5000
//��˳�����д�Ƶͳ�ƺ�˳����һ���ֲ���
class MyArray:protected MyWord
{
public:
	MyArray(bool judge):isBinarySearch(judge),totWord(0){}

	void storeWordsInArray();//�����ʴ�InFILE�ж�������

	bool findWordInOrder(string searchStr,bool isInsearchFunction);//���ҵ��ʣ������Ͳ���/����

	void storeWordsInOutFile_1();//��Ƶͳ���ֵ���������ļ�

	bool binarysSearch(string searchStr);

	~MyArray() {};
private:
	MyWord wordsArray[MAXLEN];
	int totWord;
	bool isBinarySearch;
	void getWordsInLine(char *str);
};


//��������д�Ƶͳ�ƺ�˳�����
struct Node{//����ڵ�
	MyWord data;
	Node *next;
};

class MyLinkList
{
public:
	MyLinkList() :head(NULL), tail(NULL), totWord(0) {}

	Node *getHead() { return head; }

	void storeWordsInList();//�����ʴ�InFILE�ж�������

	bool findWordInOrder(string searchStr, bool isInsearchFunction);

	void storeWordsInOutFile_1();

	MyLinkList& operator=(MyLinkList &tmpList);

	~MyLinkList() {
		Node *ptr = head;
		while (!ptr == NULL) {
			Node *delPtr = ptr;
			ptr = ptr->next;
			delete delPtr;
		}
	}
private:
	int totWord;
	Node *head;
	Node *tail;
	void getWordsInLine(char *str);
	void tailInsert(string s);
};

#endif