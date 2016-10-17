



//14MA 20021  -->  NISHANT NIKHIL
/////////////////////////////////////// QUESTION 8 TO 13 /////////////////////////////////////////////


#include <stdio.h>

void rd(int a[],int n)
{
	int i;
	printf("\nGive Elements: ");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
}

void increment(int a[],int n)
{
	int i;
	for(i=0;i<n;i++)
		a[i]+=1;
}

int even(int a[],int n)
{
	int i;
	int count=0;
	for(i=0;i<n;i++)
	{
		if(a[i]%2==0)
		count++;
	}
	return count;
}

int smaller(int a[],int n,int k)
{
	int i;
	int count=0;
	for(i=0;i<n;i++)
		if(a[i]<k)
			count++;
	return count;
}

void order(int a[],int b[],int n)
{
	int i;
	printf("\nOrder: ");
	for(i=0;i<n;i++)
		printf("%d ",a[b[i]-1]);
}

void rearrange(int a[],int b[],int n,int c[])
{
	int i=0;
	for(i=0;i<n;i++)
		{
			c[b[i]-1]=a[i];
		}
}

void location_sort(int a[],int n,int c[])
{
	int b[1000];int i;
	for(i=0;i<n;i++)
		b[i]=smaller(a,n,a[i]);
	increment(b,n);
	rearrange(a,b,n,c);
	printf("\nLocation Sort: ");
	for(i=0;i<n;i++)
		printf("%d ",c[i]);
}

int main()
{
	int n;
	printf("\nEnter Size of array A: ");
	scanf("%d",&n);
	int arr_a[1000];
	rd(arr_a,n);
	printf("\nNumber of even values in array is: %d",even(arr_a,n));
/*	printf("\nEnter the value, (smaller tha which, values you seek): ");
	int k;
	scanf("%d",&k);
	printf("\nThere are %d smaller values than %d",smaller(arr_a,a,k),k);
*/	
//	increment(arr_a,n);
/*	printf("\nEnter size of array B: ");
	int n_b;
	scanf("%d",&n_b);
	int arr_b[1000];
	rd(arr_b,n_b);
	//order(arr_a,arr_b,n_b);
*/
	int arr_c[1000];
	//rearrange(arr_a,arr_b,n,arr_c);
	location_sort(arr_a,n,arr_c);
}
