#include <stdio.h>
#include <stdlib.h>
#define max 10

int Partition(int A[], int start, int end)
{
	int pivot = A[end];
	int i;
	int index = start;
	int temp;

	for(i = start; i < end; i++)
	{
		if(A[i] <= pivot)
		{
			temp = A[i];
			A[i] = A[index];
			A[temp] = A[i];
			index++;
		}
	}
	temp = A[index];
	A[index] = A[end];
	A[end] = temp;
}

void	QuickSort(int A[], int start, int end)
{
	int index;
	int i;

	if (start < end)
	{
		index = Partition(A, start, end);
		QuickSort(A, start, index - 1);
		QuickSort(A, index + 1, end);
	}
	else
	{
		return ;
	}
}


int	main()
{
	int A[max] = {40, 30, 100, 40, 80, 70, 90, 10, 20, 50};
	int i;

	printf("\n before sorting :");
	i = -1;
	while ( ++i < max)
	{
		printf("%d ", A[i]);
	}
}