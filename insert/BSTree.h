#pragma once
#ifndef BSTREE_H
#define BSTREE_H
#include"Word.h"
struct BiNode
{
	MyWord data;
	BiNode *lchild, *rchild;
	BiNode() {
		lchild = NULL, rchild = NULL;
	}
};
class MyBSTree:protected MyWord
{
public:
	MyBSTree() :root(NULL), totWord(0) {}

	void storeWordsInTree();

	bool findWordInTree(string &searchStr, bool isInsearchFunction,BiNode *ptr);

	void storeWordsInOutFile();

	~MyBSTree() {
		destroyTree(root);
	}

private:
	BiNode *root;
	int totWord;
	void destroyTree(BiNode *ptr);//ɾ��������
	void getWordsInLine(char *str);
	void locatePosInTree(string &insertStr, BiNode *ptr);//��λ����ڵ�λ��
	void insertWordInTree(string &insertStr, BiNode *&posPtr);//�ڶ�Ӧλ���ϲ���ڵ�
	void ldrTree(BiNode *ptr, ostream &os);//����������������ֵ������
};

#endif // !BSTREE_H
