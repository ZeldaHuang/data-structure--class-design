#pragma once
#ifndef LINEARLIST_H
#define LINEARLIST_H
#include<iostream>
#include<string>
#include"Class.h"
#define MAXLEN 5000
//��˳�����д�Ƶͳ�ƺ�˳����һ���ֲ���
class MyArray:protected MyWord
{
public:
	MyArray(bool judge):isBinarySearch(judge),totWord(0){}

	void storeWordsInArray();//�����ʴ�InFILE�ж�������

	bool findWordInOrder(string searchStr,bool isInsearchFunction);//���ҵ��ʣ������Ͳ���/����

	void storeWordsInOutFile_1();//��Ƶͳ���ֵ���������ļ�

	~MyArray() {};
private:
	MyWord wordsArray[MAXLEN];
	int totWord;
	bool isBinarySearch;
	void getWordsInLine(char *str);
};


//��������д�Ƶͳ�ƺ�˳�����


#endif