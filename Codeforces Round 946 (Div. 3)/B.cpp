#include<iostream>
#include<bits/stdc++.h>
#include<cmath>
#include<unordered_map>

using namespace std;

void solve(vector <string>& result){
    int n;
    string b;
    cin >> n >> b;

    // take out distinct alphabets from b
    map<int, bool> present;
    for(int i=0;i<n;i++){
        present[b[i]-'a'] = true;
    }

    string alph = "";
    string abcd = "abcdefghijklmnopqrstuvwxyz";
    for(int i=0;i<26;i++){
        if (present[i]){
            alph += abcd[i];
        }
    }
    // cout << alph << endl;
    // map each alphabet to corresponding symmetrical alphabet
    int temp = alph.size();
    unordered_map <char,char> mapping;
    for(int i=0;i < temp; i++){
        mapping[alph[i]] = alph[temp-i-1];
    }


    //create new string
    string ans = "";
    for (int i =0 ;i <n;i++){
        ans += mapping[b[i]];
    }

    result.push_back(ans);
}

int main(){

    int t;
    cin >> t;
    vector<string> result;

    while(t--){
        solve(result);
    };

    for(int i = 0; i < result.size();i++){
        cout << result[i] << endl;
    }
    return 0;
}