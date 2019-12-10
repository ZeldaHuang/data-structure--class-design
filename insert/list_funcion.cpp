#include<fstream>
#include"linearList.h"
#include"Sort.h"
#include"Word.h"

void MyLinkList::storeWordsInList()
{
	fstream textFile;
	textFile.open("InFile.txt", ios::in);
	if (!textFile) {
		cout << "��ȡʧ��" << endl;//�����쳣
	}
	char words[MAXLEN];
	while (textFile.getline(words, MAXLEN))
	{
		getWordsInLine(words);
	}
	textFile.close();
}
void MyLinkList::storeWordsInOutFile_1()
{
	MyLinkList wordsInOrder;
	wordsInOrder = *this;
	Node *sortHead=wordsInOrder.getHead();
	sortHead=sortList(sortHead);
	fstream outFile;
	outFile.open("OutFile2.txt", ios::out);
	if (!outFile) {
		cout << "��ȡʧ��" << endl;//�����쳣
		return;
	}
	outFile << totWord << endl;
	while (sortHead != NULL)
	{
		//cout << sortHead->data.getWord() <<" " <<sortHead->data.getCount() << endl;
		outFile << sortHead->data.getWord() << " " << sortHead->data.getCount() << endl;
		sortHead = sortHead->next;
	}
	outFile.close();
}
void MyLinkList::getWordsInLine(char *str)
{
	string tmpString;
	for (int i = 0;i < strlen(str);++i)
	{
		if (isalpha(str[i]) || str[i] == '-' || str[i] == 39) {
			tmpString += tolower(str[i]);
		}
		else if (!tmpString.empty()) {
			if (!findWordInOrder(tmpString, 0)) {
				tailInsert(tmpString);
			}
			tmpString.clear();
		}
	}
	return;
}
void MyLinkList::tailInsert(string insertStr)//β�巨��������
{
	Node *insertPtr = new Node;
	insertPtr->data = MyWord(insertStr);
	insertPtr->next = NULL;
	totWord++;
	if (head == NULL) {
		head = tail = insertPtr;
	}
	else {
		tail->next = insertPtr;
		tail = insertPtr;
	}
}

bool MyLinkList::findWordInOrder(string searchStr, bool isInsearchFunction)
{
	Node *findPtr = head;
	while (findPtr != NULL)
	{
		if (findPtr->data.getWord() == searchStr) {
			if (!isInsearchFunction) {
				findPtr->data.addCount();
			}
			return true;
		}
		findPtr = findPtr->next;
	}
	return false;
}

MyLinkList& MyLinkList::operator=(MyLinkList &tmpList)
{
	Node *copyPtr = tmpList.head;
	while (!copyPtr == NULL)
	{
		Node *ptr = new Node;
		ptr->data = copyPtr->data;
		ptr->next = NULL;
		totWord++;
		if (head == NULL) {
			head = tail = ptr;
		}
		else {
			tail->next = ptr;
			tail = ptr;
		}
		copyPtr = copyPtr->next;
	}
	return *this;
}
