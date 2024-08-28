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
    int n;
    cin >> n;

    if(n&1){
        vector<int> p(n,0);
        p[0]=(n/2)+1;
        int ind = 1;
        for(int i=2;i<n;i=i+2){
            p[i]=ind;
            ind++;
        }
        ind = n/2+2;
        for(int i=1;i<n;i=i+2){
            p[i]=ind;
            ind++;
        }
        ind = 1;
        vector<int> ans(n,0);
        for(int i=0;i<n;i++){
            ans[p[i]-1]=ind;
            ind++;
        }
        result.pb(ans);

    }else{
        result.pb({-1});
    }
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