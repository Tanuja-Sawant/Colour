#include<stdio.h>

void merge(int* arr, int l, int m, int r){
	int n1=m-l+1;int n2=r-m;
	int L[n1]; int R[n2];
	
	for(int i=0; i<n1;i++)
	{
		L[i]=arr[l+i];
		//printf("L:%d \n",L[i]);
	}
	
	for(int j=0; j<n2;j++)
	{
		R[j]=arr[m+1+j];
		//printf("R:%d \n",R[j]);
	}

	int i,j,k;
	i=j=0;
	k=l;
	while(i<n1 && j<n2)
	{
		if(L[i]<R[j])
		{
			arr[k]=L[i];
			k++; i++;
		}

		else 
		{
			arr[k]=R[j];
			k++; j++;
		}
	}

	if(j==n2){
		while(i<n1)
		{
			arr[k]=L[i];
			k++;
			i++;
		}
	}

	if(i==n1){
		while(j<n2)
		{
			arr[k]=R[j];
			k++;
			j++;
		}
	}
}

void mergeSort(int* arr, int l, int r){
	int m=(l+r)/2;
		
	if(l<r)
	{
		mergeSort(arr,l,m);
		mergeSort(arr,m+1,r);
		merge(arr,l,m,r);
	}
	
}

void main(){

	int arr[]={10,8,2,1,7,5};
	int n =sizeof(arr)/sizeof(arr[0]);
	mergeSort(arr,0,n-1);
	for(int i=0;i<n;i++)
		printf("%d \n",arr[i]);
}
