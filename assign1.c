#include <stdio.h>

void rd(int x[],int n)
{
        printf("\nEnter %d values: \n",n);
        int i=0;
        for(i=0;i<n;i++)
        {
                scanf("%d",&x[i]);
        }
}

void wr(int x[],int n)
{
        printf("\nThe %d values are: \n",n);
        int i=0;
        for(i=0;i<n;i++)
        {
                printf("%d ",x[i]);
        }
}

void bs(int x[],int n)
{
        int i,j;
        for(i=0;i<n;i++)
        {
                for(j=0;j<n-i-1;j++)
                {
                        if(x[j]>x[j+1])
                        {
                                int temp=x[j];
                                x[j]=x[j+1];
                                x[j+1]=temp;
                        }
                }
        }
}

int loc(int x[],int n)
{
        int max_ele=x[0];
        int max_pos=0;
        int i;
        for(i=1;i<n;i++)
        {
                if(x[i]>max_ele)
                {
                        max_ele=x[i];
                        max_pos=i;
                }
        }
        return max_pos+1;
}

void ss(int x[],int n)
{
        int p=loc(x,n);
        int temp=x[p-1];
        x[p-1]=x[n-1];
        x[n-1]=temp;
        bs(x,n-1);
}

void rss(int x[],int n)
{
        if(n>1)
        {
                int p;
                p=loc(x,n);
                int temp=x[p-1];
                x[p-1]=x[n-1];
                x[n-1]=temp;
                rss(x,n-1);
        }
}

int main()
{
        int n;
	int x[20];
	printf("\nGive n ");
	scanf("%d",&n);
	rd(x,n); 
	//bs(x,n);
	//int p=loc(x,n);
	//printf("\nMax Element Position is: %d",p);  
	//ss(x,n);
	rss(x,n);
	wr(x,n);
}
