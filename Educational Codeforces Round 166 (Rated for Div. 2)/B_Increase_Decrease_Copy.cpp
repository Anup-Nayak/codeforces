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
 
void print(vector<int> &a){
    f(i,a.size()){
        cout << a[i] << " ";
    }
    cout << endl;
}

void solve(vector <ll>& result){
    ll n;
    cin >> n;
    vector<int> a;
    for(int i=0;i<n;i++){
        ll temp;
        cin >> temp;
        a.pb(temp);
    }
    vector<int> b;
    
    for(int i=0;i<n+1;i++){
        ll temp;
        cin >> temp;
        b.pb(temp);
    }

    ll last = b[n];
    bool do1 = false;

    for(int i=0;i<n;i++){
        if((a[i]<=last and b[i]>=last) or (a[i]>=last and b[i]<=last)){
            do1 = true;
            break;
        }
    }
    ll close = INT_MAX;
    if(!do1){
        for(int i=0;i<n;i++){
            if(abs(last-a[i]) < abs(last-close)){
                close=a[i];
            }
            if(abs(last-b[i]) < abs(last-close)){
                close=b[i];
            }

        }
    }
    
    
    ll ans;
    if(do1){
        ans = 1;
    }else{
        ans = abs(close-last)+1;
    }
    
    for(int i=0;i<n;i++){
        ans+= abs(a[i]-b[i]);
        
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