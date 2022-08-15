#include <stdio.h>
#include <stdlib.h>
#include <time.h>

float timedifference_msec(struct timeval t0, struct timeval t1)
{
    return (t1.tv_sec - t0.tv_sec) * 1000.0f + (t1.tv_usec - t0.tv_usec) / 1000.0f;
}

int binarysearch(int a[],int beg,int end,int val)
{
	int mid;
	if (end>=beg){
		mid=(beg+end)/2;
		if (a[mid]==val){
			return mid+1;
		}
		else if(a[mid]<val){
			return binarysearch(a,mid+1,end,val);
		}
		else{
			return binarysearch(a,beg,mid-1,val);
		}
	}
	return 0;
}

void  main()
{
	struct timeval t0;
	struct timeval t1;
	srand( (unsigned) time(NULL) * getpid()); 
	
	int n,i,key ;
	int a[100];
	printf("Enter the number of elements:");
	scanf("%d",&n);
	for (i=0;i<n;i++){
		a[i]=rand()%100;
	}
	
	//SORTING
	int j,temp;
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			if (a[j]<a[i]){
				temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
	}
	
	printf("The array elements are:\n");
	for (i=0;i<n;i++){
		printf("%d\t",a[i]);
	}
	
	printf("\nEnter the element to be searched:");
	scanf("%d",&key);
	gettimeofday(&t0, NULL);
	int res=binarysearch(a,0,n-1,key);
	
	if (res == 0){
			printf("\nElement is not present in the array.\n");  
	}	
	else{
		printf("\nElement is present at %d position of array\n", res);  
	}
	gettimeofday(&t1, NULL);
   	printf("Binary Search Code executed in %f milliseconds.\n", timedifference_msec(t0, t1));
}
