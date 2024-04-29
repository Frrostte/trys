#include <stdio.h>
#include <sys/time.h>
#include <stdlib.h>
#include<time.h>
void swap(int *a,int *b)
{
        int temp=*a;
        *a=*b;
        *b=temp;
}
int partition(int low,int high,int a[])
{
       int pivot=a[low],i=low,p=high;
       do{
                do{
                        i++;
                   }while(a[i]<pivot && i<high);
                do{
                        p--;
                  }while(a[p]>pivot);
                  if(i<p)
                        swap(&a[i],&a[p]);
          }while(i<p);
          swap(&a[p],&a[low]);
          return p;
}
void quickSort(int low,int high,int a[])
{
        int j;
        if(low<high)
        {
                j=partition(low,high+1,a);
                quickSort(low,j-1,a);
                quickSort(j+1,high,a);
        }
        return;
}
void calc(int low,int high,int a[])
{
	clock_t start,end;
	double time;
	start=clock();
	quickSort(low,high,a);
	end=clock();
	time=((double)(end-start))/1000000.0;
	printf("\t %lf",time);
}
void main()
{
        int n=10000,i,k,j=1;
        printf("\tInputs\tAscending Order\tRandom Numbers\tDescending Order");
       
        while(j<5)
        {
                int a[n];
                printf("\n\t %d",n);
                for(i=0;i<n;i++)
                        a[i]=i;
                calc(0,n-1,a);
                for(i=0;i<n;i++)
                        a[i]=rand()%(n*10);
                calc(0,n-1,a);
                for(i=0,k=n;i>0;i++,k--)
                        a[i]=k;
                calc(0,n-1,a);
                n=n*2;
                j++;
        }
        printf("\n");
}
