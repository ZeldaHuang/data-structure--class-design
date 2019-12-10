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
	string tmpString;
	while (textFile.getline(words, MAXLEN))
	{
		getWordsInLine(words,tmpString);
	}
	textFile.close();
}
void MyLinkList::storeWordsInOutFile()
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
void MyLinkList::getWordsInLine(char *str,string &tmpString)
{
	if (tmpString == "-") tmpString.clear();
	for (int i = 0;i < strlen(str);++i)
	{
		if (isalpha(static_cast<unsigned char>(str[i])) || str[i] == '-' || str[i] == 39) {
			if (tmpString == "-") tmpString.clear();
			tmpString += tolower(str[i]);
		}
		else if (!tmpString.empty() && tmpString[tmpString.length() - 1] != '-') {
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
void MyLinkList::wordsFilter(int filterVal)
{
	Node *ptr = head,*prePtr=NULL;
	while (ptr != NULL)
	{
		if (ptr->data.getCount() <= filterVal) {
			if (prePtr != NULL) {
				prePtr->next = ptr->next;
			}
			Node *delPtr = ptr;
			if (delPtr == head) {
				head = delPtr->next;
			}
			else if (delPtr == tail) {
				tail = NULL;
			}
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