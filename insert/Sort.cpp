#include"Word.h"
#include"linearList.h"
#include"Sort.h"
using namespace std;

void quickSort(MyWord *wordsArray, int low, int high)
{
	if (low >= high) return;

	int p = rand() % (high - low) + low;
	swap(wordsArray[p], wordsArray[high]);
	MyWord privot = wordsArray[high];
	int i = low, j = high;
	while (i<j)
	{
		while (i < j&& wordsArray[i] < privot) i++;
		while (i < j&& wordsArray[j]>= privot) j--;
		if(i<j) swap(wordsArray[i], wordsArray[j]);
	}
	swap(wordsArray[i], wordsArray[high]);
	quickSort(wordsArray, low, i - 1);
	quickSort(wordsArray, i + 1, high);
	return;
}

node *sortList(node *head)
{
	if (head == NULL || head->next == NULL) {
		return head;
	}
	node *fast = head, *slow = head;
	while (fast->next != NULL && fast->next->next != NULL)//����ָ���ҵ��м�ڵ�
	{
		fast = fast->next->next;
		slow = slow->next;
	}
	fast = slow;
	slow = slow->next;
	fast->next = NULL;//�ָ�����
	fast=sortList(head);
	slow = sortList(slow);
	return mergeList(fast, slow);
}
node *mergeList(node *head1, node *head2)
{
	if (head1 == NULL) {
		return head2;
	}
	if (head2 == NULL) {
		return head1;
	}
	node *res, *ptr;//resΪ�ϲ�������ͷ�ڵ�
	if (head1->data < head2->data) {
		res = head1;
		head1 = head1->next;
	}else {
		res = head2;
		head2 = head2->next;
	}
	ptr = res;
	while (head1 != NULL && head2 != NULL)
	{
		if (head1->data < head2->data) {
			ptr->next = head1;
			head1 = head1->next;
		}else {
			ptr->next = head2;
			head2 = head2->next;
		}
		ptr = ptr->next;
	}
	if (head1 != NULL) {
		ptr->next = head1;
	}
	else if(head2!=NULL){
		ptr->next = head2;
	}
	return res;
}