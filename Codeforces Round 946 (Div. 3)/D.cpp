#include <iostream>
#include <bits/stdc++.h>
#include <cmath>
#include <unordered_map>

using namespace std;
#define ull unsigned long long

void solve(vector<string> &result)
{

    string ans = "";

    int n;
    cin >> n;
    string s;
    cin >> s;

    int N = 0;
    int S = 0;
    int E = 0;
    int W = 0;

    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'N')
        {
            N++;
        }
        else if (s[i] == 'S')
        {
            S++;
        }
        else if (s[i] == 'E')
        {
            E++;
        }
        else
        {
            W++;
        }
    }
    // cout << N << S << E << W << endl;

    if(N == 1 and S == 1 and E == 0 and W == 0){
        ans = "NO";
        result.push_back(ans);
        return;
    }else if(N == 0 and S == 0 and E == 1 and W == 1){
        ans = "NO";
        result.push_back(ans);
        return;
    }

    int ver = abs(N - S);
    int hor = abs(E - W);

    int vswitch = 0;
    int hswitch = 1;

    int R = 0;
    int H = 0;

    vector<char> ansVector(n,'R');

    if (ver % 2 == 0 and hor % 2 == 0)
    {
        // for (int i = 0; i < n; i++){
        //     if (s[i] == 'N')
        //     {
        //         if (vswitch == 0)
        //         {
        //             ans += "R";
        //             R++;
        //             vswitch = 1;
        //         }
        //         else if (vswitch == 1)
        //         {
        //             ans += "H";
        //             H++;
        //             vswitch = 0;
        //         }
        //     }
        //     else if (s[i] == 'S')
        //     {
        //         if (vswitch == 1)
        //         {
        //             ans += "R";
        //             R++;
        //             vswitch = 0;
        //         }
        //         else if (vswitch == 0)
        //         {
        //             ans += "H";
        //             H++;
        //             vswitch = 1;
        //         }
        //     }
        //     else if (s[i] == 'E')
        //     {
        //         if (hswitch == 0)
        //         {
        //             ans += "R";
        //             R++;
        //             hswitch = 1;
        //         }
        //         else if (hswitch == 1)
        //         {
        //             ans += "H";
        //             H++;
        //             hswitch = 0;
        //         }
        //     }
        //     else if (s[i] == 'W')
        //     {
        //         if (hswitch == 1)
        //         {
        //             ans += "R";
        //             R++;
        //             hswitch = 0;
        //         }
        //         else if (hswitch == 0)
        //         {
        //             ans += "H";
        //             H++;
        //             hswitch = 1;
        //         }
        //     }
        // }
        for(int i = 0;i <n; i++){
            if(s[i] == 'N'){
                if(vswitch == 0){
                    ansVector[i] = 'R';
                    vswitch = 1;
                }else if(vswitch == 1){
                    ansVector[i] = 'H';
                    vswitch = 0;
                }
            }
        }
        vswitch = 0;
        for(int i = 0;i <n; i++){
            if(s[i] == 'S'){
                if(vswitch == 0){
                    ansVector[i] = 'R';
                    vswitch = 1;
                }else if(vswitch == 1){
                    ansVector[i] = 'H';
                    vswitch = 0;
                }
            }
        }

        for(int i = 0;i <n; i++){
            if(s[i] == 'W'){
                if(hswitch == 0){
                    ansVector[i] = 'R';
                    hswitch = 1;
                }else if(hswitch == 1){
                    ansVector[i] = 'H';
                    hswitch = 0;
                }
            }
        }
        hswitch = 1;
        for(int i = 0;i <n; i++){
            if(s[i] == 'E'){
                if(hswitch == 0){
                    ansVector[i] = 'R';
                    hswitch = 1;
                }else if(hswitch == 1){
                    ansVector[i] = 'H';
                    hswitch = 0;
                }
            }
        }
        ans = "";
        for(int i=0;i<n;i++){
            ans += ansVector[i];
        }
        
    }
       
    else
    {
        ans = "NO";
    }

    for(int i=0;i<n;i++){
        if(ansVector[i] == 'R'){
            R++;
        }else{
            H++;
        }
    }

    if(R==0 or H==0){
        ans = "NO";
    }

    result.push_back(ans);
}

int main()
{

    int t;
    cin >> t;
    vector<string> result;

    while (t--)
    {
        solve(result);
    };

    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << endl;
    }
    return 0;
}