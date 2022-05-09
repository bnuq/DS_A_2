#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool calc(int n, vector<vector<char>> c, vector<int> &v, int i = 0, int j = 0)
{
    // 목표에 도착
    if(i==n && j==n) return true;

    // 오른쪽이나 왼쪽으로 가다가 결국 경계를 벗어남
    if(i==n+1 || j==n+1) return false;

    
    // 오른쪽 이동이 가능한지 체크
    if(j != n && c[i][j+1] != 'X')
    {
        // 오른쪽 이동했을 때, 경로가 있는 지 확인
        // 경로에 포함이되면 참
        if(calc(n, c, v, i, j+1))
        {   
            // 경로에 포함된 걸 확인하고 참 리턴
            v.push_back( (i)*(n+1) + j+2 );
            return true;
        }
    }

    if(i != n && c[i+1][j] != 'X')
    {
        if(calc(n, c, v, i+1, j))
        {
            v.push_back( (i+1)*(n+1) + j+1 );
            return true;
        }
    }

    return false;
}

vector<int> findPath(int n, vector<vector<char>> c)
{
    vector<int> v;
    calc(n-1,c,v);
    v.push_back(1);

    // push back 으로 역순으로 넣어서, 나중에 한번 뒤집어
    reverse(v.begin(), v.end());
    return v;
}


// 내게 더 알아보기 쉬운 듯 솔직히
namespace myCode
{
    #include <vector>

    using namespace std;

    bool helper(int n, vector<vector<char>>& map, int row, int col, int destRow, int destCol, vector<int>& path)
    {
        // 현재 위치 방문
        path.push_back(n * row + col + 1);

        if(row == destRow && col == destCol)
        {
            return true;
        }


        // 오른쪽 방문
        pair<int, int> rightPos = {row, col + 1};
        if(rightPos.second < n && map[rightPos.first][rightPos.second] == 'O')
        {
            if(helper(n, map, rightPos.first, rightPos.second, destRow, destCol, path))
                return true;
        }

        
        // 아랫쪽 방문
        pair<int, int> downPos = {row+1, col};
        if(downPos.first < n && map[downPos.first][downPos.second] == 'O')
        {
            if(helper(n, map, downPos.first, downPos.second, destRow, destCol, path))
                return true;
        }

        
        // 방문을 모두 실패하면 path 에서 자신 제거
        path.pop_back();

        return false;
    }


    vector<int> findPath(int n, vector<vector<char>> c)
    {
        ////Write your code below. Do not modify this function or parameters. You can use helper function if needed.   

        vector<int> path{};
        if(helper(n, c, 0, 0, n-1, n-1, path))
            return path;
        else return {};
    }
} // namespace myCode
