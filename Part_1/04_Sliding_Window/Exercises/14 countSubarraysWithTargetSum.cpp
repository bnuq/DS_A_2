#include <vector>
#include <unordered_map>

using namespace std;


int cntSubarrays(vector<int>arr,int sum){
    //complete this method
    unordered_map<int, int> prevSum;
    int n = arr.size();
    int res = 0;
 
    // Sum of elements so far.
    int currsum = 0;
 
    for (int i = 0; i < n; i++) {
 
        // Add current element to sum so far.
        currsum += arr[i];
 
        // If currsum is equal to desired sum,
        // then a new subarray is found. So
        // increase count of subarrays.
        if (currsum == sum)
            res++;
 
        // currsum exceeds given sum by currsum
        //  - sum. Find number of subarrays having
        // this sum and exclude those subarrays
        // from currsum by increasing count by
        // same amount.
        if (prevSum.find(currsum - sum) != prevSum.end())
            res += (prevSum[currsum - sum]);
 
        // Add currsum value to count of
        // different values of sum.
        prevSum[currsum]++;
    }
 
    return res;
}



int cntSubarrays(vector<int> arr,int k)
{
    vector<int> prefixSum(arr.size(), 0);
    prefixSum[0] = arr[0];
    for(int i = 1; i < prefixSum.size(); i++)
        prefixSum[i] = prefixSum[i-1] + arr[i];


    unordered_map<int, int> uom{};
    int res = 0;


    for(int i = 0; i < prefixSum.size(); i++)
    {
        // [0, i] 범위의 총 합이 k 인 경우
        // 바로 원하는 범위를 찾았다
        if(prefixSum[i] == k) res++;
        

        // 이전에 찾은 값들 중에 마이너스가 있을 수 있으므로
        // 이번에 찾은게 원하는 범위였어도 또 확인을 한다
        if(uom.find(prefixSum[i] - k) != uom.end())
        {
            res += uom[prefixSum[i] - k];
        }

        uom[prefixSum[i]]++;
    }

    return res;
}