#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <numeric>
#include <unordered_map>
#include <stack>
#include <numeric>
#include <map>
#include <unordered_map>
#include <climits>

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

void solve(vector <string>& result){
    ll n;
    cin >> n;

    vector <int> arr(n);
    fcin(n,arr);

    ll a = arr[0];
    f(i,n){
        if(arr[i] < a){
            a = arr[i];
        }
    }
    ll b = INT_MAX;
    f(i,n){
        if(arr[i] < b and arr[i]%a != 0){
            b = arr[i];
        }
    }

    // cout << a << " " << b << endl;

    
        f(i,n){
            // cout << arr[i] << endl;
            if(arr[i]%a != 0 and arr[i]%b != 0){
                result.pb("no");
                return;
            }
        }
        result.pb("yes");
    
    
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