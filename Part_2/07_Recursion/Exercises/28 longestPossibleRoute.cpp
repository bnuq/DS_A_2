#include<bits/stdc++.h>
using namespace std;


// 성공실패 여부와 길이를 모두 제공하기 위해서
// pair 를 리턴
pair<bool,int> findPath(int m,int n, int i, int j, vector<vector<int>> v, bool mat[][100]){
    
    // 도착
    if(i==m-1 && j==n-1){
       
        pair<bool,int> p={true,0};
        return p;
    }

    // 혹시나 하는 경계 벗어나는 것 확인
    if(i>=m || i<0 || j>=n || j<0 ){
        
        pair<bool,int> p={false,-1};
        return p;
    }
    else{
       
       // 경로를 찾기 전에 현재 위치 밟는 걸 먼저 진행
        // 현재 위치 밟고
        mat[i][j]=true;
        pair<bool,int> res={false,-1};
        

        // 각 방향별로 경로가 존재하는 지 확인
    
        // 오른쪽 이동
       if(i<m-1 && v[i+1][j]==1 && mat[i+1][j]==false){

           // 재귀를 먼저 호출, 경로가 존재하는 지 확인
            pair<bool,int> p1=findPath(m,n,i+1,j,v,mat);

            // 경로가 존재하는 경우에만, 길이를 측정
            if(p1.first){
                res.first=true;
                res.second=max(res.second,p1.second);
            }
       }

       // 아래쪽 이동
       if(j<n-1 && v[i][j+1]==1 && mat[i][j+1]==false){
            pair<bool,int> p2=findPath(m,n,i,j+1,v,mat);
            if(p2.first){
                res.first=true;
                res.second=max(res.second,p2.second);
            }
       }

       // 위쪽 이동
       if(i>0 && v[i-1][j]==1 && mat[i-1][j]==false){
            pair<bool,int> p3=findPath(m,n,i-1,j,v,mat);
            if(p3.first){
                res.first=true;
                res.second=max(res.second,p3.second);
            }
       }

       // 왼쪽 이동
       if(j>0 && v[i][j-1]==1 && mat[i][j-1]==false){
           pair<bool,int> p4=findPath(m,n,i,j-1,v,mat);
           if(p4.first){
               res.first=true;
               res.second=max(res.second,p4.second);
           }
       }

        // 다 찾은 후에 경로 밟은 것 취소
       mat[i][j]=false;

        // 경로를 못 찾은 경우, 0 리턴
       res.second+=1;
       return res;
    }
}


int findLongestPath(int m, int n, vector<vector<int>> v){
    bool mat[100][100]={{0}};
    
    pair<bool,int> p=findPath(m,n,0,0,v,mat);
    return p.second;
}


namespace myCode
{
    #include <vector>

using namespace std;

int helper(int m, int n, vector<vector<int>>& map, vector<vector<bool>>& check, int row, int col)
{
    if(row == m-1 && col == n-1) return 0;
    

    int pathMax = -1;

    // 위쪽 이동
    if(row - 1 >= 0 && map[row - 1][col] == 1 &&check[row - 1][col] == false)
    {
        check[row - 1][col] = true;
        pathMax = max(pathMax, helper(m, n, map, check, row - 1, col));
        check[row - 1][col] = false;
    }

    // 아래쪽 이동
    if(row + 1 < m && map[row + 1][col] == 1 && check[row + 1][col] == false)
    {
        check[row + 1][col] = true;
        pathMax = max(pathMax, helper(m, n, map, check, row + 1, col));
        check[row + 1][col] = false;
    }

    // 오른쪽 이동
    if(col + 1 < n && map[row][col + 1] == 1 && check[row][col + 1] == false)
    {
        check[row][col + 1] = true;
        pathMax = max(pathMax, helper(m, n, map, check, row, col + 1));
        check[row][col + 1] = false;
    }

    // 왼쪽 이동
    if(col - 1 >= 0 && map[row][col - 1] == 1 && check[row][col - 1] == false)
    {
        check[row][col - 1] = true;
        pathMax = max(pathMax, helper(m, n, map, check, row, col - 1));
        check[row][col - 1] = false;
    }

    if(pathMax == -1) return -1;
    else return pathMax + 1;
}



int findLongestPath(int m, int n, vector<vector<int>> v){
    //Complete this function. Do not modify the name or parameters. You can make a helper function if needed.

    vector<vector<bool>> check(m, vector<bool>(n, false));
    check[0][0] = true;

    return helper(m, n, v, check, 0, 0);
}

} // namespace myCode
