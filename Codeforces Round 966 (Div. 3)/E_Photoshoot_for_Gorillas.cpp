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
    ll n,m,k;
    cin >> n >> m >> k;

    ll w;
    cin >> w;

    vector<int> arr(w,0);
    fcin(w,arr);
    sortd(arr);

    ll ans = 0;

    ll indx = 0;
    ll c = 0;

    while(indx<w and k>0)  {
        c = (n-2*(k-1))*(m-2*(k-1));
        if(c>0){
            for(int i=indx;i<min(indx+c,w);i++){
                ans += k*k*arr[i];
            }
            indx = indx+c;
        } 

        c = (n-2*(k-2))*(m-2*(k-1));
        if(c>0){
            for(int i=indx;i<min(indx+c,w);i++){
                ans += k*(k-1)*arr[i];
            }
            indx = indx+c;
        } 

        c = (n-2*(k-1))*(m-2*(k-2));
        if(c>0){
            for(int i=indx;i<min(indx+c,w);i++){
                ans += k*(k-1)*arr[i];
            }
            indx = indx+c;
        } 

        k--;
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