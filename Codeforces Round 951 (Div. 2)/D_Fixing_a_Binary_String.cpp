#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <climits>
#include <vector>
#include <queue>
#include <set>
#include <numeric>
#include <unordered_map>
#include <stack>
#include <numeric>
#include <map>
#include <unordered_map>
#include<bits/stdc++.h>

using namespace std;
 
#define ll long long
#define llu long long unsigned
#define f(i, n) for (int i = 0; i < n; i++)
#define fi(i, a, n) for (int i = a; i < n; i++)
#define fii(i, n, a) for (int i = n; i > a; i--)
#define fcin(n, arr)            \
    for (int i = 0; i < n; i++) \
    {                           \
        cin >> arr[i];          \
    }
#define sorta(a) sort(a.begin(),a.end())
#define sortd(a) sort(a.begin(),a.end(),greater<int>())
 
#define ve vector
#define vi vector<int>
#define vll vector<ll>
#define vs vector<string>
#define vb vector<bool>
#define pii pair<int, int>
#define vp vector<pii>
#define vl vector<loc>
#define vvb ve<vb>
#define vvl ve<vll>
#define vvi ve<vi> 
#define ev(a) a.begin(), a.end()
#define pb push_back
#define mp make_pair
 
void print(vector<ll> &a){
    f(i,a.size()){
        cout << a[i] << " ";
    }
    cout << endl;
}

void solve(vector <ll>& result){
    ll n,k;
    cin >> n >> k;
    string s;
    cin >> s;

    string s1 ="";
    string s2 ="";

    string z = "";
    string o = "";

    f(i,k){
        z+= "0";
        o+= "1";
    }    

    bool sw = true;

    f(i,n/k){
        if(sw){
            s1+= z;
            s2+= o;
            sw=false;
        }else{
            s1+= o;
            s2+= z;
            sw=true;
        }
    }
    int ans = -1;
    string a = s.substr(1,n-1);
    string b;
    b.assign(1, s[0]);
    string c = "";
    for(int i=1;i<n;i++){
        string st = a+b+c;
        if(st==s1 or st==s2){
            ans = i;
            break;
        }
        c = b+c; 
        b.assign(1,s[i]);
        // a = s.substr(i+1,n-1);
        a.erase(0, 1);

    }
    result.pb(ans);

}

int main(){

    int t;
    cin >> t;
    vector<ll> result;

    while(t--){
        solve(result);
    };

    for(int i = 0; i < result.size();i++){
        cout << result[i] << endl;
    }
    return 0;
}