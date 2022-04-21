#include<vector>
#include<algorithm>
#include<climits>
using namespace std;



pair<int,int> MyminDifference(vector<int> a,vector<int> b){
    
    // 주어진 배열을 일단 정렬한다
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    pair<int, int> res{};
    int minDiff{INT_MAX};

    
    size_t aIdx{ 0 }, bIdx{ 0 };

    while (aIdx < a.size() && bIdx < b.size())
    {
        // 일단 둘의 차이를 조사
        if(abs(a[aIdx] - b[bIdx]) < minDiff)
        {
            minDiff = abs(a[aIdx] - b[bIdx]);
            res = {a[aIdx], b[bIdx]};
        }

        // 두 값의 차이를  줄여야 하므로, 큰 값을 낮추던지 작은 값을 키우던지 해야 한다
        // 지금 오름차순으로 정렬되어 있으니까, 작은 값부터 조사중
        // 따라서 작은 값을 키운다
        if(a[aIdx] < b[bIdx]) aIdx++;
        else bIdx++;
    }
    

    return res;
}




pair<int,int> minDifference(vector<int> a1,vector<int> a2){

    // 일단 배열 하나만 정렬
	sort(a2.begin(),a2.end());


	vector<int> result;

	
	int p1,p2;
	
	int diff = INT_MAX;
	

    //iterate over 1 and do binary search
    // 첫 번째 배열에서만 조사를 진행한다
	for(int x : a1){

        // lower_bound => 주어진 범위에서, 주어진 값보다, 처음으로 작지 않은 값의 위치를 리턴
        // lb = lower bound 검색 위치
        // 검색 대상인 배열은 정렬되어 있다
        // 없으면 a2.end() iterator 를 리턴, 끝까지 찾았다는 뜻
		auto lb = lower_bound(a2.begin(),a2.end(),x) - a2.begin();

        // 현재, lb - x 의 값이 가장 차이가 작을 것이라 생각

        // lower bound 로 찾은 요소보다, 그 앞의 값과의 차이가 더 작을 때
        if(lb>=1 && x - a2[lb-1] < diff){

            // 더 작은 차이를 diff 로 넣고    
            diff = x - a2[lb-1];

            // diff 를 만드는 두 값을 저장
            p2 = a2[lb-1];
            p1 = x;
        }


        // lower bound 로 찾은 요소와 x 의 차이를 계산
        if(lb!=a2.size() && a2[lb]-x < diff ){
            diff = a2[lb] - x;
            p1 = x;
            p2 = a2[lb];
        }
	}
	
  return {p1,p2};
}







#include <iostream>
int main()
{
    vector<int> a{23, 5, 10, 17, 30};
    vector<int> b{26, 134, 135, 14, 19};
    

    auto res = minDifference(a, b);
    cout << res.first << ":" << res.second << endl;
}