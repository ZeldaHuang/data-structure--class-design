#pragma once
#ifndef SORT_H
#define SORT_H
#include"Word.h"
#include"linearList.h"
void quickSort(MyWord *wordsArray, int low, int high);//��������������˳��ṹ

Node *sortList(Node *head);//�鲢����������ʽ�ṹ���ռ临�Ӷ�o(1)
Node *mergeList(Node *head1, Node *head2);

#endif // !SORT_H

