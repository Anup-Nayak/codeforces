#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long
#define f(i, n) for (int i = 0; i < n; i++)
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
#define pb push_back
 
void print(vector<ll> &a){
    f(i,a.size()){
        cout << a[i] << " ";
    }
    cout << endl;
}

string binary(ll n) {
    if (n == 0) return "0";
    
    string binary = "";
    while (n > 0) {
        binary = (n % 2 == 0 ? "0" : "1") + binary;
        n /= 2;
    }
    
    return binary;
}

void solve(vector <vector<ll>>& result){
    ll n;
    cin >> n;
    vector<ll> ans = {n};

    if(!(n&(n-1))){
        cout << 1 << endl;
        cout << n << endl;
        return;
    }

    ll bits = log2(n);
    ll ans1 = __builtin_popcountll(n)+1;

    for(ll i=0;i<=bits;i++){
        if(n & (1ll <<i)){
            if(n-(1ll <<i) > 0){
                ans.pb(n-(1ll <<i));
            }
        }
    }

    reverse(ans.begin(),ans.end());
    cout << ans1 << endl;
    print(ans);


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