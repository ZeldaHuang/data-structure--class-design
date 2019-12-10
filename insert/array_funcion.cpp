#include<fstream>
#include"linearList.h"
#include"Sort.h"
#include"Word.h"
using namespace std;

void MyArray::storeWordsInArray()
{
	fstream textFile;
	textFile.open("InFile.txt", ios::in);
	if (!textFile) {
		cout << "读取失败" << endl;//处理异常
	}
	char words[MAXLEN];
	while (textFile.getline(words, MAXLEN))
	{
		getWordsInLine(words);
	}
	if (isBinarySearch) {
		quickSort(wordsArray, 1, totWord);
		for (int i = 1;i <= totWord;++i)
		{
			cout << wordsArray[i].getWord() << " " << wordsArray[i].getCount() << endl;
		}
	}
	textFile.close();
}

void MyArray::storeWordsInOutFile_1()
{
	MyWord wordsInOrder[MAXLEN];
	for (int i = 1;i <= totWord;++i) {
		wordsInOrder[i] = wordsArray[i];
	}
	quickSort(wordsInOrder, 1, totWord);
	fstream outFile;
	if (isBinarySearch) {//判断是否为二分查找下的词频统计
		outFile.open("OutFile3.txt", ios::out);
	}
	else {
		outFile.open("OutFile1.txt", ios::out);
	}
	if (!outFile) {
		cout << "读取失败" << endl;//处理异常
		return ;
	}
	outFile << totWord << endl;
	for (int i = 1;i <= totWord;++i)
	{
		outFile << wordsInOrder[i].getWord() << " " << wordsInOrder[i].getCount() << endl;
	}
	outFile.close();
}

void MyArray::getWordsInLine(char *str)
{
	string tmpString;
	for (int i = 0;i < strlen(str);++i)
	{
		if (isalpha(str[i]) || str[i] == '-' || str[i] == 39) {
			tmpString += tolower(str[i]);
		}
		else if(!tmpString.empty()){
			if (!findWordInOrder(tmpString,0)) {
				wordsArray[++totWord] = MyWord(tmpString);
			}
			tmpString.clear();
		}
	}
	return;
}

bool MyArray::findWordInOrder(string searchStr, bool isInsearchFunction)
{
	for (int i = 1;i <= totWord;++i)
	{
		if (wordsArray[i].getWord() == searchStr) {
			if (!isInsearchFunction) wordsArray[i].addCount();
			return true;
		}
	}
	return false;
}

bool MyArray::binarysSearch(string searchStr)
{
	int low = 1, high = totWord;
	while (low <= high)
	{
		int mid = (low + high) >> 1;
		if (wordsArray[mid].getWord() == searchStr) {
			return true;
		}
		else if (wordsArray[mid].getWord() < searchStr) {
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}
	}
	return false;
}