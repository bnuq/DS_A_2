#include<vector>
#include<algorithm>
using namespace std;

bool compare(pair<int,int> v1, pair<int,int> v2){
    return v1.second < v2.second;
}


int countActivites(vector<pair<int,int> > v)
{
    // 끝나는 시간 순서로 정렬을 한다
    sort(v.begin(),v.end(),compare);
    
    // 일단 무조건 첫번째 활동은 진행
    int count = 1;
    int finish = v[0].second;
    
    /* 
        Greedy Algorithm
        
        바로바로 진행할 수 있는 활동들을 진행
        그냥 빨리 끝나는 것들을 바로바로 이어서 할 수 있으면
        최대한 많은 활동을 할 수 있다
     */
    for(int i=1; i<v.size(); i++){
        if(v[i].first>=finish){
            count++;
            finish = v[i].second;
        }
    }
    return count;
}



              -----  
---------------------
        ---
        -------------
                ---
          -----  
0 1 2 3 4 5 6 7 8 9 10


#include <vector>
#include <algorithm>
using namespace std;


/* 
    Greedy Algorithm
    
    모든 활동 중에서, 가장 빨리 끝나는 활동을 찾고
    실행할 수 있는 활동 중에서, 가장 빨리 끝나는 것을 먼저실행한다
    
    최대한 많은 걸 하려면
    빨리 끝나는 것들을 해치워야 하니까?
 */
int MycountActivites(vector<pair<int,int> > activities){

    sort(activities.begin(), activities.end(), [](auto& p1, auto& p2)
    {
        return p1.second < p2.second;
    });

    int res{ 0 };

    int endTime = activities[0].second;
    res++;

    for(int i = 1; i < activities.size(); i++)
    {
        pair<int,int> curAct = activities[i];

        if(curAct.first >= endTime)
        {
            endTime = curAct.second;
            res++;
        }
    }


    return res;
}