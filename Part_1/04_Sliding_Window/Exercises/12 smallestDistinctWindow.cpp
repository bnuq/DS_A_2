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
    ?????? unordered set ??? ?????? ?????????, ????????? ?????? distint char ??? ??? ?????? ??? ???????????????
    ?????? ????????? ????????????, ??????????????? ??????????????? ??? ?????? ?????????
    ?????? distinct char ??? ???????????? ?????? ????????? ??? ?????????

    ??? ???????????? ???????????? ??? ?????? ?????? ??? ???????????????
 */
string smallestWindow(string str){
    
    // ?????? string ??? ???????????? ??? ???????????? ??????
    unordered_set<char> uniqueChars{};
    for(char ch : str)
        uniqueChars.insert(ch);

    // ?????? ?????? ???????????? ??????
    int distCount = uniqueChars.size();


    int minLen = INT_MAX;
    int minLeft{};
   
       
    // ????????? ??????
    int leftIdx{ 0 }, rightIdx{ 0 };
    int count{ 0 }; // window ??? ????????? distinct char ??? ??????
    unordered_map<char, int> windowChars{};

    while(leftIdx <= rightIdx && rightIdx < str.size())
    {
        // ?????? right index ??? ???????????? ????????? ?????? ??????
        char curCh = str[rightIdx];
        windowChars[curCh]++;

        // windwoChars ??? ????????? distinct char ??? ????????? ????????????
        // ?????? ????????? ?????? ????????? 1 ?????????, ?????? ?????????????????? count ???????????????
        if(windowChars[curCh] == 1) count++;


        // ?????? count ??? distCount ?????? ????????????
        // window ?????? ?????? distinct char ??? ???????????? ?????? ????????????
        if(count != distCount)  // window ??? ????????? ???????????? ?????? ??? ???????????????
        {
            rightIdx++; // ????????? ????????? ??????????????? ?????????
        }
        else                    // window ?????? ????????? ???????????? ??? ??????
        {
            // ?????? window ????????? ????????????, ?????? ??????
            if(rightIdx - leftIdx + 1 < minLen)
            {
                minLen = rightIdx - leftIdx + 1;
                minLeft = leftIdx;
            }


            // ?????? left index ??? ??????????????? ??????????????????
            char leftCh = str[leftIdx];
            leftIdx++;
            windowChars[leftCh]--;

            // left index ???????????? ??????, ?????? ?????? ???????????????
            // count ??? ?????????
            if(windowChars[leftCh] == 0) count--;
        }
    }

    return str.substr(minLeft, minLen);
}