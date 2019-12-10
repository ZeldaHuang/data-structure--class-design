#pragma once
#ifndef SORT_H
#define SORT_H
#include"Word.h"
#include"linearList.h"
void quickSort(MyWord *wordsArray, int low, int high);

Node *sortList(Node *head);
Node *mergeList(Node *head1, Node *head2);

#endif // !SORT_H

