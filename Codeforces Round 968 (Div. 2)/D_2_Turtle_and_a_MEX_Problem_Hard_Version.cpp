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
    ll n,m;
    cin >> n >> m;

    vector<ll> maxV;
    while(n--){
        
        int nn;
        cin >> nn;
        vector<int> arr(nn,0);
        fcin(nn,arr);

        sorta(arr);

        auto it = unique(arr.begin(),arr.end());
        arr.erase(it,arr.end());

        ll mex = 0;

        for(int num: arr){
            if(num == mex){
                mex++;
            }else if(num > mex){
                break;
            }
        }

        arr.pb(mex);
        sorta(arr);
        mex = 0;
        for(int num: arr){
            if(num == mex){
                mex++;
            }else if(num > mex){
                break;
            }
        }


        maxV.pb(mex);

    }

    sortd(maxV);
    print(maxV);

    ll ans = 0;
    ans += m*(m+1)/2;
    cout << ans << endl;
    int ind = 0;


    for(ll i=0;i<min(n,m+1);i++){
        ans -= i;
        ans += max(i,maxV[ind]);
        ind++;
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