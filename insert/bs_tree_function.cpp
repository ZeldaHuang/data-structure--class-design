#include<fstream>
#include"Word.h"
#include"BSTree.h"
#include"Sort.h"
#define MAXLEN 5000

void MyBSTree::storeWordsInTree()
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
		getWordsInLine(words,tmpString);
	}
	textFile.close();
}
void MyBSTree::getWordsInLine(char *str, string &tmpString)
{
	if (tmpString == "-") tmpString.clear();
	for (int i = 0;i < strlen(str);++i)
	{
		if (isalpha(static_cast<unsigned char>(str[i])) || str[i] == '-' || str[i] == 39) {
			if (tmpString == "-") tmpString.clear();
			tmpString += tolower(str[i]);
		}
		else if (!tmpString.empty() && tmpString[tmpString.length() - 1] != '-') {
			if (!findWordInTree(tmpString, 0,root)) {
				locatePosInTree(tmpString,root);
				totWord++;
			}
			tmpString.clear();
		}
	}
	return;
}
bool MyBSTree::findWordInTree(string &searchStr, bool isInsearchFunction,BiNode *ptr)
{
	if (ptr == NULL) return false;
	if (ptr->data.getWord() == searchStr) {
		if (!isInsearchFunction) {
			ptr->data.addCount();
		}
		return true;
	}
	else if (ptr->data.getWord() > searchStr) {
		return findWordInTree(searchStr, isInsearchFunction, ptr->lchild);
	}
	else {
		return findWordInTree(searchStr, isInsearchFunction, ptr->rchild);
	}
}
void MyBSTree::locatePosInTree(string &insertStr, BiNode *ptr)
{
	if (ptr == NULL) {
		insertWordInTree(insertStr, root);
	}
	else if (insertStr > ptr->data.getWord()) {
		if (ptr->rchild == NULL) {
			insertWordInTree(insertStr, ptr->rchild);
		}
		else {
			locatePosInTree(insertStr, ptr->rchild);
		}
	}
	else {
		if (ptr->lchild == NULL) {
			insertWordInTree(insertStr, ptr->lchild);
		}
		else {
			locatePosInTree(insertStr, ptr->lchild);
		}
	}
}
void MyBSTree::insertWordInTree(string &insertStr, BiNode *&posPtr)
{
	BiNode *insertPtr = new BiNode;
	insertPtr->data = MyWord(insertStr);
	posPtr = insertPtr;
}
void MyBSTree::storeWordsInOutFile()
{
	fstream outFile;
	outFile.open("OutFile4.txt", ios::out);
	if (!outFile) {
		cout << "读取失败" << endl;//处理异常
		return;
	}
	outFile << totWord << endl;
	ldrTree(root,outFile);
	outFile.close();
}
void MyBSTree::ldrTree(BiNode *ptr, ostream &os)
{
	if (ptr == NULL) return;
	ldrTree(ptr->lchild,os);
	os << ptr->data.getWord() << " " << ptr->data.getCount() << endl;
	ldrTree(ptr->rchild, os);
	return;
}
void MyBSTree::destroyTree(BiNode *ptr)
{
	if (ptr == NULL) return;
	if (ptr->lchild != NULL) {
		destroyTree(ptr->lchild);
	}
	if (ptr->rchild != NULL) {
		destroyTree(ptr->rchild);
	}
	delete ptr;
}

void MyBSTree::wordsFilter(BiNode *ptr,BiNode *faPtr,int filterNum)
{
	if (ptr == NULL) return;
	wordsFilter(ptr->lchild,ptr,filterNum);
	wordsFilter(ptr->rchild, ptr,filterNum);
	if (ptr->data.getCount() <= filterNum);
}