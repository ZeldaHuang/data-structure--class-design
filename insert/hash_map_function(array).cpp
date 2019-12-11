#include<fstream>
#include"Word.h"
#include"HashMap.h"
#include"Sort.h"

void MyHashMap_StoreWithArray::storeWordsInHashMap()
{
	fstream textFile;
	textFile.open("InFile.txt", ios::in);
	if (!textFile) {
		cout << "读取失败" << endl;//处理异常
	}
	char words[MAXLEN];
	string tmpString;
	while (textFile.getline(words, MAXLEN))
	{
		getWordsInLine(words, tmpString);
	}
	textFile.close();
}

void MyHashMap_StoreWithArray::getWordsInLine(char *str, string &tmpString)
{
	if (tmpString == "-") tmpString.clear();
	for (int i = 0;i < strlen(str);++i)
	{
		if (isalpha(static_cast<unsigned char>(str[i])) || str[i] == '-' || str[i] == 39) {
			if (tmpString == "-") tmpString.clear();
			tmpString += tolower(str[i]);
		}
		else if (!tmpString.empty() && tmpString[tmpString.length() - 1] != '-') {
			int pos;
			if (!findWordInHashMap(tmpString, 0,pos)) {
				hashElems[pos] = MyWord(tmpString);
				totWord++;
			}
			tmpString.clear();
		}
	}
	return;
}

bool MyHashMap_StoreWithArray::findWordInHashMap(string searchStr, bool isInsearchFunction, int &pos)
{
	pos = hash(searchStr);
	if()
}