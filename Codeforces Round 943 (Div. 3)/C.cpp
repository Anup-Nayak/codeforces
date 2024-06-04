#include<iostream>
#include<bits/stdc++.h>
#include<cmath>
#include<unordered_map>

using namespace std;

void solve(vector <vector<int>>& result){
    int n;
    cin >> n;
    vector<int> arr;
    int max = INT_MIN;
    for(int i = 0; i<n-1;i++){
        int temp;
        cin >> temp;
        arr.push_back(temp);
        if(temp > max){
            max = temp;
        }
    }

    vector<int> ans;
    int index = 0;
    ans.push_back(max+1);
    for(int i = 0; i< n-1;i++){
        int temp = ans[index]+arr[i];
        ans.push_back(temp);
        index++;
    }
    result.push_back(ans);
}

int main(){

    int t;
    cin >> t;
    vector<vector<int>> result;

    while(t--){
        solve(result);
    };

    for(int i = 0; i < result.size();i++){
        for(int j=0; j < result[i].size();j++){
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}