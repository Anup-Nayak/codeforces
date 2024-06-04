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

void solve(vector <string>& result){
    ll n;
    cin >> n;
    vector<ll> a(n,0);
    vector<ll> b(n,0);
    
    ll m;
    fcin(n,a);
    fcin(n,b);
    cin>>m;
    vector<ll> d(m,0);
    fcin(m,d);

    map<ll,ll> cnt;
    map<ll,ll> cnt1;

    f(i,m){
        cnt[d[i]]++;
        cnt1[d[i]]++;
    }

    f(i,n){
        if(a[i]!=b[i]){
            if (cnt.find(b[i]) == cnt.end()){
                result.pb("NO");
                return;
            } 
            if(cnt[b[i]]>0){
                cnt[b[i]]--;
            }else{
                result.pb("NO");
                return;
            }
        }
    }
    f(i,n){
        if(a[i]==b[i]){
            if(!(cnt.find(b[i]) == cnt.end())){
                if(cnt[b[i]]>0) cnt[b[i]]--;
            }
        }
    }
    bool t = false;
    f(i,m){
        // cout << cnt[d[i]] << endl;
        if(cnt1[d[i]]!=cnt[d[i]]) t=false;
        else if(cnt[d[i]]>0) t=true;
        else t=false;
    }
    // cout << t;
    if(t) result.pb("NO");
    else result.pb("YES");
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