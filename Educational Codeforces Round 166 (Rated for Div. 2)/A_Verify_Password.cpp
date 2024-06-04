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

void solve(vector <string>& result){
    ll n;
    cin>>n;
    string p;
    cin >> p;
    ll str=0;
    ll num=0;
    bool st = false;
    for(int i=0;i<n;i++){
        if(p[i]-'0'>=0 and p[i]-'0'<=9){
            if(st == true){
                result.pb("NO");
                return;
            }
            int temp = p[i]-'0';
            if(temp>=num){
                num=temp;
            }else{
                result.pb("NO");
                return;
            }
        }else if(p[i]-'a'>=0 and p[i]-'a'<=25){
            st = true;
            int temp = p[i]-'a';
            if(temp >= str){
                str = temp;
            }else{
                result.pb("NO");
                return;
            }
        }else{
            result.pb("NO");
            return;
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