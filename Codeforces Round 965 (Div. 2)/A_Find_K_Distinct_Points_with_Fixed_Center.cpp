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

void solve(vector<vector<vector<int>>>& result){
    int x,y,k;
    cin >> x >> y >> k;

    vector<vector<int>> ans;
    if(k&1){
        ans.pb({x,y});
        k--;
    }

    int i = 1;

    while(k>0){
        ans.pb({x-i,y});
        ans.pb({x+i,y});
        k-=2;
        i++;
    }

    result.pb(ans);

}

int main(){

    int t;
    cin >> t;
    vector<vector<vector<int>>> result;

    while(t--){
        solve(result);
    };

    for(int i = 0; i < result.size();i++){
        for(auto &test:result[i]){
            cout << test[0] << " " << test[1] << endl;
        }
    }
    return 0;
}