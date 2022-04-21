#include<iostream>
#include<string>
using namespace std;


int main(){

	string paragraph = "We are learning about STL strings. STL string class is quite powerful";

	string word;
	getline(cin,word);

	//find function
	int index =  paragraph.find(word);

	
	// size_type::npos 대신 -1 사용 가능
	if(index!=-1){
		cout <<"first occ" <<index;
	}

	// 다음 위치부터 검색
	index = paragraph.find(word,index+1);

	if(index!=-1){
		cout<<"second occ "<<index <<endl;
	}



	return 0;
}