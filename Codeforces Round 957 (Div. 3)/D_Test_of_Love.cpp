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

int goToLog(int curr, vector<int> &log, int m){
    int ans = curr;
    for(int i=1;i<log.size();i++){
        if(log[i]<=curr) continue;
        if((log[i]-log[i-1])<=m){
            ans = log[i];
        }else{
            break;
        }
    }
    return ans;
}

void solve(vector <string>& result){
    int n,m,k;
    cin >> n >> m >> k;
    string s;
    cin >> s;

    s = 'L'+s+'L';

    vector<int> croc;
    vector<int> log;
    vector<int> water;

    for(int i=0;i<s.size();i++){
        if(s[i]=='L'){
            log.pb(i);
        }else if(s[i]=='C'){
            croc.pb(i);
        }else{
            water.pb(i);
        }
    }

    // print(log);

    int curr = goToLog(0,log,m);
    // cout << curr << endl;
    while(curr < n+1){
        
    }

    if(curr >= n+1){
        result.pb("YES");
        return;
    }
    result.pb("NO");
    return;

    // while(curr <= n+1){

    // }
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