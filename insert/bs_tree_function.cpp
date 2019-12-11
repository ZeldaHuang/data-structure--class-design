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
void MyBSTree::wordsFilter(BiNode *ptr,BiNode *faPtr,int filterNum) //时间复杂度o（(log n)^2）
{
	if (ptr == NULL) return;
	wordsFilter(ptr->lchild, ptr, filterNum);
	wordsFilter(ptr->rchild, ptr, filterNum);
	if (ptr->data.getCount() <= filterNum)//删除二叉排序树上节点操作
	{
		totWord--;
		if ( ptr->lchild == NULL && ptr->rchild == NULL) 
		{
			if (faPtr != NULL && faPtr->lchild == ptr) {
				faPtr->lchild = NULL;
			}
			else if (faPtr != NULL && faPtr->rchild == ptr) {
				faPtr->rchild = NULL;
			}
			else {//删除只有一个节点的二叉排序树的情况
				root = NULL;
			}
		}
		else if(ptr->lchild!=NULL&&ptr->rchild!=NULL)//删除节点包含两个子节点
		{
			BiNode *replacePtr = ptr->lchild;
			BiNode *replaceFaPtr = ptr;
			while (replacePtr->rchild != NULL) {//向左子树中寻找最大值节点作为代替节点，不破坏二叉排序树的结构
				replacePtr = replacePtr->rchild;
			}
			if (replaceFaPtr->lchild != replacePtr) {//代替节点不是删除节点的子节点，找到父节点后置空。
				replaceFaPtr = replaceFaPtr->lchild;
				while (replaceFaPtr->rchild != replacePtr) {
					replaceFaPtr = replaceFaPtr->rchild;
				}				
				replaceFaPtr->rchild = replacePtr->lchild;
				replacePtr->rchild =ptr->rchild;//代替节点继承删除节点的左右子树
				replacePtr->lchild = ptr->lchild;
			}
			else {//代替节点时删除节点的子节点，那么删除节点左子树只有一个节点（代替节点),仅继承右节点即可
				replacePtr->rchild = ptr->rchild;
			}

			if (faPtr == NULL) {//删除节点为根节点
				root = replacePtr;
			}
			else if (faPtr->lchild == ptr) {//删除节点的父节点更换子树
				faPtr->lchild = replacePtr;
			}
			else if(faPtr->rchild==ptr){
				faPtr->rchild = replacePtr;
			}
		}
		else//删除节点只有一个子节点
		{
			if (faPtr == NULL) {
				if (ptr->lchild != NULL) {
					root = ptr->lchild;
				}
				else {
					root = ptr->rchild;
				}
			}
			else if (faPtr->lchild==ptr) {
				if (ptr->lchild != NULL) {
					faPtr->lchild = ptr->lchild;
				}
				else {
					faPtr->lchild = ptr->rchild;
				}
			}
			else {
				if (ptr->lchild != NULL) {
					faPtr->rchild = ptr->lchild;
				}
				else {
					faPtr->rchild = ptr->rchild;
				}
			}
		}
		delete ptr;
	}
}