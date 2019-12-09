
#ifndef CLASS_H

#define CLASS_H

#include<string>
#include<iostream>
using namespace std;
class MyWord {
protected:
	string word;
	int count;
public:
	MyWord()
	{
		word = "&&&";
		count = 1;
	}
	MyWord(string s)
	{
		word = s;
		count = 1;
	}
	string getWord()
	{
		return word;
	}
	int getCount()
	{
		return count;
	}
	void addCount()
	{
		count++;
	}
	void operator =(MyWord tmp)
	{
		word = tmp.word;
		count = tmp.count;
		return;
	}
	~MyWord(){}
};
#endif //CLASS_H
