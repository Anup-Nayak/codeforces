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
    long long n,m;
    cin >> n >> m;

    ll mini = INT_MAX;

    vector<ll> petals(n);
    map<int,ll> cnt;
    for(int i=0;i<n;i++){
        ll temp;
        cin >> temp;
        petals[i] = temp;
        mini = min(mini,temp);
        // cnt[temp]++;
    }

    for(int i=0;i<n;i++){
        int temp;
        cin >> temp;
        cnt[petals[i]]+=temp;
    }

    if(mini > m){
        result.pb(0);
        return;
    }else if(mini == m){
        result.pb(m);
        return;
    }

    sortd(petals);
    // auto it = unique(petals.begin(),petals.end());
    // petals.erase(it,petals.end());

    

    ll ans=0;

    for(int i=0;i<petals.size()-1;i++){
        if(petals[i]-petals[i+1] == 1){
            ll a = cnt[petals[i]];
            ll b = cnt[petals[i+1]];
            

            ll at = m/petals[i];
            
            if(min(at,a)*petals[i]==m){
                result.pb(m);
                return;
            }else{
                if(min(at+1,a)*petals[i] <= m){
                    ans = max(ans,min(at+1,a)*petals[i]);
                }
                ans = max(ans,min(at,a)*petals[i]);
            }

            ll y = min(at+1,a)*petals[i];
            if(y > m){
                if(y-m <= min(a,b)){
                    result.pb(m);
                    return;
                }else{

                    if(y-min(a,b) <=m ) ans = max(ans,y-min(a,b));
                }
            }else{
                
                ll yy = (m-y)/petals[i+1];
                

                if(y+min(b,yy)*petals[i+1]<=m) ans = max(ans,y+min(b,yy)*petals[i+1]);
                ll newY = y + min(b,yy+1)*petals[i+1];
                
                b = b - min(b,yy+1);
                
                if(newY > m){
                    if(newY-m <= min(a,b)){
                        
                        result.pb(m);
                        return;
                    }else{
                        if(newY-min(a,b) <=m) ans = max(ans,newY-min(a,b));
                    }
                }else{
                    ans = max(ans,newY);
                }
            }

 
        }else{
            ll a = cnt[petals[i]];
            ll at = m/petals[i] ;
            if(min(at+1,a)*petals[i] <= m){
                ans = max(ans,min(at+1,a)*petals[i]);
            }
            ans = max(ans,min(at,a)*petals[i]);
        }
    }

    int nn = petals.size()-1;
    ll a = cnt[petals[nn]];
    ll at = m/petals[nn] ;
    if(min(at+1,a)*petals[nn] <= m){
        ans = max(ans,min(at+1,a)*petals[nn]);
    }
    ans = max(ans,min(at,a)*petals[nn]);


    result.pb(ans);


}

// void solve() {
//     long long n,m;
//     cin >> n >> m;
//     vector<int> a(n);
//     for (int i = 0; i < n; ++i) {
//         cin >> a[i];
//     }
//     sort(a.begin(), a.end());
 
//     ll res = 0;
//     ll curr = 0;
//     int j = 0;
//     for (int i = 0; i < n; ++i) {
//         curr += a[i];
//         while (j < n and (a[j] < a[i] - 1 or curr > m)) {
//             curr -= a[j];
//             ++j;
//         }
//         res = max(res,curr);
//     }
 
//     cout << res << '\n';
// }

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