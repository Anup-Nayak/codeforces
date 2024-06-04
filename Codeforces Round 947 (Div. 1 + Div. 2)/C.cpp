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
#include <climits>
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

void solve(vector <int>& result){
    ll n;
    cin >> n;
    vector<int> arr;
    
    map<int,pair<int,vector<int>>> s;
    ll ans = INT_MIN;

    for(int i=0;i<n;i++){
        ll temp;
        cin >> temp;
        arr.pb(temp);
        s[temp].first++;
        s[temp].second.pb(i);
    }
    vector<int> store = arr;

    sort(arr.begin(),arr.end());
    auto it = unique(arr.begin(), arr.end()); 
  
    arr.erase(it, arr.end()); 
    reverse(arr.begin(),arr.end());
    

    f(i,arr.size()){
        ll num = arr[i];
        ll freq = s[num].first;
        
        vector<int> t = s[num].second;
        
        if(num > ans and freq >=2){
            for(int i=0;i<t.size();i++){
                for(int j=i+1;j<t.size();j++){
                    // cout << "hi" << endl;
                    // cout << t[i] << " " << t[j] << endl;
                    if((t[j]-t[i])<=2){
                        ans = num;
                        break;
                    }
                    vector<int> temp = store;
                    sort(temp.begin()+t[i],temp.begin()+t[j]+1);
                    // print(temp);
                    if(temp[(temp.size()+1)/2] == num){
                        ans = num;
                        break;
                    }
                }
            }
            

        }
    }


    if(store[0]<=store[1] and store[0]>ans){
        ans = store[0];
    }


    for(int i=1;i<n-1;i++){
        if((store[i]<=store[i+1] or store[i]<= store[i-1]) and store[i]>ans){
            ans=store[i];
        }
    }


    result.pb(ans); 


    
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