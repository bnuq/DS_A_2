#include<vector>
using namespace std;



/* 
    Expected Complexity O(N)

    각 요소마다, 전체 요소를 조사해야 하니까, 반드시 N^2 이 필요할 거 같은데
    어떻게 O(N) 에 해결하느냐
 */
vector<int> productArray(vector<int> arr){
    int n = arr.size();
    
    // Base case
    // 배열 크기가 1 이여서, 다른 곱할 요소가 없다
    if (n == 1) {
        return {0};
    }
 

    
    int i, temp = 1;
    // 곱한 결과를 저장하는 배열
    // 핵심 => 하나의 배열을 2번 왔다 갔다 한다
    vector<int> prod(n,1);


    /* 
        첫번째 루프
        
        In this loop, temp variable contains product of
        elements on left side excluding arr[i]

        자신을 제외한, 자신의 왼쪽에 있는 요소들의 전체 곱을 저장
     */
    for (i = 0; i < n; i++) {
        prod[i] = temp;
        temp *= arr[i];
    }
 

    /* Initialize temp to 1
    for product on right side */
    temp = 1;
 


    /* 
        두번째 루프

        In this loop, temp variable contains product of
        elements on right side excluding arr[i] 

        자신을 제외한, 자신의 오른쪽에 있는 요소들의 전체 곱을 저장
     */
    for (i = n - 1; i >= 0; i--) {
        prod[i] *= temp;
        temp *= arr[i];
    }


    // 루프를 두번 돌았더니, 자신을 제외한 곱을 얻을 수 있었다
    return prod;
}