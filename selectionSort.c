#include<stdio.h>

void swap(int* arr, int i, int min){
	int temp = arr[i];
	arr[i]=arr[min];
	arr[min]=temp;
}

void selectionSort(int* arr,int n){
	int min;
	for(int i=0;i<n-1;i++){
		min=i;
		for(int j=i;j<n-1;j++){
			if(arr[min]>arr[j+1])
				min=j+1;
		}
		swap(arr,i,min);
	}
}


void main(){

	int arr[]={5,2,4,10,8};
	int n = sizeof(arr)/sizeof(arr[0]);
	selectionSort(arr,n);
	for(int i=0;i<n;i++)
		printf("%d \n",arr[i]);
}
