#include <iostream>
#include <climits>

using namespace std;


pair<int, int> housing(int *arr,int n,int k){

    // Sliding Window 의 양 끝 범위, [i, j]
    int i=0;
    int j= 0;

    int cs = 0; // current sum

    // 범위 길이를 저장
    int WindowSize = INT_MAX;
    pair<int, int> res{};

    
    // 윈도우 첫 범위와 끝 범위가 모두
    // 배열을 벗어나지 않는 동안에
    while(i >= 0 && j < n)
    {
        
        // expand to right
        // 윈도우 한칸 증가
        // 일단 전체 범위를 조사해야 하니까, 오른쪽 범위가 1 증가 하는 건 맞아
        cs += arr[j];


        // remove elements from the left till cs > sum and i<j
        // 여기서 한번에, current sum 이 원하는 값을 넘지 않게
        // 범위를 여러 개 줄인다
        while(cs > k && i < j){
            cs = cs - arr[i];
            i++;
        }


        // 범위 조정 후 원하는 값이 됐는 지 확인
        if(cs==k){
            //print that window
            cout<< i <<" - "<< j <<endl;

            // smallest window that contains the reqd sum
            // 범위 내 합이 원하는 값이면서, 동시에 그 범위 길이가
            // 가장 짧은 것을 기록해둔다
            if(WindowSize > (j - i + 1))
            {
                WindowSize = j - i + 1;
                res = {i, j};
            }
        }

        // 다음 반복을 위해 범위 증가
        j++;
    }

    return res;
}

int main() {

    
    // handle if you have negative integers in the arrays 

    int plots[] = { 1 ,3 ,2 ,1 ,4, 0, 0, 0, 1 ,3 ,2 ,1 ,1};
    int  n = sizeof(plots)/sizeof(int);
    int k = 8;



    auto res = housing(plots,n,k);
    cout << "The Smallest Ragne is " << res.first << " : " << res.second << endl;

    return 0;
}