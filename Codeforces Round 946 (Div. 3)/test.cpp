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
 
void printl(int a, int b, int c, int d)
{
    cout << "? " << a << " " << b << " " << c << " " << d << endl;
}
void printll(vector<ll> &a)
{
    f(i, a.size())
    {
        cout << a[i] << 
;
    }
    cout << endl;
}
void printvll(ve<vll>& a){
    f(i,a.size()){
        printll(a[i]);
    }
}

void solve(vector <int>& result){
    
}

int main(){

    int t;
    cin >> t;
    vector<int> result;

    while(t--){
        solve(result);
    };

    for(int i = 0; i < result.size();i++){
        cout << result[i] << endl;
    }
    return 0;
}