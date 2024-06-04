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

void solve(vector<vector<ll>>& result){
    ll n,m;
    cin >> n >> m;

    vector<int> a(n+m+1);
    fcin(n+m+1,a);
    vector<int> b(n+m+1);
    fcin(n+m+1,b);

    ll x;
    ll y;

    ll nv=0;
    ll mv=0;

    ll prog = 0;
    ll test = 0;

    vector<int> pos(n+m+1,0);
    
    for(int i=0;i<n+m+1;i++){
        if((nv < n) and a[i]>b[i]){
            prog+= a[i];
            nv++;
        }else if((mv < m) and a[i]<b[i]){
            test+= b[i];
            pos[i]=1;
            mv++;
        }else if(nv == n+1){
            test+=b[i];
            pos[i]=1;
            mv++;
        }else if(mv == m+1){
            prog+= a[i];
            nv++;
        }else if((nv == n) and a[i]>b[i]){
            prog+= a[i];
            test+= b[i];
            pos[i]=2;
            x = a[i];
            y = b[i];
            nv++;
        }else if((mv == m )and a[i]<b[i]){
            prog+= a[i];
            test+= b[i];
            pos[i]=2;
            x = a[i];
            y = b[i];
            mv++;
        }
    }
    // cout << prog << " " << test << endl;
    vector<ll> ans(n+m+1);
    for(int i=0;i<n+m+1;i++){
        if(pos[i]==2){
            ans[i] = prog-x+test-y;
        }else if(pos[i]==1){
            ans[i] = prog+test-b[i]-x;
        }else{
            ans[i] = prog+test-a[i]-y;
        }
    }
    result.pb(ans);
}

int main(){

    int t;
    cin >> t;
    vector<vector<ll>> result;

    while(t--){
        solve(result);
    };

    for(int i = 0; i < result.size();i++){
        print(result[i]);
    }
    return 0;
}