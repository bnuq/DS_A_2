#include<bits/stdc++.h>
using namespace std;


// 인덱스 [i, j) 범위의 값을 더하는 함수
int sum(vector<int> v, int i, int j)
{
    int res = 0;
    for (int k = i; k < j; k++) res += v[k];
    return res;
}


// recursion 을 위한 재귀함수
int calc(vector<int> v, int s, int e, int k)
{
    // 엥 start 가 한칸 앞에 있어도 괜찮아?
    //if (e - s + 1 < 0)
    if(s > e) // 이거 아닌가
    {
        return 0;
    }


    // 이번에 얻을 수 있는 최대 이익
    int res = INT_MIN;

    // 앞에서 i 개를 취한다고 생각할 때
    for (int i = 0; i <= k; i++)
    {
        // 앞에서 i 개, 뒤에서 k-i 개 를 선택해서 얻는 값
        int ans = sum(v, s, s + i) + sum(v, e - k + i + 1, e + 1);

        // 상대방 선택 차례, 상대방 선택 후 내가 얻는 최소 값
        int op = INT_MAX;

        // 상대방도 똑같이 j 개 앞에서 취하고, k-j 개 뒤에서 취할 때
        for (int j = 0; j <= k; j++)
        {
            // 그 후, 내가 얻을 수 있는 최소 값을 구한다
            op = min(op, calc(v, s + i + j, e - k + i - k + j, k));
        }


        // 이번 선택에서 내가 얻는 값이, 최대 값인지 확인
        res = max(res, ans + op);
    }

    return res;
}
int MaxValue(int n, vector<int> v, int k){
    int res=calc(v,0,n-1,k);
    return res;
}


namespace myCode
{
    #include <vector>
    #include <climits>

    using namespace std;


    /* 
        내가 k 개 가져올 수 있는 모든 경우를 조사
        내가 어떤 방법으로 코인을 k 개 가져왔을 때 -

            상대방도 똑같이 k 개 가져갈 수 있다
            상대방이 가져갈 수 있는 모든 경우를 조사

            상대방은 이후 내 이득이 가장 적을 때의 방법으로 가져갈 것이다
            이후 내가 가장 적게 얻게 되는 이득을 조사

        k 개 가져온 이득과, 이후 내가 가장 적게 얻은 이득을 더하면
        이번에 가져온 방법으로 얻는 총합
        이 총합이 가장 큰 값을 리턴한다
    */
    int helper(vector<int>& Val, int sIdx, int eIdx, int k)
    {
        // base case
        if(sIdx > eIdx) return 0;

        int myMaxRes = INT_MIN;     // 최대 이득
        


        // k 개 가져올 수 있는 모든 경우를 조사
        for(int i = 0; i <= k; i++)
        {
            int res = 0;            // 이번 경우에 얻는 나의 이득
            int frontGet = i;       // 앞에서 i 개 가져가고
            int backGet = k - i;    // 뒤에서 k-i 개 가져갈 때

            // 일단 앞에서 가져가고
            for(int s = 0; s < frontGet; s++)
                res += Val[sIdx + s];

            // 뒤에서 가져가
            for(int e = 0; e < backGet; e++)
                res += Val[eIdx - e];


            // 이제 이후 상대방이 가져가는 경우를 생각
            int enemyStartIdx = sIdx + frontGet;
            int enemyEndIdx = eIdx - backGet;
            int afterMyMinRes = INT_MAX;

            for(int j = 0; j <= k; j++)
            {
                int enemyFrontGet = j;
                int enemyBackGet = k - j;


                // 적이 가지고 간 후, 이후 얻게 되는 나의 이득을 조사
                int temp = helper(Val, enemyStartIdx + enemyFrontGet,
                enemyEndIdx - enemyBackGet, k);

                // 이후의 나의 이득이 가장 작을 때의 값을 구한다
                if(temp < afterMyMinRes) afterMyMinRes = temp;
            }


            // 내 선택에 의한 이득과, 적 선택 이후 얻게 되는 나의 최소 이득을 더한다
            res += afterMyMinRes;

            // 이번 경우 내 이득이 최대이면 저장한다
            if(res > myMaxRes) myMaxRes = res;
        }

        
        // 내가 얻을 수 있는 최대값을 리턴
        return myMaxRes;
    }


    int MaxValue(int n, vector<int> v, int k){
    //Write your code here. Do not modify the function or parameters. You can use a helper function if needed.
        
        return helper(v, 0, n-1, k);
    }


    #include <iostream>
    int main()
    {
        cout << MaxValue(6, {10, 15, 20, 9, 2, 5}, 2) << endl;
    }
} // namespace myCode
