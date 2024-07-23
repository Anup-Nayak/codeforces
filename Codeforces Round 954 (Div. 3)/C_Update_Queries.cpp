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
 
void print(vector<int> &a){
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

void solve(vector <string>& result){
    int n,m;
    cin >> n >> m;
    string s;
    cin >> s;
    vector<int> d(m);
    f(i,m){
        int temp;
        cin >> temp;
        d[i]=temp-1;
    }
    sort(d.begin(), d.end()); 
    auto it 
        = unique(d.begin(), d.end()); 
    d.erase(it, d.end()); 

    string c;
    cin >> c;
    sort(c.begin(),c.end());

    int ii = 0;
    
    string ans = "";
    f(i,n){
        if(i==d[ii] and ii < d.size()){
            ans+= c[ii];
            ii++;
        }else{
            ans += s[i];
        }
    }   

    result.pb(ans);


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