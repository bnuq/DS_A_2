#include<bits/stdc++.h>
using namespace std;

int skip_whitespace(const string &sentence, int idx) {
    while (idx < sentence.length() && sentence[idx] == ' ') {
        idx += 1;
    }

    return idx;
}

int normalize_word(string &sentence, int idx) {
    if (idx < sentence.length() && sentence[idx] != ' ') {
        sentence[idx] = toupper(sentence[idx]);
        idx += 1;
    }

    while (idx < sentence.length() && sentence[idx] != ' ') {
        sentence[idx] = tolower(sentence[idx]);
        idx += 1;
    }

    return idx;
}

string normalize(const string &sentence) {
    string copy = sentence;
    int idx = 0;

    while (idx < copy.length()) {
        idx = skip_whitespace(copy, idx);
        idx = normalize_word(copy, idx);
    }

    return copy;
}



// 내가 한 게 더 좋은듯 ㅋㅋ

#include <string>
#include <sstream>
using namespace std;


// String Stream 사용해봤다
string normalize_1(const string &sentence) {
    
    string res{};

    // string stream 을 문자열로 초기화
    stringstream ss(sentence);
    string buffer{};

    // 기본적으로 띄어쓰기를 기준으로 나누어서 저장한다
    // string stream 에서 버퍼로 출력, cout 처럼
    //while(ss >> buffer)
    while(getline(ss, buffer, ' ')) // 이것과 동일, 문자열 입력하는 것과 동일하다
                                    // cin 대신 string stream 이라는 차이
                                    // delimiter 디폴트는 \n
    {
        for(int i = 0; i < buffer.size(); i++)
        {
            if(i == 0) buffer[0] = toupper(buffer[0]);
            else buffer[i] = tolower(buffer[i]);
        }

        res += (buffer + ' ');
        buffer = "";
    }    
    res.pop_back();

    return res;
}

string normalize(const string &sentence)
{
    string copy = sentence;
    bool isFirst = true;

    for(char& ch : copy)
    {
        if(ch == ' ')
        {
            isFirst = true;
            continue;
        }

        if(isFirst)
        {
            ch = toupper(ch);
            isFirst = false;
        }
        else ch = tolower(ch);
        
    }

    return copy;
}



#include <iostream>
int main()
{
    string str = "THIS IS SO FUN";
    cout << normalize(str) << endl;
}