#include<stdio.h>

void swap(int* arr, int j){
	
	int p = arr[j];
	arr[j]=arr[j+1];
	arr[j+1]=p; 


}

void bubbleSort(int* arr,int n){

	for(int i=0;i<n;i++){
		for(int j=0;j<n-1-i;j++)
		{
			if(arr[j]>arr[j+1])
				swap(arr,j);
		}
	}
}


void main(){

	int arr[]={1,5,4,2,8};
	int n=sizeof(arr)/sizeof(arr[0]);
	bubbleSort(arr,n);
	
	for(int i=0; i<n;i++)
		printf("%d \n",arr[i]);
}
