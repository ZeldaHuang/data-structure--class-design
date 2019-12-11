#include<iostream>
#include<time.h>
#include<Windows.h>
#include<iomanip>
#include"linearList.h"
#include"Word.h"
#include"BSTree.h"
#define MAXLEN 5000

int main()
{	
	/*string s;
	clock_t start, finish;
	cin >> s;
	cout << "˳���˳����ң�" << endl;
	MyArray a1(0);
	start = clock();
	a1.storeWordsInArray();
	if (a1.findWordInOrder(s, 1)) cout << "�ҵ���" << endl;
	else cout << "û�ҵ�" << endl;
	finish = clock();
	cout << "����ʱ�䣺" << (finish - start) << endl;
	cout << "˳�����ֲ��ң�" << endl;
	MyArray a2(1);
	start = clock();
	a2.storeWordsInArray();
	if (a2.binarysSearch(s)) cout << "�ҵ���" << endl;
	else cout << "û�ҵ�" << endl;
	finish = clock();
	cout << "����ʱ�䣺" << (finish - start)<< endl;
	cout << "������ң�" << endl;
	MyLinkList l;
	start = clock();
	l.storeWordsInList();
	if(l.findWordInOrder(s,1))cout << "�ҵ���" << endl;
	else cout << "û�ҵ�" << endl;
	finish = clock();
	cout << "����ʱ�䣺" << (finish - start)  << endl;
	cout << "�������������ң�" << endl;
	MyBSTree t;
	start = clock();
	t.storeWordsInTree();
	if (t.findWordInTree(s, 1, t.getRoot()))cout << "�ҵ���" << endl;
	else cout << "û�ҵ�" << endl;
	finish = clock();
	cout << "����ʱ�䣺" << (finish - start)  << endl;*/
	MyArray a1(0);
	MyArray a2(1);
	MyLinkList l;
	MyBSTree t;
	a2.storeWordsInArray();
	a1.storeWordsInArray();
	l.storeWordsInList();
	t.storeWordsInTree();

	a1.wordsFilter(10);
	a2.wordsFilter(10);
	l.wordsFilter(10);
	t.wordsFilter(t.getRoot(), NULL, 10);

	a1.storeWordsInOutFile();
	a2.storeWordsInOutFile();
	l.storeWordsInOutFile();
	t.storeWordsInOutFile();
	getchar();
	getchar();
	return 0;
}