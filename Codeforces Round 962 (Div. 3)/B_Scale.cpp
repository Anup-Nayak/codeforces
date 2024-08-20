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
        cout << a[i] ;
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

void solve(vector<vector<vector<int>>>& result){
    int n,k;
    cin >> n >> k;

    vector<vector<int>> arr(n,vector<int>(n,0));

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            char temp;
            cin >> temp;
            arr[i][j]= temp-'0';
        }
    // cout << "done" << endl;
    }

    if(k==1) {
        result.push_back(arr);
        return;
    }
    else{
        vector<vector<int>> ans(n/k);
        int i=0;
        int j=0;
        while(true){
            if(i==n){
                break;
            }else if(j==n){
                j=0;
                i+=k;
                // if(arr[i][j]==1){
                //     ans[i/k].push_back(1);
                // }else{
                //     ans[i/k].push_back(0);
                // }
            }else{
                if(arr[i][j]==1){
                    ans[i/k].push_back(1);
                }else{
                    ans[i/k].push_back(0);
                }
                j+=k;
            }
        }
        result.pb(ans);
        return;
    }
}

int main(){

    int t;
    cin >> t;
    vector<vector<vector<int>>> result;

    while(t--){
        solve(result);
    };

    for(int i = 0; i < result.size();i++){
        for(int j=0;j< result[i].size();j++){
            print(result[i][j]);

        }
    }
    return 0;
}