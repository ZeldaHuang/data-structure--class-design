#include"pages.h"
#include"BSTree.h"
#include"linearList.h"
#include"HashMap.h"
#include"Sort.h"
#include"Word.h"
#include<iostream>
#include<time.h>
#include<Windows.h>
#include<string>
using namespace std;

void MyPages::buildMainPage()
{
	cout << "\t\t\t\t/****���ڲ�ͬ���Եĵ���ͳ�ƺͼ���ϵͳ****/" << endl;
	putchar('\n');
	cout << "\t\t\t\t 1.�������Ա�Ĳ���" << endl;
	putchar('\n');
	cout << "\t\t\t\t 2.���ڶ����������Ĳ���" << endl;
	putchar('\n');
	cout << "\t\t\t\t 3.���ڹ�ϣ��Ĳ���" << endl;
	putchar('\n');
	cout << "\t\t\t\t 4.�˳�" << endl;
	char op = '0';
	while (op < '1' || op>'4')
	{
		cout << "��������Ӧ���ֽ���ѡ��";
		cin >> op;
	}
	switch (op)
	{
	case '1':buildLinearPage();
		break;
	case '2':buildFunctionPage_4();
		break;
	case '3':buildHashPage();
		break;
	default:
		break;
	}
	return;
}
void MyPages::buildLinearPage()
{
	cout << "\t\t\t\t/****�������Ա�Ĳ���****/" << endl;
	putchar('\n');
	cout << "\t\t\t\t 1.˳�����" << endl;
	putchar('\n');
	cout << "\t\t\t\t 2.�۰����" << endl;
	putchar('\n');
	cout << "\t\t\t\t 3.����" << endl;
	char op = '0';
	while (op < '1' || op>'3')
	{
		cout << "��������Ӧ���ֽ���ѡ��";
		cin >> op;
	}
	switch (op)
	{
	case '1':
		buildInOrderPage();
		break;
	case '2':
		buildFunctionPage_3();
		break;
	case '3':
		buildMainPage();
		break;
	default:
		break;
	}
}
void MyPages::buildInOrderPage()
{
	cout << "\t\t\t\t/****�������Ա��˳�����****/" << endl;
	putchar('\n');
	cout << "\t\t\t\t 1.����˳���Ĳ���" << endl;
	putchar('\n');
	cout << "\t\t\t\t 2.�����������" << endl;
	putchar('\n');
	cout << "\t\t\t\t 3.����" << endl;
	char op = '0';
	while (op < '1' || op>'3')
	{
		cout << "��������Ӧ���ֽ���ѡ��";
		cin >> op;
	}
	switch (op)
	{
	case '1':
		buildFunctionPage_1();
		break;
	case '2':
		buildFunctionPage_2();
		break;
	case '3':
		buildLinearPage();
		break;
	default:
		break;
	}
}
void MyPages::buildHashPage()
{
	cout << "\t\t\t\t/****���ڹ�ϣ��Ĳ���****/" << endl;
	putchar('\n');
	cout << "\t\t\t\t 1.���ڿ��ŵ�ַ���Ĺ�ϣ����" << endl;
	putchar('\n');
	cout << "\t\t\t\t 2.��������ַ���Ĺ�ϣ����" << endl;
	putchar('\n');
	cout << "\t\t\t\t 3.����" << endl;
	char op = '0';
	while (op < '1' || op>'3')
	{
		cout << "��������Ӧ���ֽ���ѡ��";
		cin >> op;
	}
	switch (op)
	{
	case '1':
		buildFunctionPage_5();
		break;
	case '2':
		buildFunctionPage_6();
		break;
	case '3':
		buildMainPage();
		break;
	default:
		break;
	}
}
void MyPages::buildFunctionPage_1()
{
	MyArray ma;
	cout << "���ڳ�ʼ��..." << endl;
	ma.storeWordsInArray();
	cout << "\t\t\t\t/****����ҳ��****/" << endl;
	putchar('\n');
	cout << "\t\t\t\t 1.��Ƶͳ��" << endl;
	putchar('\n');
	cout << "\t\t\t\t 2.���ʲ���" << endl;
	putchar('\n');
	cout << "\t\t\t\t 3.��Ƶ����" << endl;
	putchar('\n');
	cout << "\t\t\t\t 4.����" << endl;
	char op = '0';
	while (true)
	{
		op = '0';
		while (op < '1' || op>'4')
		{
			cout << "\n��������Ӧ���ֽ���ѡ��";
			cin >> op;
		}
		if (op == '1')
		{
			ma.storeWordsInOutFile();
			cout << "ͳ�Ƴɹ�����������OutFile1!" << endl;
		}
		else if (op == '2')
		{
			string str;
			cout << "����������ҵĵ��ʣ�";
			cin >> str;
			int cnt = 0;
			LARGE_INTEGER lFrequency;//LARGE_INTEGERΪ��������
			QueryPerformanceFrequency(&lFrequency);//��ȡCPU��ʱ��Ƶ��
			LARGE_INTEGER lBeginCount;
			QueryPerformanceCounter(&lBeginCount);//��ȡCPU���������֣����ڼ�ʱ��
			int wordsNum=ma.findWordInOrder(str, 1, cnt);
			LARGE_INTEGER lEndCount;
			QueryPerformanceCounter(&lEndCount);//���CPU���������֣����ڼ�ʱ��
			double runTime = (double)(lEndCount.QuadPart - lBeginCount.QuadPart) / (double)lFrequency.QuadPart;//�õ�����ʱ�䣬��λ��
			if (wordsNum == 0) {
				cout << "����ʧ��!" << endl;
			}
			else {
				cout << "�˵��ʵĴ�ƵΪ��" << wordsNum << endl;
				cout << "���Ҹõ���������ʱ�䣺" << runTime <<"s"<< endl;
				cout << "���ҳ��ȣ�" << cnt << endl;
			}
		}
		else if (op == '3')
		{
			int num;
			cout << "��������˴�Ƶ: ";
			cin >> num;
			ma.wordsFilter(num);
			ma.storeWordsInOutFile();
			cout << "���˳ɹ�����������OutFile1!" << endl;
		}
		else break;
	}
	buildInOrderPage();
}
void MyPages::buildFunctionPage_2()
{
	MyLinkList ml;
	cout << "���ڳ�ʼ��..." << endl;
	ml.storeWordsInList();
	cout << "\t\t\t\t/****����ҳ��****/" << endl;
	putchar('\n');
	cout << "\t\t\t\t 1.��Ƶͳ��" << endl;
	putchar('\n');
	cout << "\t\t\t\t 2.���ʲ���" << endl;
	putchar('\n');
	cout << "\t\t\t\t 3.��Ƶ����" << endl;
	putchar('\n');
	cout << "\t\t\t\t 4.����" << endl;
	char op = '0';
	while (true)
	{
		op = '0';
		while (op < '1' || op>'4')
		{
			cout << "\n��������Ӧ���ֽ���ѡ��";
			cin >> op;
		}
		if (op == '1')
		{
			ml.storeWordsInOutFile();
			cout << "ͳ�Ƴɹ�����������OutFile2!" << endl;
		}
		else if (op == '2')
		{
			string str;
			cout << "����������ҵĵ��ʣ�";
			cin >> str;
			int cnt = 0;
			LARGE_INTEGER lFrequency;//LARGE_INTEGERΪ��������
			QueryPerformanceFrequency(&lFrequency);//��ȡCPU��ʱ��Ƶ��
			LARGE_INTEGER lBeginCount;
			QueryPerformanceCounter(&lBeginCount);//��ȡCPU���������֣����ڼ�ʱ��
			int wordsNum = ml.findWordInOrder(str, 1, cnt);
			LARGE_INTEGER lEndCount;
			QueryPerformanceCounter(&lEndCount);//���CPU���������֣����ڼ�ʱ��
			double runTime = (double)(lEndCount.QuadPart - lBeginCount.QuadPart) / (double)lFrequency.QuadPart;//�õ�����ʱ�䣬��λ��
			if (wordsNum == 0) {
				cout << "����ʧ��!" << endl;
			}
			else {
				cout << "�˵��ʵĴ�ƵΪ��" << wordsNum << endl;
				cout << "���Ҹõ���������ʱ�䣺" << runTime << "s" << endl;
				cout << "���ҳ��ȣ�" << cnt << endl;
			}
		}
		else if (op == '3')
		{
			int num;
			cout << "��������˴�Ƶ: ";
			cin >> num;
			ml.wordsFilter(num);
			ml.storeWordsInOutFile();
			cout << "���˳ɹ�����������OutFile2!" << endl;
		}
		else break;
	}
	buildInOrderPage();
}
void MyPages::buildFunctionPage_3()
{
	MyArray mab;
	mab.binarysSearchMode();
	cout << "���ڳ�ʼ��..." << endl;
	mab.storeWordsInArray();
	cout << "\t\t\t\t/****����ҳ��****/" << endl;
	putchar('\n');
	cout << "\t\t\t\t 1.��Ƶͳ��" << endl;
	putchar('\n');
	cout << "\t\t\t\t 2.���ʲ���" << endl;
	putchar('\n');
	cout << "\t\t\t\t 3.��Ƶ����" << endl;
	putchar('\n');
	cout << "\t\t\t\t 4.����" << endl;
	char op = '0';
	while (true)
	{
		op = '0';
		while (op < '1' || op>'4')
		{
			cout << "\n��������Ӧ���ֽ���ѡ��";
			cin >> op;
		}
		if (op == '1')
		{
			mab.storeWordsInOutFile();
			cout << "ͳ�Ƴɹ�����������OutFile3!" << endl;
		}
		else if (op == '2')
		{
			string str;
			cout << "����������ҵĵ��ʣ�";
			cin >> str;
			int cnt = 0;
			LARGE_INTEGER lFrequency;//LARGE_INTEGERΪ��������
			QueryPerformanceFrequency(&lFrequency);//��ȡCPU��ʱ��Ƶ��
			LARGE_INTEGER lBeginCount;
			QueryPerformanceCounter(&lBeginCount);//��ȡCPU���������֣����ڼ�ʱ��
			int wordsNum = mab.binarysSearch(str, cnt);
			LARGE_INTEGER lEndCount;
			QueryPerformanceCounter(&lEndCount);//���CPU���������֣����ڼ�ʱ��
			double runTime = (double)(lEndCount.QuadPart - lBeginCount.QuadPart) / (double)lFrequency.QuadPart;//�õ�����ʱ�䣬��λ��
			if (wordsNum == 0) {
				cout << "����ʧ��!" << endl;
			}
			else {
				cout << "�˵��ʵĴ�ƵΪ��" << wordsNum << endl;
				cout << "���Ҹõ���������ʱ�䣺" << runTime << "s" << endl;
				cout << "���ҳ��ȣ�" << cnt << endl;
			}
		}
		else if (op == '3')
		{
			int num;
			cout << "��������˴�Ƶ: ";
			cin >> num;
			mab.wordsFilter(num);
			mab.storeWordsInOutFile();
			cout << "���˳ɹ�����������OutFile3!" << endl;
		}
		else break;
	}
	buildLinearPage();
}
void MyPages::buildFunctionPage_4()
{
	MyBSTree mb;
	cout << "���ڳ�ʼ��..." << endl;
	mb.storeWordsInTree();
	cout << "\t\t\t\t/****����ҳ��****/" << endl;
	putchar('\n');
	cout << "\t\t\t\t 1.��Ƶͳ��" << endl;
	putchar('\n');
	cout << "\t\t\t\t 2.���ʲ���" << endl;
	putchar('\n');
	cout << "\t\t\t\t 3.��Ƶ����" << endl;
	putchar('\n');
	cout << "\t\t\t\t 4.����" << endl;
	char op = '0';
	while (true)
	{
		op = '0';
		while (op < '1' || op>'4')
		{
			cout << "\n��������Ӧ���ֽ���ѡ��";
			cin >> op;
		}
		if (op == '1')
		{
			mb.storeWordsInOutFile();
			cout << "ͳ�Ƴɹ�����������OutFile4!" << endl;
		}
		else if (op == '2')
		{
			string str;
			cout << "����������ҵĵ��ʣ�";
			cin >> str;
			int cnt = 0;
			LARGE_INTEGER lFrequency;//LARGE_INTEGERΪ��������
			QueryPerformanceFrequency(&lFrequency);//��ȡCPU��ʱ��Ƶ��
			LARGE_INTEGER lBeginCount;
			QueryPerformanceCounter(&lBeginCount);//��ȡCPU���������֣����ڼ�ʱ��
			int wordsNum = mb.findWordInTree(str,1,mb.getRoot(),cnt);
			LARGE_INTEGER lEndCount;
			QueryPerformanceCounter(&lEndCount);//���CPU���������֣����ڼ�ʱ��
			double runTime = (double)(lEndCount.QuadPart - lBeginCount.QuadPart) / (double)lFrequency.QuadPart;//�õ�����ʱ�䣬��λ��
			if (wordsNum == 0) {
				cout << "����ʧ��!" << endl;
			}
			else {
				cout << "�˵��ʵĴ�ƵΪ��" << wordsNum << endl;
				cout << "���Ҹõ���������ʱ�䣺" << runTime << "s" << endl;
				cout << "���ҳ��ȣ�" << cnt << endl;
			}
		}
		else if (op == '3')
		{
			int num;
			cout << "��������˴�Ƶ: ";
			cin >> num;
			mb.wordsFilter(mb.getRoot(),NULL,num);
			mb.storeWordsInOutFile();
			cout << "���˳ɹ�����������OutFile4!" << endl;
		}
		else break;
	}
	buildMainPage();
}
void MyPages::buildFunctionPage_5()
{
	MyHashMap_StoreWithArray hash1;
	cout << "���ڳ�ʼ��..." << endl;
	hash1.storeWordsInHashMap();
	cout << "\t\t\t\t/****����ҳ��****/" << endl;
	putchar('\n');
	cout << "\t\t\t\t 1.��Ƶͳ��" << endl;
	putchar('\n');
	cout << "\t\t\t\t 2.���ʲ���" << endl;
	putchar('\n');
	cout << "\t\t\t\t 3.��Ƶ����" << endl;
	putchar('\n');
	cout << "\t\t\t\t 4.����" << endl;
	char op = '0';
	while (true)
	{
		op = '0';
		while (op < '1' || op>'4')
		{
			cout << "\n��������Ӧ���ֽ���ѡ��";
			cin >> op;
		}
		if (op == '1')
		{
			hash1.storeWordsInOutFile();
			cout << "ͳ�Ƴɹ�����������OutFile5!" << endl;
		}
		else if (op == '2')
		{
			string str;
			cout << "����������ҵĵ��ʣ�";
			cin >> str;
			int cnt = 0;
			LARGE_INTEGER lFrequency;//LARGE_INTEGERΪ��������
			QueryPerformanceFrequency(&lFrequency);//��ȡCPU��ʱ��Ƶ��
			LARGE_INTEGER lBeginCount;
			QueryPerformanceCounter(&lBeginCount);//��ȡCPU���������֣����ڼ�ʱ��
			int pos = 0;
			int wordsNum = hash1.findWordInHashMap(str, 1, pos, cnt);
			LARGE_INTEGER lEndCount;
			QueryPerformanceCounter(&lEndCount);//���CPU���������֣����ڼ�ʱ��
			double runTime = (double)(lEndCount.QuadPart - lBeginCount.QuadPart) / (double)lFrequency.QuadPart;//�õ�����ʱ�䣬��λ��
			if (wordsNum == 0) {
				cout << "����ʧ��!" << endl;
			}
			else {
				cout << "�˵��ʵĴ�ƵΪ��" << wordsNum << endl;
				cout << "���Ҹõ���������ʱ�䣺" << runTime << "s" << endl;
				cout << "���ҳ��ȣ�" << cnt << endl;
			}
		}
		else if (op == '3')
		{
			int num;
			cout << "��������˴�Ƶ: ";
			cin >> num;
			hash1.wordsFilter(num);
			hash1.storeWordsInOutFile();
			cout << "���˳ɹ�����������OutFile5!" << endl;
		}
		else break;
	}
	buildHashPage();
}
void MyPages::buildFunctionPage_6()
{
	MyHashMap_StoreWithLinkList hash2;
	cout << "���ڳ�ʼ��..." << endl;
	hash2.storeWordsInHashMap();
	cout << "\t\t\t\t/****����ҳ��****/" << endl;
	putchar('\n');
	cout << "\t\t\t\t 1.��Ƶͳ��" << endl;
	putchar('\n');
	cout << "\t\t\t\t 2.���ʲ���" << endl;
	putchar('\n');
	cout << "\t\t\t\t 3.��Ƶ����" << endl;
	putchar('\n');
	cout << "\t\t\t\t 4.����" << endl;
	char op = '0';
	while (true)
	{
		op = '0';
		while (op < '1' || op>'4')
		{
			cout << "\n��������Ӧ���ֽ���ѡ��";
			cin >> op;
		}
		if (op == '1')
		{
			hash2.storeWordsInOutFile();
			cout << "ͳ�Ƴɹ�����������OutFile6!" << endl;
		}
		else if (op == '2')
		{
			string str;
			cout << "����������ҵĵ��ʣ�";
			cin >> str;
			int cnt = 0;
			LARGE_INTEGER lFrequency;//LARGE_INTEGERΪ��������
			QueryPerformanceFrequency(&lFrequency);//��ȡCPU��ʱ��Ƶ��
			LARGE_INTEGER lBeginCount;
			QueryPerformanceCounter(&lBeginCount);//��ȡCPU���������֣����ڼ�ʱ��
			int wordsNum = hash2.findWordInHashMap(str, 1, cnt);
			LARGE_INTEGER lEndCount;
			QueryPerformanceCounter(&lEndCount);//���CPU���������֣����ڼ�ʱ��
			double runTime = (double)(lEndCount.QuadPart - lBeginCount.QuadPart) / (double)lFrequency.QuadPart;//�õ�����ʱ�䣬��λ��
			if (wordsNum == 0) {
				cout << "����ʧ��!" << endl;
			}
			else {
				cout << "�˵��ʵĴ�ƵΪ��" << wordsNum << endl;
				cout << "���Ҹõ���������ʱ�䣺" << runTime << "s" << endl;
				cout << "���ҳ��ȣ�" << cnt << endl;
			}
		}
		else if (op == '3')
		{
			int num;
			cout << "��������˴�Ƶ: ";
			cin >> num;
			hash2.wordsFilter(num);
			hash2.storeWordsInOutFile();
			cout << "���˳ɹ�����������OutFile6!" << endl;
		}
		else break;
	}
	buildHashPage();
}