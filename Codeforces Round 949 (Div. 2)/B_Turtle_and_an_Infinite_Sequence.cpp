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

ll decimal(const string& binary) {
    ll decimal = 0;
    int length = binary.length();

    for (int i = 0; i < length; ++i) {
        if (binary[length - 1 - i] == '1') {
            decimal += pow(2, i);
        }
    }
    
    return decimal;
}


void solve(vector <ll>& result){
    ll n,m;
    cin >> n >> m;
    string k = binary(m);
    string a = "";
    f(i,k.size()){
        a+="0";
    }
    string s = "00000"+a+binary(n);

    if(m==0){
        result.pb(decimal(s));
        return;
    }

    ll power = 0;
    ll sum = 0;

    for(int i=s.size()-1;i>=0;i--){
        if(s[i]=='0'){
            if(((pow(2,power)-sum) <= m) or (((sum+1) <= m) and (n >= pow(2,power+1)))){
                s[i]='1';
            }
        }else{
            sum += (pow(2,power));
        }
        power++;
    }

    ll ans = decimal(s);
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