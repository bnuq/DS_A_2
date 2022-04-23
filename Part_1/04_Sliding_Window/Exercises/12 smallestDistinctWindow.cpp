#include<string>
#include<climits>
using namespace std;

const int MAX_CHARS = 256;
 
 //Algorithm : https://www.geeksforgeeks.org/smallest-window-contains-characters-string/#:~:text=Solution%3A%20Above%20problem%20states%20that,the%20characters%20is%20%E2%80%9Cabcbcd%E2%80%9D.
 
// Function to find smallest window containing
// all distinct characters
string smallestWindow(string str)
{
    int n = str.length();
    if(n==0){
        return "";
    }
 
    // Count all distinct characters.
    int dist_count = 0;
    bool visited[MAX_CHARS] = { false };
    
    for (int i = 0; i < n; i++) {
        if (visited[str[i]] == false) {
            visited[str[i]] = true;
            dist_count++;
        }
    }
 
    // We basically maintain a window of characters
    // that contains all characters of given string.
    int start = 0, start_index = -1, min_len = INT_MAX;
 
    int count = 0;
    int curr_count[MAX_CHARS] = { 0 };
    for (int j = 0; j < n; j++) {
        // Count occurrence of characters of string
        curr_count[str[j]]++;
 
        // If any distinct character matched,
        // then increment count
        if (curr_count[str[j]] == 1)
            count++;
 
        // if all the characters are matched
        if (count == dist_count) {
            // Try to minimize the window i.e., check if
            // any character is occurring more no. of times
            // than its occurrence in pattern, if yes
            // then remove it from starting and also remove
            // the useless characters.
            while (curr_count[str[start]] > 1) {
                if (curr_count[str[start]] > 1)
                    curr_count[str[start]]--;
                start++;
            }
 
            // Update window size
            int len_window = j - start + 1;
            if (min_len > len_window) {
                min_len = len_window;
                start_index = start;
            }
        }
    }
 
    // Return substring starting from start_index
    // and length min_len
    return str.substr(start_index, min_len);
}


#include <string>
#include <unordered_set>
#include <unordered_map>
#include <climits>

using namespace std;

/* 
    원래 unordered set 을 전부 돌면서, 윈도우 안에 distint char 가 다 있는 지 확인했는데
    개수 정보를 이용해서, 저장해놓은 자료구조를 다 돌지 않고도
    모든 distinct char 를 저장했는 지를 파악할 수 있었다

    매 반복마다 정확하게 할 일을 하는 게 중요하구나
 */
string smallestWindow(string str){
    
    // 먼저 string 에 들어있는 각 알파벳을 조사
    unordered_set<char> uniqueChars{};
    for(char ch : str)
        uniqueChars.insert(ch);

    // 서로 다른 문자들의 개수
    int distCount = uniqueChars.size();


    int minLen = INT_MAX;
    int minLeft{};
   
       
    // 윈도우 설정
    int leftIdx{ 0 }, rightIdx{ 0 };
    int count{ 0 }; // window 에 들어온 distinct char 의 개수
    unordered_map<char, int> windowChars{};

    while(leftIdx <= rightIdx && rightIdx < str.size())
    {
        // 현재 right index 가 가리키는 문자을 넣고 나서
        char curCh = str[rightIdx];
        windowChars[curCh]++;

        // windwoChars 에 들어온 distinct char 의 개수를 파악한다
        // 방금 들어온 문자 개수가 1 이라면, 처음 들어왔으니까 count 증가시킨다
        if(windowChars[curCh] == 1) count++;


        // 이후 count 와 distCount 값을 비교해서
        // window 안에 모든 distinct char 가 들어왔는 지를 판단한다
        if(count != distCount)  // window 에 필요한 문자들이 아직 다 안들어왔다
        {
            rightIdx++; // 윈도우 사이즈 오른쪽으로 늘리기
        }
        else                    // window 안에 필요한 문자들이 다 있다
        {
            // 현재 window 길이가 최소라면, 정보 갱신
            if(rightIdx - leftIdx + 1 < minLen)
            {
                minLen = rightIdx - leftIdx + 1;
                minLeft = leftIdx;
            }


            // 이제 left index 를 오른쪽으로 이동시킬거야
            char leftCh = str[leftIdx];
            leftIdx++;
            windowChars[leftCh]--;

            // left index 이동으로 인해, 문자 아예 없어졌다면
            // count 를 줄인다
            if(windowChars[leftCh] == 0) count--;
        }
    }

    return str.substr(minLeft, minLen);
}