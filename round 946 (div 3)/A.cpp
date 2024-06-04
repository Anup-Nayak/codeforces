#include<iostream>
#include<bits/stdc++.h>
#include<cmath>
#include<unordered_map>

using namespace std;

void solve(vector <int>& result){
    double x,y;
    cin >> x >> y;
    int ans = 0;
    double two = ceil(y/2);
    
    double left = 15*two - y*4;
    if(left >= x){
        ans = ceil(two);
    }else{
        ans = ceil(two + ceil((x - left)/15));
    }
    result.push_back(ans);
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