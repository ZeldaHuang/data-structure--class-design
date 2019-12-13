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

	void wordsFilter(BiNode *ptr, BiNode *faPtr, int filterNum);

	BiNode *getRoot() { return root; }

	~MyBSTree() {
		destroyTree(root);
	}

private:
	BiNode *root;
	int totWord;
	void destroyTree(BiNode *ptr);//删除整棵树
	void getWordsInLine(char *str, string &tmpString);
	void locatePosInTree(string &insertStr, BiNode *ptr);//定位插入节点位置
	void insertWordInTree(string &insertStr, BiNode *&posPtr);//在对应位置上插入节点
	void ldrTree(BiNode *ptr, ostream &os);//中序遍历二叉树按字典序输出
};

#endif // !BSTREE_H
