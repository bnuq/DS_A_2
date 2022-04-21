#include<bits/stdc++.h>
using namespace std;

//str is the input the string
string compressString(const string &str){   
    int n = str.length();
    string output;
    for (int i = 0; i < n; i++) {
 
        // Count occurrences of current character
        int count = 1;
 
        // 현재 인덱스와 그 다음 인덱스를 비교
        // 다른 문자로 넘어가기 전에 비교
        while (i < n - 1 && str[i] == str[i + 1]) {
            count++;
            i++;
        }
 
        // Store the Character and its count
        // 둘다 += 연산자 사용
        // int 는 to_string 사용해서 char 로 먼저 바꿈
        output += str[i];
        output += to_string(count);
    }

    
    if(output.length()>str.length()){
        return str;
    }
    return output;
}


#include <string>

using namespace std;

//str is the input the string
string MycompressString(const string &str){   
    //complete the function to return output string
  
    int strSize = str.length();

    string res{};
    int count = 0, index = 0;
    
    while(index < strSize)
    {
        char curCh = str[index];
        
        // char 를 string 에 붙일 때는
        // += 연산자 사용
        res += curCh;
        count++;

        index++;

        while(index < strSize && str[index] == curCh)
        {
            count++;
            index++;
        }

        // int 를 string 에 붙일 때는
        // to_stirng + += 연산자 사용
        res += to_string(count);
        count = 0;
    }


    return (res.length() < str.length()) ? res : str;
}