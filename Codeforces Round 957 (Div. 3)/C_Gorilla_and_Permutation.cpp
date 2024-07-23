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
 
void print(vector<int> &a){
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

void solve(vector<vector<int>>& result){
    int n,m,k;
    cin >> n >> m >> k;

    vector<int> a(n,0);

    int ind = 1;

    for(int i=0;i<n;i++){
        a[i] = n-i;
    }

    for(int i=n-m;i<n;i++){
        a[i] = ind;
        ind++;
    }

    result.pb(a);
}

int main(){

    int t;
    cin >> t;
    vector<vector<int>> result;

    while(t--){
        solve(result);
    };

    for(int i = 0; i < result.size();i++){
        print(result[i]);
    }
    return 0;
}