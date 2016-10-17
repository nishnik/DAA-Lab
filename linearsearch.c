#include<stdio.h>
#include<malloc.h>
int linear_search(int arr[],int size,int to_search)
{
	int i;
	for(i=0;i<size;i++)
	{
		if(arr[i]==to_search)
			return i+1;
	}
	return 0;
}
int main()
{
	printf("\nEnter the size of integer array : ");
	int size;
	scanf("%d",&size);
	int* arr;
	arr=(int*)malloc(sizeof(int)*size);
	int i;
	printf("\nEnter the array: ");
	for(i=0;i<size;i++)
	{
		scanf("%d",&arr[i]);
	}
	printf("Enter the number to search: ");
	int to_search;
	scanf("%d",&to_search);
	int pos=linear_search(arr,size,to_search);
	if(pos>=1)
		printf("Given number is present in the array at pos: %d\n",pos);
	else printf("Given number is not in the array\n");
	return 0;
}
