#include<iostream>
#include"linearList.h"
#include"Word.h"
#define MAXLEN 5000
using namespace std;

int main()
{
	int idx;
	cin >> idx;
	if (idx == 1) {
		MyArray obj1(1);
		obj1.storeWordsInArray();
		obj1.storeWordsInOutFile_1();
		MyArray ojb2(0);
		ojb2.storeWordsInArray();
		ojb2.storeWordsInOutFile_1();
	}
	getchar();
	getchar();
	return 0;
}