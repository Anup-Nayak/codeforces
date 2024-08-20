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
    int n,q;
    cin >>n >> q;
    string a;
    cin >> a;
    string b;
    cin >> b;

    vector<ll> ans = {0};
    map<char,int> cnt;
    ll s = 0;

    for(int i=0;i<n;i++){
        if(a[i]==b[i]){
            s++;
            ans.push_back(s);
            continue;
        }

        cnt[a[i]]++;
        cnt[b[i]]--;

        if(cnt[a[i]] <= 0) s++;
        if(cnt[b[i]] >= 0) s++;

        ans.push_back(s);
    }
    // cout << endl;
    // print(ans);

    while(q--){
        int l;
        int r;
        cin >> l;
        cin >> r;

        result.push_back((r-l+1)-(ans[r]-ans[l-1]));
    }
}

int main(){

    int t;
    cin >> t;
    vector<ll> result;

    while(t--){
        solve(result);
    };

    for(int i = 0; i < result.size();i++){
        cout << abs(result[i]) << endl;
    }
    return 0;
}