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
    ll n,k;
    cin >> n >> k;
    vector<int> a(n);
    fcin(n,a);
    
    map<int,vector<int>> mp;

    f(i,n){
        mp[a[i]%k].pb(a[i]);
    }

    int cnt = 0;

    for(auto i:mp){
        if(i.second.size()&1){
            cnt++;
        }
    }
    if(cnt > 1){
        result.pb(-1);
        return;
    }else{

        if(n&1){
            ll ans = 0; 
            for(auto i:mp){
                vector<int> ay = i.second;
                sorta(ay);
                if(ay.size()&1){
                    int si = ay.size();
                    vector<ll> pref(si,0);
                    vector<ll> suff(si,0);

                    pref[0]=0;
                    suff[si-1]=0;

                    for(int i=2;i<si;i+=2){
                        pref[i] = pref[i-2]+(ay[i-1]-ay[i-2])/k;
                    }

                    for(int i=si-3;i>=0;i-=2){
                        suff[i] = suff[i+2]+(ay[i+2]-ay[i+1])/k;
                    }

                    ll mini = INT_MAX;
                    for(int i=0;i<si;i+=2){
                        mini = min(mini,pref[i]+suff[i]);
                    }

                    ans += mini ;

                }else{
                    for(int i=0;i<ay.size()-1;i+=2){
                        ans += (ay[i+1]-ay[i])/k;
                    }
                }
            }
            result.pb(ans);
            return;

        }else{
            ll ans = 0; 
            for(auto i:mp){
                vector<int> ay = i.second;
                sorta(ay);
                for(int i=0;i<ay.size()-1;i+=2){
                    ans += (ay[i+1]-ay[i])/k;
                }
            }
            result.pb(ans);
            return;
        }
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
        cout << result[i] << endl;
    }
    return 0;
}