#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int array[100];
float timedifference_msec(struct timeval t0, struct timeval t1)
{
    return (t1.tv_sec - t0.tv_sec) * 1000.0f + (t1.tv_usec - t0.tv_usec) / 1000.0f;
}

void linear (int a[], int  x,int n)
{
	int flag=0,i;
	for (i=0;i<n;i++){
		if (a[i]==x){
			flag =1;
			break;
		}
	}
	if (flag ==1){
		printf("%d found at position %d\n",x,i);
	}
	else{
		printf("Element not found!\n");
	}
}

void main()
{
	struct timeval t0;
	struct timeval t1;
	float elapsed;
	int i,x;
	while(1){
		int size,ch,limit;
		printf("\n1.Creation & Search\t\t2.Exit\n");
		printf("Enter Your Choice:");
		scanf("%d",&ch);
		switch(ch){
			case 1:{
				printf("Enter the number of elements:");
				scanf("%d",&size);
				int array[size];
				printf("Enter Limit :"),scanf("%d",&limit);
				srand( (unsigned) time(NULL) * getpid()); 
				if (array!=NULL){
					for (i=0;i<size;i++){
						array[i]=rand()%limit;
					}
				}
				printf("\nThe array elements are :\n");
				for (i=0;i<size;i++){
					printf("%d\t",array[i]);
				}
				printf("\n\nEnter the number you have to search :");
				scanf("%d",&x);
				gettimeofday(&t0, NULL);
				linear(array,x,size);
				gettimeofday(&t1, NULL);
				elapsed = timedifference_msec(t0, t1);
				printf("Linear Search Code executed in %f milliseconds.\n\n", elapsed);
				break;
			}
			case 2:{
				printf("Exiting...\n");
				exit(0);
			}
			default:{
				printf("\nError, wrong input.\n");
				break;
			}
		}
	}
}

