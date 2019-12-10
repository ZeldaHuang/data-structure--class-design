#pragma once
#ifndef LINEARLIST_H
#define LINEARLIST_H
#include<iostream>
#include<string>
#include"Word.h"
#define MAXLEN 5000
//用顺序表进行词频统计和顺序查找或二分查找
class MyArray:protected MyWord
{
public:
	MyArray(bool judge):isBinarySearch(judge),totWord(0){}

	void storeWordsInArray();//将单词从InFILE中读入数组

	bool findWordInOrder(string searchStr,bool isInsearchFunction);//查找单词，功能型查找/内置

	void storeWordsInOutFile_1();//词频统计字典序输出至文件

	~MyArray() {};
private:
	MyWord wordsArray[MAXLEN];
	int totWord;
	bool isBinarySearch;
	void getWordsInLine(char *str);
};


//用链表进行词频统计和顺序查找


#endif