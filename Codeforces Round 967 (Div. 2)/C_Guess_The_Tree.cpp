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

    int edgeCount = 0;
    vector<pair<int,int>> edges;

    int queries = 15*n;
    int j = 2;
    int i = 1;

    while(queries>0 and edgeCount != n-1){

            cout << "? " << j << " " << i << endl;
            cout.flush();
            queries--;
        
            int a1;
            cin >> a1;
            
            if(a1==j){
                edgeCount++;
                edges.pb(make_pair(i,j));
                j++;
                i = 1;
            }else{
                i = a1;
            }
        
    }
    
    string ans= "!";
    for(auto &pa:edges){
        ans += " ";
        ans += to_string(pa.first);
        ans += " ";
        ans += to_string(pa.second);
    }

    cout << ans << endl;
    
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