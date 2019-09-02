#include<iostream>
#include<string>
int reset[100];

using namespace std;

// function to make reset table
void makeResetTable(string pat){
	reset[0]=-1;

	int i=1;
	int j=-1;

	while(i<pat.length()){

		while(j>=0 && pat[i]!=pat[j]){
			j=reset[j];
		}

		j++;
		i++;
		reset[i]=j;
	}

}

// function to check the string and the pattern
void isPatternFound(string str,string pat){

	// call the make reset table function
	makeResetTable(pat);
	int i=0;
	int j=0;

	while(i<str.length()){

		while(j>=0 && pat[j]!=str[i]){
			j=reset[j];
		}

		

		j++;
		
		if(j==pat.length()){
			cout<<"found pattern at index : "<<i-2<<endl;
		}

		i++;
	}

}

int main(){

	string str;
	string pat;


	cin>>str;
	cin>>pat;

	isPatternFound(str,pat);



	return 0;

}