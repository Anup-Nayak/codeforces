#include<iostream>
#include<bits/stdc++.h>
#include<cmath>
#include<unordered_map>

using namespace std;

void solve(vector <int>& result){
    int n,m;
    cin >> n >> m;
    string a,b;
    cin >> a >> b;
    int ans = 0;
    int index = 0 ;
    int i = 0;
    while(i < a.size() and index < b.size()){
        if(a[i] == b[index]){
            i++;
            index++;
            ans++;
        }else{
            index++;
        }
    }
    result.push_back(ans);

}

int main(){

    int t;
    cin >> t;
    vector <int> result;
    while(t--){
        solve(result);
    };

    for(int i = 0; i < result.size();i++){
        cout << result[i] << endl;
    }
    return 0;
}