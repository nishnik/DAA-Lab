#include<stdlib.h>
#include<stdio.h>

void merge(int arr[],int l,int m,int r)
{
	int i,j,k;
	int n1=m-l+1;
	int n2=r-m;

	int left[n1],right[n2];

	for(i=0;i<n1;i++)
		left[i]=arr[l + i];
	for(j=0;j<n2;j++)
		right[j]=arr[m + 1+ j];

	i = 0;
	j = 0;
	k = l;
	while(i<n1 && j<n2)
	{
	if(left[i]<=right[j])
	{
	    arr[k++]=left[i++];
	}
	else
	{
	    arr[k++]=right[j++];
	}
	}

	while(i<n1)
	{
	arr[k++]=left[i++];
	}
	while(j<n2)
	{
	arr[k++]=right[j++];
	}
}

void mergeSort(int arr[],int l,int r)
{
    if (l<r)
    {
        int m=l+(r-l)/2; 
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}
 

void rd(int a[],int n)
{
	int i;
	printf("\nGive Elements: ");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
}

int main()
{
	int n;
	printf("\nEnter Size: ");
	scanf("%d",&n);
	int arr[1000];
	rd(arr,n);
	mergeSort(arr,0,n-1);

	printf("\nSorted array is \n");
	int i;
	for(i=0;i<n;i++)
		printf("%d ",arr[i]);
	return 0;
}
