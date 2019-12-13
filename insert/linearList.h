#pragma once
#ifndef LINEARLIST_H
#define LINEARLIST_H
#include"Word.h"
#define MAXLEN 5000
//��˳�����д�Ƶͳ�ƺ�˳����һ���ֲ���
class MyArray
{
public:
    MyArray():totWord(0),isBinarySearch(0){}

	void storeWordsInArray();//�����ʴ�InFILE�ж�������

	int findWordInOrder(string searchStr,bool isInsearchFunction,int &findcnt);//���ҵ��ʣ������Ͳ���/����

	void storeWordsInOutFile();//��Ƶͳ���ֵ���������ļ�

	int binarysSearch(string searchStr,int &cnt);

	void wordsFilter(int filterVal);

    void binarysSearchMode(){isBinarySearch=1;}

    ~MyArray() {}
private:
	MyWord wordsArray[MAXLEN];
	int totWord;
	bool isBinarySearch;
	void getWordsInLine(char *str, string &tmpString);
};


//��������д�Ƶͳ�ƺ�˳�����
struct Node{//����ڵ�
	MyWord data;
	Node *next;
	Node() {
		next = NULL;
	}
};

class MyLinkList
{
public:
	MyLinkList() :head(NULL), tail(NULL), totWord(0) {}

	Node *getHead() { return head; }

	void storeWordsInList();//�����ʴ�InFILE�ж�������

	int findWordInOrder(string searchStr, bool isInsearchFunction, int &findcnt);

	void storeWordsInOutFile();

	MyLinkList& operator=(MyLinkList &tmpList);

	void wordsFilter(int filterVal);

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
	void getWordsInLine(char *str, string &tmpString);
	void tailInsert(string s);
};

#endif
