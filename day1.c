


//14MA 20021  -->  NISHANT NIKHIL
/////////////////////////////////////// QUESTION 1 TO 5 /////////////////////////////////////////////


#include <stdio.h>

void rd(int a[],int n)
{
	int i;
	printf("\nGive Elements: ");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
}

int minimum(int arr[],int n)
{
	int i;
	int min=arr[0];
	for(i=1;i<n;i++)
	{
		if(arr[i]<min)
			min=arr[i];
	}
	return min;
}

int location(int a[],int n,int k)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(a[i]==k)
			return i+1;
	}	
	return -1;
}

int min_location(int a[],int n)
{
	int k=minimum(a,n);
	return location(a,n,k);
}
void replace(int a[],int n,int k,int t)
{
	a[t-1]=k;
}

void selection_sort(int a[],int n)
{
	int step;
	int loc;
	printf("\nSelection Sort: ");
	for(step=0;step<n;step++)
	{
		loc=min_location(a,n);
		printf("%d ",a[loc-1]);
		replace(a,n,100,loc);
		
	}
}



int main()
{
	int n;
	printf("\nEnter Size: ");
	scanf("%d",&n);
	int arr[1000];
	rd(arr,n);
	printf("\nMinimum ELement is: %d",minimum(arr,n));	
	int k;

/*	printf("\nEnter Element whose location you want to know: ");
	scanf("%d",&k);
	int res=location(arr,n,k);
	if(res>=1)
		printf("\nLocation of %d is: %d",k,res);
	else
		printf("\nElement not found");
*/
	printf("\nMin element location is: %d",min_location(arr,n));		
//
/*	int t;
	printf("\nEnter the location where you want to replace: ");
	scanf("%d",&t);
	printf("\nEnter the value you want to replace by: ");
	scanf("%d",&k);
	replace(arr,n,k,t);
*///
	selection_sort(arr,n);	

		
		
			
	
}
