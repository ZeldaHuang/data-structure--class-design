#pragma once
#ifndef LINEARLIST_H
#define LINEARLIST_H
#include"Word.h"
#define MAXLEN 5000
//用顺序表进行词频统计和顺序查找或二分查找
class MyArray
{
public:
    MyArray():totWord(0),isBinarySearch(0){}

	void storeWordsInArray();//将单词从InFILE中读入数组

	int findWordInOrder(string searchStr,bool isInsearchFunction,int &findcnt);//查找单词，功能型查找/内置

	void storeWordsInOutFile();//词频统计字典序输出至文件

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


//用链表进行词频统计和顺序查找
struct Node{//链表节点
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

	void storeWordsInList();//将单词从InFILE中读入数组

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
