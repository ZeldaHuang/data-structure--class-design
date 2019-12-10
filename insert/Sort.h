#pragma once
#ifndef SORT_H
#define SORT_H
#include"Word.h"
#include"linearList.h"
void quickSort(MyWord *wordsArray, int low, int high);

node *sortList(node *head);
node *mergeList(node *head1, node *head2);

#endif // !SORT_H

