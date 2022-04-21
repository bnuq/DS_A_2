#include<bits/stdc++.h>
using namespace std;

string breakPalindrome(string palindrome) {
//If we have string size == 1, return "". Since any replacement cannot break the palindrome.
    if(palindrome.size() == 1)
        return "";
    

    // 가로 세로 알파벳을 저장할 수 있는 2차원 배열
    vector<vector<int>> count(26);
    int firstNonA = -1; // 처음으로 a 가 아닌 문자가 나오는 인덱스
    
    for(int i = 0; i < palindrome.size(); i++)
    {
        // 주어진 문자열에서 각 알파벳이 나온 인덱스를 저장한다
        count[palindrome[i] - 'a'].push_back(i);
        
        //Update firstNonA index if its not yet found.
        // 처음으로 a 가 아닌 문자가 나오는 인덱스를 저장
        if(firstNonA == -1 && palindrome[i] != 'a')
            firstNonA = i;
    }

    // 결국 a 를 바꾸는 게 중요하니까, a 가 아닌 위치를 찾아서 전략적으로 한다?
    
    //If we have N-1 a's, we need to replace last a with b
    if(count[0].size() >= palindrome.size() - 1)
        palindrome[count[0].back()] = 'b';

    //Else replace first non-'a' character with 'a'
    // 엥 이러면 aba -> aaa 되는 거 아님?
    else
        palindrome[firstNonA] = 'a';
    
    return palindrome;
}






#include <string>

using namespace std;

bool isPalindrome(const string& str)
{
    auto i = str.begin();
    auto j = str.end()-1;

    while(i <= j)
    {
        if(*i != *j)
            return false;

        i++;
        j--;
    }

    return true;
}


string MybreakPalindrome(string palindrome)
{
    // palindrome 의 대칭 전까지는 기존 값을 넘기지 않고
    // 그 이후 부터는 넘겨도 된다
    int halfSize = palindrome.size() / 2;

    for(int i = 0; i <= halfSize; i++)
    {
        char curCh = palindrome[i];

        for(char x = 'a'; x < curCh; x++)
        {   
            palindrome[i] = x;
            if(!isPalindrome(palindrome)) return palindrome;
        }
        palindrome[i] = curCh;
    }

    for(int i = halfSize+1; i < palindrome.size(); i++)
    {
        for(char x = 'a'; x <= 'z'; x++)
        {   
            palindrome[i] = x;
            if(!isPalindrome(palindrome)) return palindrome;
        }
    }

    return {};
}


#include <iostream>
int main()
{
    string str = "aaba";

    cout << boolalpha << isPalindrome(str) << endl;
}