#include<vector>
#include<algorithm>
using namespace std;


//This is O(NLogN) Solution, O(N) Solution also exists
pair<int,int> subarraySorting(vector<int> a) {

	// 정렬된 복사본을 먼저 생성하고
	vector<int> b(a);
	sort(a.begin(),a.end());
	

	//do comparison
	// 요소가 바뀐 영역을 확인한다
	int i = 0;
	int n = a.size();
	while(i<n && a[i]==b[i]){
		i++;
	}
	int j = a.size()-1;
	while(j>=0 && a[j]==b[j]){
		j--;
	}

	//already sorted
	if(i==a.size()){
			return {-1,-1};
	}
  return {i,j};
}

#include <vector>

using namespace std;


pair<int,int> MYsubarraySorting(vector<int> a){
    //Expected Optimal Complexity O(n) Time, O(1) Space
    //may be start with O(NLogN) and try to improve
    //complete this function
    
    
    int index = 0;
    pair<int, int> res{ a.size(), -1 };
    bool flag = false;

    while(index >= 0 && index < a.size()-1)
    {
        if(a[index] > a[index+1])
        {
            res.first = min(res.first, index);
            res.second = max(res.second, index + 1);
            flag = true;

            swap(a[index], a[index+1]);
            index--;
        }
        //else if(flag) break;
        else index++;
    }


    return (flag) ? res : make_pair(-1, -1);
}


#include <vector>
#include <deque>

using namespace std;


// O(N) complexity
pair<int,int> MYREALsubarraySorting(vector<int> a){
    //Expected Optimal Complexity O(n) Time, O(1) Space
    //may be start with O(NLogN) and try to improve
    //complete this function
    
    
    deque<int> dq{};
    dq.push_back(a[0]);

    int index = 1, leftIdx = 0, rightIdx = 0;
    while(index < a.size())
    {
        if(dq.back() < a[index])
        {
            leftIdx = index;
            dq.push_back(a[index]);
            index++;
        }
        else break;
    }

    if(dq.size() == a.size()) return {-1, -1};


    rightIdx = index;
    while(rightIdx + 1 < a.size() && a[rightIdx + 1] < dq.back())
        rightIdx++;

    while(!dq.empty() && dq.back() > a[rightIdx])
    {
        dq.pop_back();
        leftIdx--;
    }

    return {leftIdx + 1, rightIdx};
}


#include <iostream>
int main()
{
    vector<int> a = {4,3,2,1};

    auto res = subarraySorting(a);
    cout << res.first << "  :  " << res.second << endl;
}