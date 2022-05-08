#include<bits/stdc++.h>
using namespace std;

/* 
    배열을 부분배열들로 나누었을 때 - 부분 배열의 합 중 최대값에 대해서
        최대값의 최소는 얼마인가

    역시 똑같이 최대값이 될 수 있는 범위를 먼저 정하고
    
        모든 배열이 하나씩 나누어지는 경우 => 가장 큰 원소 값이 최대값
        모든 배열이 합쳐진 경우 => 모든 배열의 합이 최대값
        따라서, 요소중 최대값 ~ 모든 요소 총합 이 범위가 된다

    부분배열을 나누었을 때, 해당 최대값이 가능한 지 확인한다

        여기서도 어떤 부분 배열이 최대값 얼마를 가질 때 ~ 다른 건 어떻게 ~ 이런식으로
        케이스를 직접 확인하려 하니까 복잡해졌다

        실제 어떤 부분 배열의 합이 최대값 얼마를 가진다고 생각하지 않고
        최대값이 가능하다 => 모든 부분 배열의 합이 최대값을 넘지 않는다

        따라서 부분배열을 최대한 크게 모으면서
        동시에 최대값을 넘지 않게 부분 배열을 모은다

        정해진 조건에 맞춰서 부분배열을 모으고 나서
        나온 결과를 보고, 가능 여부를 따진다

    내가 헷갈렸던 부분이, 꼭 배열 합이 mid 인 부분배열이 존재해야 하고, 다른 부분 배열들의 합을 조사해야 한다고 생각한 것...

    디테일하게 들어가지 말고, 그냥 조건만 따졌어야 한다
    각 부분배열의 합이 mid 를 넘지 않는다
        그러면 부분배열 합이 mid 인 배열은 존재하지 않을 수 있지만
        어쨌든 최대값이 mid 인 경우를 만들 수는 있다

        진짜 부분배열 중 최대값이 mid 인 게 중요한게 아니고
        최대값이 mid 인 경우가 존재할 수 있다 ~ 그런 가능성이 존재할 수 있다
        는 것이 중요
        
        부분 배열의 합의 최대값이 mid 가 되려면, 정확한 경우는 알 수 없지만
        모든 부분 배열의 합이 mid 이하여야 한다 ~ <= 어떤 경우에도 참이 되어야 한다

    정해진 조건으로 따졌더니, 그런 경우가 가능하더라 ~
 */

bool isPossible(vector<int> &books,int m,int mid){
    
    int n = books.size();
    int cs = 0;
    int students = 1;
    
    for(int i = 0; i < n; i++){
        
        // 부분 배열의 합이 mid 를 넘어버리면
        // 이전까지를 하나의 부분 배열로 처리하고
        // 현재 값을 시작으로 새로운 부분배열을 만든다
        if(cs + books[i] > mid){
            students++;
            //cs = books[i];
            cs = 0;
            

            // 정해진 조건대로 진행했는데
            // 부분 배열이 너무 많이 만들어지면 => 원하는 경우가 불가능
            if(students > m)
            {
                return false;
            }
        }
        // 부분배열을 채워가는 데
        else{
            cs += books[i];
        }
    }
    
    return true;
}


int minPages(vector<int> books, int m){
    int n = books.size();
    //complete this code
    int end = 0;
    int start = 0;
    
    for(int b:books){
        end += b;
        start = max(start,b);
    }
    int result = INT_MAX;
    
    while(start<=end){
        int mid = (start + end)/2;
        if(isPossible(books,m,mid)){
            result = min(result,mid);
            end = mid - 1;
        }
        
        else{
            start = mid + 1;
        }
    }
    return result;
}