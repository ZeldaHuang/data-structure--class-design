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
	cout << "\t\t\t\t/****基于不同策略的单词统计和检索系统****/" << endl;
	putchar('\n');
	cout << "\t\t\t\t 1.基于线性表的查找" << endl;
	putchar('\n');
	cout << "\t\t\t\t 2.基于二叉排序树的查找" << endl;
	putchar('\n');
	cout << "\t\t\t\t 3.基于哈希表的查找" << endl;
	putchar('\n');
	cout << "\t\t\t\t 4.退出" << endl;
	char op = '0';
	while (op < '1' || op>'4')
	{
		cout << "请输入相应数字进行选择：";
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
	cout << "\t\t\t\t/****基于线性表的查找****/" << endl;
	putchar('\n');
	cout << "\t\t\t\t 1.顺序查找" << endl;
	putchar('\n');
	cout << "\t\t\t\t 2.折半查找" << endl;
	putchar('\n');
	cout << "\t\t\t\t 3.返回" << endl;
	char op = '0';
	while (op < '1' || op>'3')
	{
		cout << "请输入相应数字进行选择：";
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
	cout << "\t\t\t\t/****基于线性表的顺序查找****/" << endl;
	putchar('\n');
	cout << "\t\t\t\t 1.基于顺序表的查找" << endl;
	putchar('\n');
	cout << "\t\t\t\t 2.基于链表查找" << endl;
	putchar('\n');
	cout << "\t\t\t\t 3.返回" << endl;
	char op = '0';
	while (op < '1' || op>'3')
	{
		cout << "请输入相应数字进行选择：";
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
	cout << "\t\t\t\t/****基于哈希表的查找****/" << endl;
	putchar('\n');
	cout << "\t\t\t\t 1.基于开放地址法的哈希查找" << endl;
	putchar('\n');
	cout << "\t\t\t\t 2.基于链地址法的哈希查找" << endl;
	putchar('\n');
	cout << "\t\t\t\t 3.返回" << endl;
	char op = '0';
	while (op < '1' || op>'3')
	{
		cout << "请输入相应数字进行选择：";
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
	cout << "正在初始化..." << endl;
	ma.storeWordsInArray();
	cout << "\t\t\t\t/****功能页面****/" << endl;
	putchar('\n');
	cout << "\t\t\t\t 1.词频统计" << endl;
	putchar('\n');
	cout << "\t\t\t\t 2.单词查找" << endl;
	putchar('\n');
	cout << "\t\t\t\t 3.词频过滤" << endl;
	putchar('\n');
	cout << "\t\t\t\t 4.返回" << endl;
	char op = '0';
	while (true)
	{
		op = '0';
		while (op < '1' || op>'4')
		{
			cout << "\n请输入相应数字进行选择：";
			cin >> op;
		}
		if (op == '1')
		{
			ma.storeWordsInOutFile();
			cout << "统计成功，结果输出至OutFile1!" << endl;
		}
		else if (op == '2')
		{
			string str;
			cout << "请输入待查找的单词：";
			cin >> str;
			int cnt = 0;
			LARGE_INTEGER lFrequency;//LARGE_INTEGER为数据类型
			QueryPerformanceFrequency(&lFrequency);//获取CPU的时钟频率
			LARGE_INTEGER lBeginCount;
			QueryPerformanceCounter(&lBeginCount);//获取CPU计数器数字，放在计时开
			int wordsNum=ma.findWordInOrder(str, 1, cnt);
			LARGE_INTEGER lEndCount;
			QueryPerformanceCounter(&lEndCount);//获得CPU计数器数字，放在计时结
			double runTime = (double)(lEndCount.QuadPart - lBeginCount.QuadPart) / (double)lFrequency.QuadPart;//得到运行时间，单位秒
			if (wordsNum == 0) {
				cout << "查找失败!" << endl;
			}
			else {
				cout << "此单词的词频为：" << wordsNum << endl;
				cout << "查找该单词所花的时间：" << runTime <<"s"<< endl;
				cout << "查找长度：" << cnt << endl;
			}
		}
		else if (op == '3')
		{
			int num;
			cout << "请输入过滤词频: ";
			cin >> num;
			ma.wordsFilter(num);
			ma.storeWordsInOutFile();
			cout << "过滤成功，结果输出至OutFile1!" << endl;
		}
		else break;
	}
	buildInOrderPage();
}
void MyPages::buildFunctionPage_2()
{
	MyLinkList ml;
	cout << "正在初始化..." << endl;
	ml.storeWordsInList();
	cout << "\t\t\t\t/****功能页面****/" << endl;
	putchar('\n');
	cout << "\t\t\t\t 1.词频统计" << endl;
	putchar('\n');
	cout << "\t\t\t\t 2.单词查找" << endl;
	putchar('\n');
	cout << "\t\t\t\t 3.词频过滤" << endl;
	putchar('\n');
	cout << "\t\t\t\t 4.返回" << endl;
	char op = '0';
	while (true)
	{
		op = '0';
		while (op < '1' || op>'4')
		{
			cout << "\n请输入相应数字进行选择：";
			cin >> op;
		}
		if (op == '1')
		{
			ml.storeWordsInOutFile();
			cout << "统计成功，结果输出至OutFile2!" << endl;
		}
		else if (op == '2')
		{
			string str;
			cout << "请输入待查找的单词：";
			cin >> str;
			int cnt = 0;
			LARGE_INTEGER lFrequency;//LARGE_INTEGER为数据类型
			QueryPerformanceFrequency(&lFrequency);//获取CPU的时钟频率
			LARGE_INTEGER lBeginCount;
			QueryPerformanceCounter(&lBeginCount);//获取CPU计数器数字，放在计时开
			int wordsNum = ml.findWordInOrder(str, 1, cnt);
			LARGE_INTEGER lEndCount;
			QueryPerformanceCounter(&lEndCount);//获得CPU计数器数字，放在计时结
			double runTime = (double)(lEndCount.QuadPart - lBeginCount.QuadPart) / (double)lFrequency.QuadPart;//得到运行时间，单位秒
			if (wordsNum == 0) {
				cout << "查找失败!" << endl;
			}
			else {
				cout << "此单词的词频为：" << wordsNum << endl;
				cout << "查找该单词所花的时间：" << runTime << "s" << endl;
				cout << "查找长度：" << cnt << endl;
			}
		}
		else if (op == '3')
		{
			int num;
			cout << "请输入过滤词频: ";
			cin >> num;
			ml.wordsFilter(num);
			ml.storeWordsInOutFile();
			cout << "过滤成功，结果输出至OutFile2!" << endl;
		}
		else break;
	}
	buildInOrderPage();
}
void MyPages::buildFunctionPage_3()
{
	MyArray mab;
	mab.binarysSearchMode();
	cout << "正在初始化..." << endl;
	mab.storeWordsInArray();
	cout << "\t\t\t\t/****功能页面****/" << endl;
	putchar('\n');
	cout << "\t\t\t\t 1.词频统计" << endl;
	putchar('\n');
	cout << "\t\t\t\t 2.单词查找" << endl;
	putchar('\n');
	cout << "\t\t\t\t 3.词频过滤" << endl;
	putchar('\n');
	cout << "\t\t\t\t 4.返回" << endl;
	char op = '0';
	while (true)
	{
		op = '0';
		while (op < '1' || op>'4')
		{
			cout << "\n请输入相应数字进行选择：";
			cin >> op;
		}
		if (op == '1')
		{
			mab.storeWordsInOutFile();
			cout << "统计成功，结果输出至OutFile3!" << endl;
		}
		else if (op == '2')
		{
			string str;
			cout << "请输入待查找的单词：";
			cin >> str;
			int cnt = 0;
			LARGE_INTEGER lFrequency;//LARGE_INTEGER为数据类型
			QueryPerformanceFrequency(&lFrequency);//获取CPU的时钟频率
			LARGE_INTEGER lBeginCount;
			QueryPerformanceCounter(&lBeginCount);//获取CPU计数器数字，放在计时开
			int wordsNum = mab.binarysSearch(str, cnt);
			LARGE_INTEGER lEndCount;
			QueryPerformanceCounter(&lEndCount);//获得CPU计数器数字，放在计时结
			double runTime = (double)(lEndCount.QuadPart - lBeginCount.QuadPart) / (double)lFrequency.QuadPart;//得到运行时间，单位秒
			if (wordsNum == 0) {
				cout << "查找失败!" << endl;
			}
			else {
				cout << "此单词的词频为：" << wordsNum << endl;
				cout << "查找该单词所花的时间：" << runTime << "s" << endl;
				cout << "查找长度：" << cnt << endl;
			}
		}
		else if (op == '3')
		{
			int num;
			cout << "请输入过滤词频: ";
			cin >> num;
			mab.wordsFilter(num);
			mab.storeWordsInOutFile();
			cout << "过滤成功，结果输出至OutFile3!" << endl;
		}
		else break;
	}
	buildLinearPage();
}
void MyPages::buildFunctionPage_4()
{
	MyBSTree mb;
	cout << "正在初始化..." << endl;
	mb.storeWordsInTree();
	cout << "\t\t\t\t/****功能页面****/" << endl;
	putchar('\n');
	cout << "\t\t\t\t 1.词频统计" << endl;
	putchar('\n');
	cout << "\t\t\t\t 2.单词查找" << endl;
	putchar('\n');
	cout << "\t\t\t\t 3.词频过滤" << endl;
	putchar('\n');
	cout << "\t\t\t\t 4.返回" << endl;
	char op = '0';
	while (true)
	{
		op = '0';
		while (op < '1' || op>'4')
		{
			cout << "\n请输入相应数字进行选择：";
			cin >> op;
		}
		if (op == '1')
		{
			mb.storeWordsInOutFile();
			cout << "统计成功，结果输出至OutFile4!" << endl;
		}
		else if (op == '2')
		{
			string str;
			cout << "请输入待查找的单词：";
			cin >> str;
			int cnt = 0;
			LARGE_INTEGER lFrequency;//LARGE_INTEGER为数据类型
			QueryPerformanceFrequency(&lFrequency);//获取CPU的时钟频率
			LARGE_INTEGER lBeginCount;
			QueryPerformanceCounter(&lBeginCount);//获取CPU计数器数字，放在计时开
			int wordsNum = mb.findWordInTree(str,1,mb.getRoot(),cnt);
			LARGE_INTEGER lEndCount;
			QueryPerformanceCounter(&lEndCount);//获得CPU计数器数字，放在计时结
			double runTime = (double)(lEndCount.QuadPart - lBeginCount.QuadPart) / (double)lFrequency.QuadPart;//得到运行时间，单位秒
			if (wordsNum == 0) {
				cout << "查找失败!" << endl;
			}
			else {
				cout << "此单词的词频为：" << wordsNum << endl;
				cout << "查找该单词所花的时间：" << runTime << "s" << endl;
				cout << "查找长度：" << cnt << endl;
			}
		}
		else if (op == '3')
		{
			int num;
			cout << "请输入过滤词频: ";
			cin >> num;
			mb.wordsFilter(mb.getRoot(),NULL,num);
			mb.storeWordsInOutFile();
			cout << "过滤成功，结果输出至OutFile4!" << endl;
		}
		else break;
	}
	buildMainPage();
}
void MyPages::buildFunctionPage_5()
{
	MyHashMap_StoreWithArray hash1;
	cout << "正在初始化..." << endl;
	hash1.storeWordsInHashMap();
	cout << "\t\t\t\t/****功能页面****/" << endl;
	putchar('\n');
	cout << "\t\t\t\t 1.词频统计" << endl;
	putchar('\n');
	cout << "\t\t\t\t 2.单词查找" << endl;
	putchar('\n');
	cout << "\t\t\t\t 3.词频过滤" << endl;
	putchar('\n');
	cout << "\t\t\t\t 4.返回" << endl;
	char op = '0';
	while (true)
	{
		op = '0';
		while (op < '1' || op>'4')
		{
			cout << "\n请输入相应数字进行选择：";
			cin >> op;
		}
		if (op == '1')
		{
			hash1.storeWordsInOutFile();
			cout << "统计成功，结果输出至OutFile5!" << endl;
		}
		else if (op == '2')
		{
			string str;
			cout << "请输入待查找的单词：";
			cin >> str;
			int cnt = 0;
			LARGE_INTEGER lFrequency;//LARGE_INTEGER为数据类型
			QueryPerformanceFrequency(&lFrequency);//获取CPU的时钟频率
			LARGE_INTEGER lBeginCount;
			QueryPerformanceCounter(&lBeginCount);//获取CPU计数器数字，放在计时开
			int pos = 0;
			int wordsNum = hash1.findWordInHashMap(str, 1, pos, cnt);
			LARGE_INTEGER lEndCount;
			QueryPerformanceCounter(&lEndCount);//获得CPU计数器数字，放在计时结
			double runTime = (double)(lEndCount.QuadPart - lBeginCount.QuadPart) / (double)lFrequency.QuadPart;//得到运行时间，单位秒
			if (wordsNum == 0) {
				cout << "查找失败!" << endl;
			}
			else {
				cout << "此单词的词频为：" << wordsNum << endl;
				cout << "查找该单词所花的时间：" << runTime << "s" << endl;
				cout << "查找长度：" << cnt << endl;
			}
		}
		else if (op == '3')
		{
			int num;
			cout << "请输入过滤词频: ";
			cin >> num;
			hash1.wordsFilter(num);
			hash1.storeWordsInOutFile();
			cout << "过滤成功，结果输出至OutFile5!" << endl;
		}
		else break;
	}
	buildHashPage();
}
void MyPages::buildFunctionPage_6()
{
	MyHashMap_StoreWithLinkList hash2;
	cout << "正在初始化..." << endl;
	hash2.storeWordsInHashMap();
	cout << "\t\t\t\t/****功能页面****/" << endl;
	putchar('\n');
	cout << "\t\t\t\t 1.词频统计" << endl;
	putchar('\n');
	cout << "\t\t\t\t 2.单词查找" << endl;
	putchar('\n');
	cout << "\t\t\t\t 3.词频过滤" << endl;
	putchar('\n');
	cout << "\t\t\t\t 4.返回" << endl;
	char op = '0';
	while (true)
	{
		op = '0';
		while (op < '1' || op>'4')
		{
			cout << "\n请输入相应数字进行选择：";
			cin >> op;
		}
		if (op == '1')
		{
			hash2.storeWordsInOutFile();
			cout << "统计成功，结果输出至OutFile6!" << endl;
		}
		else if (op == '2')
		{
			string str;
			cout << "请输入待查找的单词：";
			cin >> str;
			int cnt = 0;
			LARGE_INTEGER lFrequency;//LARGE_INTEGER为数据类型
			QueryPerformanceFrequency(&lFrequency);//获取CPU的时钟频率
			LARGE_INTEGER lBeginCount;
			QueryPerformanceCounter(&lBeginCount);//获取CPU计数器数字，放在计时开
			int wordsNum = hash2.findWordInHashMap(str, 1, cnt);
			LARGE_INTEGER lEndCount;
			QueryPerformanceCounter(&lEndCount);//获得CPU计数器数字，放在计时结
			double runTime = (double)(lEndCount.QuadPart - lBeginCount.QuadPart) / (double)lFrequency.QuadPart;//得到运行时间，单位秒
			if (wordsNum == 0) {
				cout << "查找失败!" << endl;
			}
			else {
				cout << "此单词的词频为：" << wordsNum << endl;
				cout << "查找该单词所花的时间：" << runTime << "s" << endl;
				cout << "查找长度：" << cnt << endl;
			}
		}
		else if (op == '3')
		{
			int num;
			cout << "请输入过滤词频: ";
			cin >> num;
			hash2.wordsFilter(num);
			hash2.storeWordsInOutFile();
			cout << "过滤成功，结果输出至OutFile6!" << endl;
		}
		else break;
	}
	buildHashPage();
}