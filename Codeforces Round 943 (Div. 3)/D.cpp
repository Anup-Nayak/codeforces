#include<iostream>
#include<bits/stdc++.h>
#include<cmath>
#include<unordered_map>

using namespace std;

#define ull long long

// ull findMaxIndex(ull n,ull pos, vector<ull> perm, vector<ull> arr){
//     ull maxi = INT_MIN;
//     ull index = 0;
//     for(ull i=0;i<n;i++){
//         if(arr[pos-1] > maxi){
//             maxi = arr[pos-1];
//             index = pos-1;
//         }
//         pos = perm[pos-1];
//     }
//     return index;
// }

// ull game(ull k, ull pos, vector<ull> perm, vector<ull> arr,ull maxIndex){
//     if(k==1){
//         return arr[pos-1];
//     }else if(pos == maxIndex+1){
//         return k*arr[pos-1];
//     }else{
//         return max(arr[pos-1]+game(k-1,pos,perm,arr,maxIndex),arr[pos-1]+game(k-1,perm[pos-1],perm,arr,maxIndex));
//     }
// }

ull solution(ull n,ull k, ull pos, vector<ull> perm, vector<ull> arr){
    vector<bool> visited (n,false);
    ull ans = 0;
    ull sum = 0;
    while(visited[pos-1] == false and k>0){
        visited[pos-1] = true;
        ans = max(ans, sum+k*arr[pos-1]);
        sum+= arr[pos-1];
        k--;
        pos = perm[pos-1];
    }
    return ans;
}

void solve(vector <string>& result){

    //inputs
    ull n,k,pb,ps;
    vector<ull> perm;
    vector<ull> arr;
    cin >> n >> k >> pb >> ps;
    for (ull i = 0; i < n; i++){
        ull temp;
        cin >> temp;
        perm.push_back(temp);
    }
    for (ull i = 0; i < n; i++){
        ull temp;
        cin >> temp;
        arr.push_back(temp);
    }

    //logic
    // ull maxIndex1 = findMaxIndex(n,pb,perm,arr);
    // ull maxIndex2 = findMaxIndex(n,ps,perm,arr);
    // ull score1 = game(k,pb,perm,arr,maxIndex1);
    // ull score2 = game(k,ps,perm,arr,maxIndex2);

    ull score1 = solution(n,k,pb,perm,arr);
    ull score2 = solution(n,k,ps,perm,arr);
    

    string ans;
    if(score1 > score2){
        ans = "Bodya";
    }else if(score2 > score1){
        ans = "Sasha";
    }else{
        ans = "Draw";
    }
    

    result.push_back(ans);

}

int main(){

    ull t;
    cin >> t;
    vector<string> result;

    while(t--){
        solve(result);
    };

    for(ull i = 0; i < result.size();i++){
        cout << result[i] << endl;
    }
    
    return 0;
}