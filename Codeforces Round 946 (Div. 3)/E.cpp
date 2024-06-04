#include<iostream>
#include<bits/stdc++.h>
#include<cmath>
#include<unordered_map>

using namespace std;

void solve(vector <int>& result){
    int m,x;
    cin >> m >> x;
    vector<int> cost;
    vector<int> hap;
    for(int i = 0;i<m;i++){
        int c,h;
        cin >> c >> h;
        cost.push_back(c);
        hap.push_back(h);
    }

    
}

int main(){

    int t;
    cin >> t;
    vector<int> result;

    while(t--){
        solve(result);
    };

    for(int i = 0; i < result.size();i++){
        cout << result[i] << endl;
    }
    return 0;
}