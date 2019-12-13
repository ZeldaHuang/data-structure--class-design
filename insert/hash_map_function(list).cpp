#include<fstream>
#include"Word.h"
#include"HashMap.h"
#include"linearList.h"
#include"Sort.h"
#define HASHMAXLEN 3079//定义哈希表长为素数减少冲突

void MyHashMap_StoreWithLinkList::storeWordsInHashMap()
{
	fstream textFile;
	textFile.open("InFile.txt", ios::in);
	if (!textFile) {
		cout << "读取失败" << endl;//处理异常
	}
	char words[HASHMAXLEN];
	string tmpString;
	while (textFile.getline(words, HASHMAXLEN))
	{
		getWordsInLine(words, tmpString);
	}
	textFile.close();
}
void MyHashMap_StoreWithLinkList::storeWordsInOutFile()
{
	fstream outFile;
	outFile.open("OutFile6.txt", ios::out);
	if (!outFile) {
		cout << "读取失败" << endl;//处理异常
		return;
	}
	outFile << totWord << endl;
	/*MyHashMap_StoreWithLinkList sortedHashMap = *this;//归并
	sortedHashMap.totWord = totWord;
	for (int i = 0;i < HASHMAXLEN;++i)
	{
		sortedHashMap.hashElems[i].head=sortList(sortedHashMap.hashElems[i].head);
	}
	for (int i = 1;i < HASHMAXLEN;++i)
	{
		sortedHashMap.hashElems[0].head=mergeList(sortedHashMap.hashElems[0].head, sortedHashMap.hashElems[i].head);
	}
	Node *ptr = sortedHashMap.hashElems[0].head;
	while (ptr!=NULL)
	{
		outFile << ptr->data.getWord() << " " << ptr->data.getCount() << endl;
		ptr = ptr->next;
	}*/
	MyWord tmpa[MAXLEN];
	int tot = 0;
	for (int i = 0;i < MAXLEN;++i)
	{
		Node *ptr = hashElems[i].head;
		while (ptr != NULL)
		{
			tmpa[++tot] = ptr->data;
			ptr = ptr->next;
		}
	}
	quickSort(tmpa, 1, tot);
	for (int i = 1;i <= tot;++i)
	{
		outFile << tmpa[i].getWord() << " " << tmpa[i].getCount() << endl;
	}
	outFile.close();
}
void MyHashMap_StoreWithLinkList::getWordsInLine(char *str, string &tmpString)
{
	if (tmpString == "-") tmpString.clear();
	for (int i = 0;i < strlen(str);++i)
	{
		if (isalpha(static_cast<unsigned char>(str[i])) || str[i] == '-' || str[i] == 39) {
			if (tmpString == "-") tmpString.clear();
			tmpString += tolower(str[i]);
		}
		else if (!tmpString.empty() && tmpString[tmpString.length() - 1] != '-') {
			int cnt = 0;
			if (!findWordInHashMap(tmpString, 0,cnt)) {
				insertWordInHashMap(tmpString);
				totWord++;
			}
			tmpString.clear();
		}
	}
	return;
}
void MyHashMap_StoreWithLinkList::insertWordInHashMap(string &
	str)//头插法
{
	int pos = hash(str);
	Node *insertPtr = new Node;
	insertPtr->data = MyWord(str);
	hashElems[pos].length++;
	insertPtr->next = hashElems[pos].head;
	hashElems[pos].head = insertPtr;
}
int MyHashMap_StoreWithLinkList::findWordInHashMap(string searchStr, bool isInsearchFunction,int &findCnt)
{
	int pos = hash(searchStr);
	Node *searchPtr = hashElems[pos].head;
	while (searchPtr!=NULL)
	{
		findCnt++;
		if (searchPtr->data.getWord() == searchStr) {
			if (!isInsearchFunction) {
				searchPtr->data.addCount();
			}
			return searchPtr->data.getCount();
		}
		searchPtr = searchPtr->next;
	}
	return 0;
}
int MyHashMap_StoreWithLinkList::hash(string key)
{
	long long kNum = 0;
	long long  seed = 3;
	for (int i = 0;i < key.length();++i)
	{
		kNum = kNum * seed + key[i];
	}
	return kNum % HASHMAXLEN;
}
MyHashMap_StoreWithLinkList& MyHashMap_StoreWithLinkList::operator=(MyHashMap_StoreWithLinkList &tmpHashMap)
{
	for (int i = 0;i < HASHMAXLEN;++i)
	{
		hashElems[i].length = tmpHashMap.hashElems[i].length;
		Node *ptr = tmpHashMap.hashElems[i].head;
		while (ptr!=NULL)
		{
			Node *newPtr = new Node;
			newPtr->data = ptr->data;
			newPtr->next = hashElems[i].head;
			hashElems[i].head=newPtr;
			ptr = ptr->next;
		}
	}
	return *this;
}
void MyHashMap_StoreWithLinkList::wordsFilter(int filterVal)
{
	for (int i = 0;i < HASHMAXLEN;++i)
	{
		Node *ptr = hashElems[i].head;
		Node *prePtr = NULL;
		while (ptr != NULL)
		{
			if (ptr->data.getCount() <= filterVal) {//从链表上删除节点
				if (prePtr == NULL) {
					hashElems[i].head = ptr->next;
				}
				else {
					prePtr->next = ptr->next;
				}
				Node *delPtr = ptr;
				ptr = ptr->next;
				delete delPtr;
				totWord--;
			}
			else {
				prePtr = ptr;
				ptr = ptr->next;
			}
		}
	}
}