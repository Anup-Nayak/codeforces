#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long
#define f(i, n) for (int i = 0; i < n; i++)
#define fcin(n, ans)            \
    for (int i = 0; i < n; i++) \
    {                           \
        cin >> ans[i];          \
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

void solve(vector <pair<string,vector<ll>>>& result){
    ll n,k;
    cin >> n >> k;
    vector<ll> ans = {};
    ll upper_limit = 0;
    ll a =n-1;
    f(i,n/2){
        upper_limit += a;
        a -= 2;
    }
    upper_limit *= 2;
    
    if(k&1 or k > upper_limit){
        result.pb(make_pair("No",ans));
    }else{
        f(i,n){
            ans.pb(i+1);
        }

        int i = 0;
        int j = n-1;

        while(k > 0 and i < j){
            if(ans[j]-ans[i]<=(k/2)){
                k=k-((ans[j]-ans[i])*2);
                
                ans[i]= ans[i]^ans[j];
                ans[j]= ans[i]^ans[j];
                ans[i]= ans[i]^ans[j];
                
                i++;
                j--;
            }else{
                j--;
            }

        }
        
        result.pb(make_pair("Yes",ans));
    }
}

int main(){

    int t;
    cin >> t;
    vector<pair<string,vector<ll>>> result;

    while(t--){
        solve(result);
    };

    for(int i = 0; i < result.size();i++){
        cout << result[i].first << endl;
        if(result[i].second.size()!=0){

            print(result[i].second);
        }
    }
    return 0;
}