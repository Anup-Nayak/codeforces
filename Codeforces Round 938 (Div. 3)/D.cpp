#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
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

bool binarySearch(vector<ll> &arr,ll a){
    ll n = arr.size();

    ll start = 0;
    ll end = n-1;

    while(start <= end){
        ll mid = start + (end - start)/2;
        ll temp = arr[mid];
        if(temp == a){
            return true;
        }else{
            if(temp > a){
                end = mid - 1;
            }else{
                start = mid + 1;
            }
        }
    }
    return false;
}

void solve(vector <int>& result){

    ll ans = 0;

    ll n,m,k;
    cin >> n >> m >> k;
    vector<ll> a(n,0);
    vector<ll> b(m,0);
    fcin(n,a);
    fcin(m,b);

    sort(b.begin(),b.end());

    queue<ll> curr;
    ll kv = 0;
    
    f(i,m){
        
        if(binarySearch(b,a[i])){
            curr.push(1);
            kv++;
        }else{
            curr.push(0);
        }
    }

    if(kv >= k){
        ans++;
    }

    for(int i=m;i<n;i++){
        if(curr.front()==1){
            kv--;
        }
        curr.pop();
        if(binarySearch(b,a[i])){
            curr.push(1);
            kv++;
        }else{
            curr.push(0);
        }

        if(kv >= k){
            ans++;
        }
    }

    result.pb(ans);
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