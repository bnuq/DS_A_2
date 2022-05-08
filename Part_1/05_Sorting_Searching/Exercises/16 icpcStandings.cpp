#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int MYbadness(vector<pair<string,int> > teams){
    
    int PeopleNum = teams.size();

    vector<int> prefRank{};
    vector<int> realRank(PeopleNum + 1, 0);

    for(auto i : teams)
    {
        if(realRank[i.second] == 0)
            realRank[i.second]++;
        else
            prefRank.push_back(i.second);
    }

    sort(prefRank.begin(), prefRank.end());

    int answer = 0, prefIdx = 0;
    for(int i = 1; i < realRank.size(); i++)
    {
        if(realRank[i] == 1) continue;

        answer += abs(i - prefRank[prefIdx]);
        prefIdx++;
    }
    
    return answer;
}



int badness(vector<pair<string,int> > teams){
    
    int n = teams.size();
    
    //create a count array init with 0
    vector<int> cnt(n+1,0);
    
    // 써놓은 등수 개수를 파악한다
    // 등수를 인덱스로 사용 => 정렬할 필요 없이, 바로 1 => 큰수로 접근 가능
    for(int i=0;i<n;i++){
        cnt[teams[i].second]++;
    }
    
    int pos = 1;
    int sum = 0;


    // sorting 할 필요도 없어
    for(int i = 1; i <= n; i++) // 전체 구간을 조사하는 데
    {
        // 하나라도 써 놓은 게 존재한다면
        while(cnt[i])
        {
            // position 자리에 i 가 들어가고 badness 조사
            sum += abs(pos-i);

            // 개수 줄이고
            cnt[i]--;

            // 자리에 들어갔으니, 자리 증가
            pos++;
        }
    }
       
    return sum;
}

