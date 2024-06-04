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
 
void print(vector<int> &a){
    f(i,a.size()){
        cout << a[i] << " ";
    }
    cout << endl;
}

string binary(ll n){
    if (n == 0) return "0";
    
    std::string binary = "";
    while (n > 0) {
        binary = (n % 2 == 0 ? "0" : "1") + binary;
        n /= 2;
    }
    
    return binary;
}

void solve(vector <vector<int>>& result){
    ll x;
    cin >> x;
    string b = binary(x);
    string a = "0"+b+"0";
    // cout << a << endl;
    string ans = "";
    for(int i=a.size()-1;i>=1;i--){
        if(a[i]=='0' and a[i-1]=='0'){
            ans+="0";
        }else if(a[i]=='0' and a[i-1]=='1'){
            ans+="2";
        }else if(a[i]=='1' and a[i-1]=='1'){
            ans+="0";
        }else if(a[i]=='1' and a[i-1]=='0'){
            ans+="1";
        }
    }
    // cout << ans << endl;

    vector<int> res={};

    for(int i=0;i<ans.size();i++){
        if(ans[i]=='0'){
            res.pb(0);
        }else if(ans[i]=='1'){
            res.pb(1);
        }else{
            res.pb(-1);
        }
    }

    // print(res);

    for(int i=0;i<res.size()-1;i++){
        if(res[i]==1 and res[i+1]==-1){
            res[i]=-1;
            res[i+1]=0;
        }else if(res[i]==-1 and res[i+1]==1){
            res[i]=1;
            res[i+1]=0;
        }
    }

    result.pb(res);
    // ll nn = ans.size();
    // string newAns = "";
    // for(int i=nn-1;i>=1;i--){
    //     if(ans[i]==1 and ans[i-1]==-1){

    //     }
    // }

}

int main(){

    int t;
    cin >> t;
    vector<vector<int>> result;

    while(t--){
        solve(result);
    };

    for(int i = 0; i < result.size();i++){
        cout << result[i].size() << endl;
        print(result[i]);
    }
    return 0;
}