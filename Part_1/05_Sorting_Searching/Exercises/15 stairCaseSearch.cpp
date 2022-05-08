#include <vector>

using namespace std;


pair<int,int> search(int m, int n, vector<vector<int>> v, int k){
    
    int i=m-1;  // row 의 가장 마지막
    int j=0;    // col 의 첫번째
    // 좌측 하단에서 부터 검색을 시작한다

    /* 
    
        좌측 상단에서 시작하면, 어느 방향으로 가도 자신보다 값이 크니까
        방향을 정할 수가 없다
        
        좌측 하단에서 시작하면, 찾는 값보다 값이 크거나 작을 때, 가야하는 방향이 다르니까
        검색이 쉽다 쉬바
     */

    // 범위 내에 있는 동안
    while(j<n && i>=0){
        
        // 값 체크
        if(v[i][j]==k){
            break;
        }

        // 작으면 col 증가
        else if(v[i][j]<k){
            j++;
        }
        
        // 크면 row 감소
        else{
            i--;
        }
    }
    pair<int,int> p={i,j};
    return p;
}



pair<int,int> Mysearch(int m, int n, vector<vector<int>> v, int k){

    for(int row = 0; row < m; row++)
    {
        int colLeft = 0, colRight = n-1;

        if(v[row][colRight] < k) continue;


        while(colLeft <= colRight)
        {
            int mid = (colLeft + colRight) / 2;

            if(v[row][mid] == k) return {row, mid};
            else if(v[row][mid] < k)
                colLeft = mid + 1;
            else
                colRight = mid - 1;
        }
    }    

    return {-1, -1};
}