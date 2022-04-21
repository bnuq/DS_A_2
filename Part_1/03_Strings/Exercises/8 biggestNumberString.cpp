#include<bits/stdc++.h>
using namespace std;

// 실제 합쳐보고 그 결과를 리턴
bool compare(string s1,string s2){
    return s1 + s2 > s2 + s1;
}

string concatenate(vector<int> numbers){
    vector<string> output;

    // 일단 문자열 배열에 문자로 넣고 나서
    for(int no:numbers){
        output.push_back(to_string(no));
    }
    // 정렬
    sort(output.begin(),output.end(),compare);

    string ans = "";
    for(string x:output){
        ans += x;
    }
    return ans;
}


#include <string>
#include <algorithm>
#include <vector>

using namespace std;

string Myconcatenate(vector<int> numbers)
{
    // lexicographically large 순서로 정렬하고 싶으므로
    // 실제로 합쳐본 다음에, 합친 결과에 맞춰서 정렬을 한다
    // 서로 다른 2개 각각이, 문자열 순서가 큰것 -> 작은 것 순서로 정렬되면
    // 전체도 그러한 순서로 정렬된다? 부분을 정렬한 방식대로 전체가 정렬된다?
    sort(numbers.begin(), numbers.end(), [](int e1, int e2)
    {
        string s1{to_string(e1)};
        string s2{to_string(e2)};

        return (s1+s2) > (s2+s1);
    });

    string res{};
    for(auto x : numbers)
    {
        res += to_string(x);
    }

    return res;
}