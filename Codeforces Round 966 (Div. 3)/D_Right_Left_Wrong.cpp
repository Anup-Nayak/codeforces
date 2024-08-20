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

void solve(vector <ll>& result){
    int n;
    cin >> n;


    vector<int> arr(n,0);
    fcin(n,arr);

    vector<ll> pre(n+1,0);
    pre[1]=arr[0];
    for(int i=1;i<n;i++){
        pre[i+1]=pre[i]+arr[i];
    }
    // print(pre);
    string s;
    cin >> s;

    int start = 0;
    int end = s.size()-1;

    long long ans = 0;

    while(start<=end){
        if(s[start]=='L' and s[end]=='R'){
            // cout << start << " " << end << endl;
            ans += pre[end+1]-pre[start];
            start++;
            end--;
        }
        if(s[start]=='R'){
            start++;
        }
        if(s[end]=='L'){
            end--;
        }
    }
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