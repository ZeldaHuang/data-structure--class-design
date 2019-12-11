#pragma once
#ifndef LINEARLIST_H
#define LINEARLIST_H
#include"Word.h"
#define MAXLEN 5000
//用顺序表进行词频统计和顺序查找或二分查找
class MyArray
{
public:
	MyArray(bool judge):isBinarySearch(judge),totWord(0){}

	void storeWordsInArray();//将单词从InFILE中读入数组

	bool findWordInOrder(string searchStr,bool isInsearchFunction);//查找单词，功能型查找/内置

	void storeWordsInOutFile();//词频统计字典序输出至文件

	bool binarysSearch(string searchStr);

	void wordsFilter(int filterVal);

	~MyArray() {};
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

	bool findWordInOrder(string searchStr, bool isInsearchFunction);

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