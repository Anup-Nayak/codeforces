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

void solve(vector <ll>& result){
    ll n,a,b;
    cin >> n >> a >> b;
    ll ans = 0;
    if(b<=a){
        ans = n*a;
        result.pb(ans);
    }else{
        ll c = b-a;
        ll d = b-n;
        if(n<=c+1){
            ll q = (b*b + b)/2;
            ll ar = b-n;
            // cout << b << ar << endl;
            ll w = (ar*ar + ar)/2;
            ans = q-w;
            result.pb(ans);
        }else{
            ans = (n-(b-a))*a;
            ll q = (b*b+b)/2;
            ll ar = a;
            ll w = (ar*ar + ar)/2;
            ans += q-w;
            result.pb(ans);
        }
    }
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