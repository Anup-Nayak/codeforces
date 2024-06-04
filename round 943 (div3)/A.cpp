#include<iostream>
#include<bits/stdc++.h>
#include<cmath>
#include<unordered_map>

using namespace std;

void solve(vector <int>& ans){
    int n;
    cin >> n;
    ans.push_back(n-1);
}

int main(){

    int t;
    cin >> t;
    vector <int> ans;
    while(t--){
        solve(ans);
    };

    for(int i = 0; i < ans.size();i++){
        cout << ans[i] << endl;
    }
    return 0;
}