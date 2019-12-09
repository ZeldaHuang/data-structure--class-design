#include"Class.h"
#include"linearList.h"
#include"Sort.h"
using namespace std;

void mergeSort(MyWord *wordsArray, int low, int high)
{
	if (low >= high) return;

	int p = rand() % (high - low) + low;
	swap(wordsArray[p], wordsArray[high]);
	MyWord privot = wordsArray[high];
	int i = low;
	int j = high;
	while (1)
	{
		while (i < j&& wordsArray[i].getWord() < privot.getWord()) i++;
		while (i < j&& wordsArray[j].getWord() >= privot.getWord()) j--;
		if (i >= j)break;
		swap(wordsArray[i], wordsArray[j]);
	}
	swap(wordsArray[i], wordsArray[high]);
	mergeSort(wordsArray, low, i - 1);
	mergeSort(wordsArray, i + 1, high);
	return;
}