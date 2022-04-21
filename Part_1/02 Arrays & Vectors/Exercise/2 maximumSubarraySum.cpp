#include<vector>
using namespace std;

int maxSubarraySum(vector<int> arr){
    //Complete this function, your function should return the maximum subarray sum
    int n = arr.size();
    int cs = 0;     // current sum
    int ms = 0;     // maximum sum
    
    // 전체 배열 조사
    for(int i=0;i<n;i++){

        // 이번 요소를 더하고
        cs += arr[i];

        // 최대 합이 되는 지 확인
        ms = max(ms,cs);

        // 이번 합이 마이너스 였다면, 앞으로도 계속 손해만 될 뿐
        // 합을 구하는 범위에서 빼야한다
        // 구간을 따로 설정하는 게 아니고, 그냥 current sum 을 0으로 만들면
        // 지금까지 더했던 구간이 사라지는 효과
        // 시바 존나 간단했네
        if(cs<0){
            cs = 0;
        }
    }
    return ms;
}


int MymaxSubarraySum(vector<int> arr){
    //Complete this function, your function should return the maximum subarray sum
    int n = arr.size();
    
    
    vector<int> prefixSum(n, 0);
    for (size_t i = 0; i < n; i++)
    {
        if(i == 0) {
            prefixSum[0] = arr[0];
        }
        else
            prefixSum[i] += prefixSum[i-1] + arr[i];
    }
    
    
    int maximum{0};
    int startIdx{0};

    for (size_t endIdx = 0; endIdx < n; endIdx++)
    {
        int temp{};
        if(startIdx == 0)
        {
            temp = prefixSum[endIdx];
        }
        else
        {
            temp = prefixSum[endIdx] - prefixSum[startIdx-1];
        }
        
        if(temp < 0)
        {
            startIdx = endIdx + 1;
        }
        else
        {
            maximum = max(maximum, temp);
        }
    }
    
    return maximum;
}