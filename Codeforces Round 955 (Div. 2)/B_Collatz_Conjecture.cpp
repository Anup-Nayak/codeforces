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
    ll x,y,k;
    cin >> x >> y >> k;

    while(k>0){

        if(x<y){
            if(x+k < y){
                result.pb(x+k);
                return;
            }
            else if(x+k == y){
                result.pb(1);
                return;
            }
            else{
                k = k-(y-x);
                x = 1;

                int r = y-1;
                ll f = r;
                int i=1;
                while(r*i <= k){
                    f = r*i;
                    i++;
                }

                k = k-f;

                result.pb(x+k);
                return;
                
            }
        }

        ll factor = y;
        int i=2;
        while(factor <= x){
            factor = y*i;
            i++;
        }
        
        if(factor > x+k){
            result.pb(x+k);
            return;
        }else{
            k=k-(factor-x);
            while(factor%y == 0){
                factor/=y;
            }
            x=factor;
            
        }
        
        if(k==0){
            result.pb(x);
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