#include <vector>
using namespace std;

// DNF algorithm

vector<int> MYsortBalls(vector<int> balls){
    //sort the balls in place in a single pass (O(N) time, O(1) space)
    
    int redIdx = 0, blueIdx = 0, greenIdx = balls.size()-1;

    while(blueIdx <= greenIdx)
    {
        int curInt = balls[blueIdx];

        if(curInt == 0)
        {
            swap(balls[redIdx], balls[blueIdx]);
            redIdx++;
            blueIdx++;
        }
        else if(curInt == 1)
        {
            blueIdx++;
        }
        else
        {
            swap(balls[blueIdx], balls[greenIdx]);
            greenIdx--;
        }
    }
    
    return balls;
}

vector<int> sortBalls(vector<int> a){
    //sort the balls in place
    int n = a.size();
    
    int s = 0;
    int e = n-1;
    int mid = 0;
    
    while(mid<=e){
        if(a[mid] == 0){
            swap(a[s++],a[mid++]);
        }
        else if(a[mid] == 1){
            mid++;
        }
        else{
            swap(a[mid],a[e--]);
        }
    }
    return a;
}