#include <bits/stdc++.h>
#include <string>
#include <iostream>
#include <algorithm>
#include <iterator>     // std::iterator, std::input_iterator_tag

using namespace std;










class LexGen {

	int lex;


class MyIterator : public std::iterator<std::input_iterator_tag, int>
{
  int arr[100]={0};
  int lex;
  char * str = "abcd";


public: MyIterator(int x){
  	lex=x;

	for(int i=0;i<lex;i++){
  		arr[i]=0;
  	}


  }
  

  bool end(){
  	
  		if(arr[lex]==1) return true;
  	

  	return false;
}
  
  MyIterator operator++(int) {

  for(int i=lex-1;i>=0;i--){
  		cout << str[arr[i]];
  }
  	cout << endl;
  
  int n=0;
  for(int i=0;i<=lex;i++){
  	
  		if(arr[n]++>2){
  			arr[n]=0;
  			n++;
  		}
  		else{
  			break;
  		}
  }

  	return *this;
  }
  //MyIterator operator++(int) {MyIterator tmp(*this); operator++(); return tmp;}
  
  char * operator*() {

  	/*
  	char st[lex];
  	for(int i=lex-1;i>=0;i--){
  		st[i]=str[arr[i]];
  	}
  	cout << st << endl;
*/
  }

  
};





	public : LexGen(int i){
		lex=i;
	}


	MyIterator begin(){

		
		return MyIterator(lex);
	}


};




int main () {


	int lex;

	cin >> lex;
  
  LexGen it(lex);

  for (LexGen::MyIterator l = it.begin(); !l.end(); l++);
  		

  

/*
  int lex;
  cin >> lex;
  int arr[lex]={0};
for(int j=0;j<lex*lex*lex*lex;j++){
  for(int i=lex-1;i>=0;i--){
  	cout << arr[i];
  }
  cout << endl;
  
  int n=0;
  for(int i=0;i<lex;i++){
  	
  		if(arr[n]++>2){
  			arr[n]=0;
  			n++;
  		}
  		else{
  			break;
  		}
  }
  
}
*/
  return 0;
}
