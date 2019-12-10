#pragma once
#ifndef SORT_H
#define SORT_H
#include"Word.h"
#include"linearList.h"
void quickSort(MyWord *wordsArray, int low, int high);//快速排序，适用于顺序结构

Node *sortList(Node *head);//归并排序，用于链式结构，空间复杂度o(1)
Node *mergeList(Node *head1, Node *head2);

#endif // !SORT_H

