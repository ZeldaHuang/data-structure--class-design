#include<fstream>
#include"Word.h"
#include"BSTree.h"
#include"Sort.h"
void MyBSTree::storeWordsInTree()
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
			int cnt = 0;
			if (!findWordInTree(tmpString, 0,root,cnt)) {
				locatePosInTree(tmpString,root);
				totWord++;
			}
			tmpString.clear();
		}
	}
	return;
}
int MyBSTree::findWordInTree(string &searchStr, bool isInsearchFunction,BiNode *ptr,int &cnt)
{
	if (ptr == NULL) return 0;
	cnt++;
	if (ptr->data.getWord() == searchStr) {
		if (!isInsearchFunction) {
			ptr->data.addCount();
		}
		return ptr->data.getCount();
	}
	else if (ptr->data.getWord() > searchStr) {
		return findWordInTree(searchStr, isInsearchFunction, ptr->lchild,cnt);
	}
	else {
		return findWordInTree(searchStr, isInsearchFunction, ptr->rchild,cnt);
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
		cout << "��ȡʧ��" << endl;//�����쳣
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
void MyBSTree::wordsFilter(BiNode *ptr,BiNode *faPtr,int filterNum) //ʱ�临�Ӷ�o��(log n)^2��
{
	if (ptr == NULL) return;
	wordsFilter(ptr->lchild, ptr, filterNum);
	wordsFilter(ptr->rchild, ptr, filterNum);
	if (ptr->data.getCount() <= filterNum)//ɾ�������������Ͻڵ����
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
			else {//ɾ��ֻ��һ���ڵ�Ķ��������������
				root = NULL;
			}
		}
		else if(ptr->lchild!=NULL&&ptr->rchild!=NULL)//ɾ���ڵ���������ӽڵ�
		{
			BiNode *replacePtr = ptr->lchild;
			BiNode *replaceFaPtr = ptr;
			while (replacePtr->rchild != NULL) {//����������Ѱ�����ֵ�ڵ���Ϊ����ڵ㣬���ƻ������������Ľṹ
				replacePtr = replacePtr->rchild;
			}
			if (replaceFaPtr->lchild != replacePtr) {//����ڵ㲻��ɾ���ڵ���ӽڵ㣬�ҵ����ڵ���ÿա�
				replaceFaPtr = replaceFaPtr->lchild;
				while (replaceFaPtr->rchild != replacePtr) {
					replaceFaPtr = replaceFaPtr->rchild;
				}				
				replaceFaPtr->rchild = replacePtr->lchild;
				replacePtr->rchild =ptr->rchild;//����ڵ�̳�ɾ���ڵ����������
				replacePtr->lchild = ptr->lchild;
			}
			else {//����ڵ�ʱɾ���ڵ���ӽڵ㣬��ôɾ���ڵ�������ֻ��һ���ڵ㣨����ڵ�),���̳��ҽڵ㼴��
				replacePtr->rchild = ptr->rchild;
			}

			if (faPtr == NULL) {//ɾ���ڵ�Ϊ���ڵ�
				root = replacePtr;
			}
			else if (faPtr->lchild == ptr) {//ɾ���ڵ�ĸ��ڵ��������
				faPtr->lchild = replacePtr;
			}
			else if(faPtr->rchild==ptr){
				faPtr->rchild = replacePtr;
			}
		}
		else//ɾ���ڵ�ֻ��һ���ӽڵ�
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
