#include<stdio.h>

void swap(int* arr,int* jarr)
{
	int temp=arr[0];
	arr[0]=jarr[0];
	jarr[0]=temp;
}

void quickSort(int* arr, int n)
{
	int i=-1;
	int j=0;
	int p=arr[n-1];

	while(j<n-1)
	{
		if(arr[j]<=p)
		{
			i++;
			swap(&arr[i],&arr[j]);	
		}
		j++;
	}
	i++;
	swap(&arr[i],&arr[n-1]);
	if(i>1)
		quickSort(arr,i);
	
	if((n-1-i)>1)
		quickSort(&arr[i+1],n-1-i);

}

void main()
{
	int arr[]={7,4,2,9,1,11,0,255,100,500,200,600};
	int n=sizeof(arr)/sizeof(arr[0]);

	quickSort(arr,n);

	for(int i=0;i<n;i++)
		printf("%d \n",arr[i]);

}
