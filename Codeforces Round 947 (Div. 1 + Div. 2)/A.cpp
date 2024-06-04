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

    ll decrease = 0;
    vector<int> arr;
    ll curr;
    cin >> curr;
    arr.pb(curr);
    ll index = 1;
    ll change = 0;

    f(i,n-1){
        ll temp;
        cin >> temp;
        arr.pb(temp);
        if (temp < curr){
            decrease++;
            change = index;
        }
        curr = temp;
        index++;

    }
    // cout << change << endl;

    if(decrease == 0){
        result.push_back("yes");
    }else if(decrease == 1){
        if(arr[0] >= arr[n-1]){
            
            result.push_back("yes");
        }else{
            result.push_back("no");
        }
    }else{
        result.push_back("no");   
    }
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