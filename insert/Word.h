
#ifndef WORD_H

#define WORD_H

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
	MyWord& operator =(MyWord tmp){
		word = tmp.word;
		count = tmp.count;
		return *this;
	}
	bool operator<(MyWord& tmp) {
		return word < tmp.getWord();
	}
	bool operator>=(MyWord& tmp) {
		return word >= tmp.getWord();
	}
	~MyWord(){}
};
#endif //WORD_H
