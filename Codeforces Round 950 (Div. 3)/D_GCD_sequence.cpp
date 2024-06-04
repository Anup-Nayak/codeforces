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
#include <algorithm> 
 
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
bool check(vector<ll> a){
    // cout << "h";
    bool c = true;
    ll g=INT_MIN;
    f(i,a.size()-1){
        ll gc1 = __gcd(a[i],a[i+1]);
        if(gc1>=g){
            g=gc1;
        }else{
            return false;
        }
    }
    return true;
}

void solve(vector <string>& result){
    ll n;
    cin>>n;
    vector<ll> a(n,0);
    fcin(n,a);
    vector<ll> b = a;
    vector<ll> c = a;
    vector<ll> d = a;
    ll g = INT_MIN;
    // ll pg = INT_MIN;
    // bool o = false;
    // ll i=1;
    f(i,n-1){
        ll gc1 = __gcd(a[i],a[i+1]);
        if(g<=gc1){
            g=gc1;
        }else{
            if(i==n-2){
                result.pb("YES");
                return;
            }
            
            b.erase(b.begin()+i);
            c.erase(c.begin()+i+1);
            
            bool a1 = check(b);
            bool a2 = check(c);
            bool a3 = false;
            if(i-1>=0){
                d.erase(d.begin()+i-1);
                a3 = check(d);
            }
            
        
            if(a1 or a2 or a3){
                result.pb("YES");
                return;
            }else{
                result.pb("NO");
                return;
            }
        }
    }

    result.pb("YES");
    return;
}

int main(){

    int t;
    cin >> t;
    vector<string> result;
   
    while(t--){
        solve(result);
    };

    
    for(int i = 0; i < result.size();i++){
        cout << result[i] << endl;
    }
    return 0;
}