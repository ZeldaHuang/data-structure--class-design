#pragma once
#ifndef HASHMAP_H
#define HASHMAP_H
#include"Word.h"
#include"linearList.h"
#define MAXLEN 5000
struct HashLinkList {
	int length;
	Node *head;
	HashLinkList() {
		head = NULL;
		length = 0;
	}
};
class MyHashMap_StoreWithLinkList//����ַ���洢
{
public:

	MyHashMap_StoreWithLinkList():totWord(0){}
	void storeWordsInHashMap();
	int findWordInHashMap(string searchStr, bool isInsearchFunction,int &findCnt);
	void storeWordsInOutFile();
	void wordsFilter(int filterVal);
	MyHashMap_StoreWithLinkList& operator=(MyHashMap_StoreWithLinkList &tmpHashMap);

	~MyHashMap_StoreWithLinkList() {
		int delNum = 0;
		for (int i = 0;i < MAXLEN&&delNum!=totWord;++i)
		{
			Node *ptr=hashElems[i].head;
			while (ptr!=NULL)
			{
				Node *delPtr = ptr;
				ptr = ptr->next;
				delete delPtr;
				delNum++;
			}
		}
	}
private:
	HashLinkList hashElems[MAXLEN];
	int totWord;
	void insertWordInHashMap(string &str);
	int hash(string key); //hash������һ��(ȡģ��)  
	void getWordsInLine(char *str, string &tmpString);
};

class MyHashMap_StoreWithArray
{
public:
	MyHashMap_StoreWithArray() :totWord(0) { memset(isExist, 0, sizeof(isExist)); }

	void storeWordsInHashMap();
	int findWordInHashMap(string searchStr, bool isInsearchFunction, int &pos,int &findCnt);
	void storeWordsInOutFile();
	void wordsFilter(int filterVal);

private:
	MyWord hashElems[MAXLEN];
	bool isExist[MAXLEN];
	int totWord;
	int hash(string key); //hash������һ��(ȡģ��)  
	void getWordsInLine(char *str, string &tmpString);
	void Collision(int &p);
};

#endif // !HASHMAP_H
