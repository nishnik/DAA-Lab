



//14MA 20021  -->  NISHANT NIKHIL
/////////////////////////////////////// QUESTION 6 TO 7 /////////////////////////////////////////////


#include <stdio.h>

void rd(int a[],int n)
{
	int i;
	printf("\nGive Elements: ");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
}



void scan(int a[],int n)
{
	int i;
	for(i=0;i<n-1;i++)
	{
		if(a[i]>a[i+1])
			{
				a[i]=a[i]+a[i+1];
				a[i+1]=a[i]-a[i+1];
				a[i]=a[i]-a[i+1];
			}
	}
}

void bubble_sort(int a[],int n)
{
	int step;
	for(step=0;step<n-1;step++)
		scan(a,n);
	printf("\nBubble Sort: ");
	for(step=0;step<n;step++)
		printf("%d ",a[step]);
}

int main()
{
	int n;
	printf("\nEnter Size: ");
	scanf("%d",&n);
	int arr[1000];
	rd(arr,n);
	//scan(arr,n);
	
	bubble_sort(arr,n);	
}
