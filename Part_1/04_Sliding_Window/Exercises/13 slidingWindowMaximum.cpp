#include<vector>
#include<deque>
using namespace std;

vector<int> maxInWindow(vector<int> a,int k){

    //Algorithm
    vector<int> output;
    int n = a.size();

    // queue 로서 deque 를 사용
    deque<int> Q(k);


    //1. Process only the first K elements
    // 일단 처음에 있는 원소들 처리  
    int i;

    for(i=0;i<k;i++){
        //Logic here ...

        // 큐 내에 내림차순으로 값을 가지는 인덱스를 저장한다
        while(!Q.empty() && a[i] > a[Q.back()]){
            Q.pop_back();
        }

        Q.push_back(i);

    }

    //2. Remaining the elements of the array
    for( ;i<n;i++){
        //cout << a[Q.front()]<<" ";

        // 일단 큐의 가장 앞에 있는, 가장 큰 값을 넣어?
        output.push_back(a[Q.front()]);
        
        //Remove element from the left (contraction when an index lies outside the current window)
        // 가장 큰 값을 가지는 인덱스가 범위를 벗어나 있으면 제거
        while(!Q.empty() && Q.front() <=i-k){
            Q.pop_front();
        }

        // 현재 값을 큐 내에서 내림차순으로 저장
        while(!Q.empty() && a[i] >= a[Q.back()]){
            Q.pop_back();
        }

        //always
        // 이번에 조사한 인덱스를 항상 큐에 넣는다
        Q.push_back(i);
    }


    output.push_back(a[Q.front()]);
    return output;

}



#include <vector>
#include <deque>

using namespace std;


vector<int> maxInWindow(vector<int> input,int k){
    
    /* 
        deque 에 내림차순으로 저장을 하는 거지

        가장 앞에 있는 값 => 지금까지 조사한 값 중 가장 큰 값

        먼저 가장 큰 값이 => 조사하려는 인덱스 안에 있는 지 확인
        조사 범위 밖이면 => 없애

        그래서 앞에 있는 값과 현재 값을 비교
        현재 값이 더 크면 => 덱을 비우고 현재 값 저장
        앞에 있는 값이 더 크면 => 덱의 뒤 값을 확인
            현재 값이 내림차순이 될 수 있게 더 작은 값은 빼고
            현재 값 넣어
     */
    
    deque<pair<int, int>> dq{}; // { 인덱스, 값 }
    vector<int> res{};

    // 일단 k 개 전까지 deque 를 채워놔
    for(int i = 0; i < k-1; i++)
    {
        if(dq.empty()) dq.emplace_back(i, input[i]);
        else
        {
            if(input[i] > dq.front().second)
            {
                dq.clear();
                dq.emplace_back(i, input[i]);
            }
            else
            {
                while(dq.back().second < input[i])
                {
                    dq.pop_back();
                }

                dq.emplace_back(i, input[i]);
            }
        }
    }


    // 이제 리턴할 벡터를 채운다
    for(int i = k-1; i < input.size(); i++)
    {
        // 먼저 덱에 있는 값이 조사 범위인지를 확인한다
        while(!dq.empty() && dq.front().first + k <= i)
            dq.pop_front();

        // 덱이 비어버렸다면 => 안 빌거 같은데
        //if(dq.empty()) dq.emplace_back(i, input[i]);

        // 현재 조사하는 값이 덱에 저장해둔 값보다 크다면
        if(input[i] > dq.front().second)
        {
            // 현재 값이 현재 범위에서 가장 큰 값
            res.push_back(input[i]);

            // 덱 초기화
            dq.clear();
            dq.emplace_back(i, input[i]);
        }
        // 덱이 있는 값이 더 크다
        else
        {
            res.push_back(dq.front().second);

            // 현재 값을 덱의 적절한 위치에 저장한다
            while(dq.back().second < input[i])
            {
                dq.pop_back();
            }

            dq.emplace_back(i, input[i]);
        }
    }
    
    
    return res;    
}



#include <iostream>
int main()
{
    vector<int> input = {1,2,3,1,4,5,2,3,6};
    vector<int> res = maxInWindow(input, 3);

    for(auto x : res)
        cout << x << endl;
}