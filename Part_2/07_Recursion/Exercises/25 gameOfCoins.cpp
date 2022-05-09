#include <bits/stdc++.h>
using namespace std;

int game(int n, vector<int> v, int s, int e){

    // 2개만 남아도, 더 진행할 필요가 없구나
    // 어차피 서로 하나씩만 가져가니까
    if(s==e || s==e-1){
        return max(v[s],v[e]);
    }

    /* 
        내가 무언가 가져갔을 때

            상대방이 무언가 가져가고 나서
            이후 다시 내가 얻는 값을 생각
     */
    int op1=v[s] + min(game(n,v,s+2,e),game(n,v,s+1,e-1));
    int op2=v[e] + min(game(n,v,s+1,e-1),game(n,v,s,e-2));
    return max(op1,op2); 
}

int MaxValue(int n, vector<int> v){
    int res=game(n,v,0,n-1);
    return res;
}