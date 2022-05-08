#include<bits/stdc++.h>
using namespace std;

/* 
    동전의 값을 나누었을 때, 각 경우 최소값이 존재
        그 최소값 중, 최대값을 구하라

    접근 방법
        나올 수 있는 최소 값의 범위를 확인
        어떤 최소값이 나오는 것이 가능한지 확인
        최소값이 나올 수 있는 범위를, Binary Search 를 통해서 줄여가며 확인

    배열을 나누는 데, 최소값이 존재하는 것이 가능한지 확인하는 방법
        그 값이 최소값일 때의 특정한 경우를 찾는 것이 아니다
        그 값이 최소값인 게 가능한 경우가 존재하는 지를 찾는 것
            나눈 모든 부분 배열의 합이 최소값 이상이다 로 판단
 */


/* 
    배열을 나누었을 때, 부분집합의 합이 모두 limit 이상인 경우가
    단 한가지라도 존재하는 지 확인하는 함수
 */
bool divideAmongK(vector<int> arr,int n,int k,int limit){
    //return true if every partition gets atleast limit no of coins

    int cnt = 0;
    int current_sum = 0;
    
    /* 
        항상 배열의 앞부분부터 부분집합을 만들지는 않겠지만
        나는 이런 경우가 존재하는 경우 하나만 찾으면 된다

        무조건 앞에서부터 부분집합 만들기

        실제로 배열을 나누었을 때, 부분 집합의 합의 최소값이 limit 다 - X
        부분 배열의 최소값을 limit 로 만들고 나머지를 나눈다 - X

        부분집합의 합이 limit 이상이 되도록 배열을 나누는 것이 가능한 경우가 있는 지 찾는다 - O
        정확한 케이스에 대해서 알 필요 없고, 그냥 가능한 지만 확인한다 - O
     */
    for(int i=0; i<n; i++)
    {
        // 더하기 전에 확인
        // 정해진 limit 이상이 되면, 여기까지로 부분배열을 나눈다
        if(current_sum + arr[i] >=limit)
        {
            cnt +=1;
            // 다음 찾는 부분에서부터는 다시 새로운 부분배열
            current_sum = 0;
        }
        else
        {
            // limit 보다 커질 때까지 값을 더한다
            current_sum += arr[i];
        }
    }
    
    /* 
        실제로 어떻게 나누어지는 지는 전혀 모른채
        일단 정해진 조건대로 배열을 무조건 나눴다

        이후, 나눠진 배열의 개수를 확인
        => 정해진 배열보다 개수가 많으면, 
            실제로 이렇게 나눌 수는 없지만 많이 나눠진 배열은 다시 합치면 되니까
            아무튼 가능하다는 걸 알수 있다
            return true

        => 정해진 개수보다 배열이 적다면
            문제의 조건대로 나눌 수 없다는 뜻
            가능한 경우가 하나도 없다, 불가능
            return false
     */
    return cnt>=k;
}


int getCoins(vector<int> arr,int k){
    //return the minimum number
    int n = arr.size();

    /* 
        최소값이 될 수 있는 가능한 범위
        0 부터 동전의 모든 합까지
     */
    int e = 0;
    int s = 0;
    for(int i=0;i<n;i++){
        e += arr[i];
    }
    //mid
    int mid;
    int ans;

    //search range (s,e)
    // Binary Search 를 통해서, 확인하고 범위를 재조정한다
    while(s<=e){
        mid = (s+e)/2;
         
        // 배열을 나눌 때, mid 값 이상으로 나누는 경우가 존재하는 지 확인
        // 그런 경우가 한번이라도 존재하면 된다
        bool isPossible = divideAmongK(arr,n,k,mid);

        // 가능하다면, 일단 mid 값을 저장
        // 범위를 올려 => 더 큰 값에 대해서도 가능한 경우가 존재하는 지 확인
        if(isPossible){
            s = mid + 1;
            ans = mid;
        }

        // 불가능하다면, 범위를 더 작은 값의 범위로 낮춘다
        else{
            e = mid - 1;
        }
    }
    return ans;
}