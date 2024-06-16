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

ll gcd(ll num1, ll num2)
{
    if (num2 == 0)
        return num1;
    return gcd(num2, num1 % num2);
}
 
ll lcm_of_array(vector<ll> arr)
{
    ll lcm = arr[0];
    for (ll i = 1; i < arr.size(); i++) {
        ll num1 = lcm;
        ll num2 = arr[i];
        ll gcd_val = gcd(num1, num2);
        lcm = (lcm * arr[i]) / gcd_val;
    }
    return lcm;
}

void solve(vector <vector<ll>>& result){
    int n;
    cin>>n;
    vector<ll> a(n);
    fcin(n,a);
    ll lcm = lcm_of_array(a);
    ll sum = 0 ;
    vector<ll> ans;
    f(i,n){
        sum+= lcm/a[i];
        ans.pb((lcm/a[i]));
    }
    if(sum >= lcm){
        ans = {-1};
        result.pb(ans);
        return;
    }else{
        result.pb(ans);
        return;
    }
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