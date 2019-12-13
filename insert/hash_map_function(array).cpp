#include<fstream>
#include"Word.h"
#include"HashMap.h"
#include"Sort.h"
#define HASHMAXLEN 3079//�����ϣ��Ϊ�������ٳ�ͻ

void MyHashMap_StoreWithArray::storeWordsInHashMap()
{
	fstream textFile;
	textFile.open("InFile.txt", ios::in);
	if (!textFile) {
        cout << "��ȡʧ��" << endl;//�����쳣
	}
	char words[HASHMAXLEN];
	string tmpString;
	while (textFile.getline(words, HASHMAXLEN))
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
			int cnt = 0;
			if (!findWordInHashMap(tmpString, 0,pos,cnt)) {
				hashElems[pos] = MyWord(tmpString);
				isExist[pos] = 1;
				totWord++;
			}
			tmpString.clear();
		}
	}
	return;
}
int MyHashMap_StoreWithArray::findWordInHashMap(string searchStr, bool isInsearchFunction, int &pos,int &findCnt)
{
	pos = hash(searchStr);
	int cnt = 0;
	while (cnt <= HASHMAXLEN / 2 && isExist[pos])
	{
		findCnt++;
		if (hashElems[pos].getWord() == searchStr) {
			if (!isInsearchFunction) {
				hashElems[pos].addCount();
			}
			return hashElems[pos].getCount();
		}		
		cnt++;
		Collision(pos);	
	}
	return 0;
}
int MyHashMap_StoreWithArray::hash(string key)//ʹ��BKDR��ϣ��������
{
	long long kNum = 0;
	long long  seed = 3;
	for (int i = 0;i < key.length();++i)
	{
		kNum = kNum * seed + key[i];
	}
	return kNum % HASHMAXLEN;
}
void MyHashMap_StoreWithArray::Collision(int &p) //�����ͻ  
{
	p = (p + 1) % HASHMAXLEN; //���ÿ��ŵ�ַ���������̽��  
}
void MyHashMap_StoreWithArray::storeWordsInOutFile()
{
	fstream outFile;
	outFile.open("OutFile5.txt", ios::out);
	if (!outFile) {
		cout << "��ȡʧ��" << endl;//�����쳣
		return;
	}
	MyWord tmpArray[HASHMAXLEN];
	int tot = 0;
	for (int i = 0;i < HASHMAXLEN&&tot<=totWord;++i)
	{
		if (isExist[i]) {
			tmpArray[++tot] = hashElems[i];
		}
	}
	quickSort(tmpArray, 1, tot);
	outFile << totWord << endl;
	for (int i = 1;i <= tot;++i)
	{
		outFile << tmpArray[i].getWord() << " " << tmpArray[i].getCount() << endl;
	}
	outFile.close();
}
void MyHashMap_StoreWithArray::wordsFilter(int filterVal)
{
	for (int i = 0;i < HASHMAXLEN;++i)
	{
		if (isExist[i] && hashElems[i].getCount() <= filterVal) {
			totWord--;
			isExist[i] = 0;
			hashElems[i] = MyWord();
		}
	}
}
