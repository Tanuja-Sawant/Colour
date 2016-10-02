#include <bits/stdc++.h>
#include <string>
#include <iostream>
#include <algorithm>


using namespace std;


int A[100];

pair<int,int> B[100];

bool f(int A, int B){
	if(A<B) return(true);
	return(false);
}

int bins3(int lo,int hi,int k){
	int mid;
	

	while(lo<hi){

		mid = lo + (hi -lo)/2;

		cout << lo << " " << " " << mid << " " << hi << endl;

		if(!f(k,A[mid])){
			lo=mid+1;
		}
		else{
			
			hi=mid-1;
		}


		
	}

	return(A[hi]);
}



int bins(int lo,int hi,int k){
	int mid;
	

	while(lo<hi){

		mid = lo + (hi -lo)/2;

		cout << lo << " " << " " << mid << " " << hi << endl;

		if(A[mid]<k){
			lo=mid+1;
		}
		else{
			if(A[mid]==k){
				return(mid);
			}
			hi=mid-1;
		}


		
	}

	return(hi);
}

float bins2(float lo,float hi,float k){
	float  mid;
	

	while(hi-lo>0.0001){

		mid = lo + (hi -lo)/2;

		cout << lo << " " << " " << mid << " " << hi << endl;

		if(mid*mid<k){
			lo=mid;
		}
		else{
			if(mid*mid==k){
				return(mid);
			}
			hi=mid;
		}


		
	}

	return(hi);
}

int main(){



	for(int i=0;i<10;i++){
		cin >> B[i].first;
		B[i].second=i;
	}



	
  std::sort(B,B+10); 

  for(int i=0;i<10;i++){
		cout <<  B[i].first << " " << B[i].second << endl;
	}

	cout << bins3(0,7,50) << endl;
}
