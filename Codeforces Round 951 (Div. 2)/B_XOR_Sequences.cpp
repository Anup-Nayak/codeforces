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

string binary(ll n) {
    // Handle the case where the input is 0
    if (n == 0) return "0";
    
    std::string binary = "";
    while (n > 0) {
        binary = (n % 2 == 0 ? "0" : "1") + binary;
        n /= 2;
    }
    
    return binary;
}

void solve(vector <ll>& result){
    ll x,y;
    cin >> x >> y;
    string a = binary(x);
    string b = binary(y);
    int i = a.size()-1;
    int j = b.size()-1;
    int n=0;
    if(i>j){
        int e = i-j;
        string ut = "";
        while(e--){
            ut+= "0";
        }
        b = ut + b;
        n=i;
    }else if(i<j){
        int e = j-i;
        string ut = "";
        while(e--){
            ut+= "0";
        }
        a = ut + a;
        n=j;
    }else{
        n=i;
    }
    
    ll ans=0;
    while(n>=0){
        if(a[n]==b[n] ){
            ans++;
            n--;
        }else{
            break;
        }
    }
    result.pb(pow(2,ans));

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