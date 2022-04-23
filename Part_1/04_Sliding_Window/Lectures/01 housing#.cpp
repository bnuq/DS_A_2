#include <vector>
#include <deque>
#include <climits>

using namespace std;


int shortestSubarray(vector<int>& nums, int k) 
{    
    vector<long> prefixSum(nums.size(), 0);
    prefixSum[0] = nums[0];
    for(int i = 1; i < nums.size(); i++)
    {
        prefixSum[i] = prefixSum[i-1] + nums[i];
    }


    int MinLength = INT_MAX;

    deque<int> d{}; // prefixSum 을 오름차순으로 저장하는 덱

    for(int i = 0; i < prefixSum.size(); i++)
    {
        // 일단 현재 인덱스인 0~i 까지 범위가 k 를 넘는 지 확인
        // 넘으면 0~i 범위가 최소 길이인지 확인
        if(prefixSum[i] >= k)
        {
            MinLength = min(MinLength, i+1);
        }

        /* 
            i 보다 앞에 있는 인덱스들에 대해서 하나씩 조사
            prefixSum[i] - prefixSum[j] = [j+1, i] 범위 내의 요소들의 합
            이 합이 k 보다 큰 지, 크지 않은 지를 조사한다

            근데 다 조사하면 O(N^2) 복잡도
            다 조사하는 건 피하고 싶다

            조사하려는 게
            prefixSum[i] - prefixSum[j] >= k 이므로

            prefixSum[j] 가 작을수록 충족할 확률이 높고
            조사해야할 확률이 높다
            따라서 작은 것 부터 넣는다

            만약 prefixSum[i] - prefixSum[j] >= k 가 성립한다면,
            prefixSum[j] 로 만들 수 있는 가장 작은 subarray 는 i 에 의해 생김
            그 뒤의 인덱스에서도 생길 수 있지만 i 로부터 생기는 것이 가장 작다
            따라서 j 에 대해서는 더이상 조사하지 않는다

            조사를 마친 후에는, prefixSum[i] 를 deque 에 넣어서
            다음번 조사 때 사용할 건데
            만약 deque 에 현재 prefixSum[i] 보다 큰 값이 있다면
            계산 시 i 를 사용해도 충분히 k 보다 크게 나올 수 있으며
            위치도 i 쪽 을 사용하는 게 더 짧기 때문에
            기존에 deque 에 있는 것을 사용할 이유가 없다
            따라서 제거한다
            */

        while (d.size() > 0 && prefixSum[i] - prefixSum[d.front()] >= k)
        {
            MinLength = min(MinLength, i - d.front());
            d.pop_front();
        }

        while(d.size() > 0 && prefixSum[i] <= prefixSum[d.back()])
        {
            d.pop_back();
        }


        // 이번에 조사한 prefixSum[i] 를 덱에 넣어
        // 다음 번 조사에서 사용하도록 한다
        d.push_back(i);
    }

    return (MinLength == INT_MAX) ? -1 : MinLength;
}