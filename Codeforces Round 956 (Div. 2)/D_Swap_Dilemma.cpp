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
    int n;
    cin >> n;

    map<int,int> am;

    vector<int> a(n,0);
    vector<int> b(n,0);

    for(int i=0;i<n;i++){
        int t;
        cin >> t;
        a[i]=t;
        am[t]=i;
    }

    for(int i=0;i<n;i++){
        int t;
        cin >> t;
        b[i]=t;
    }

    vector<int> a1 = a;
    vector<int> b1 = b;

    sortd(a1);
    sortd(b1);

    if(a1!=b1){
        result.pb("NO");
        return;
    }

    ll swap = 0;

    int i = 0;

    while(i<n){
        if(a[i] == b[i]){
            i++;
        }else{
            int ind1 = am[b[i]];
            am[a[i]] = ind1;
            a[ind1] = a[i];
            a[i] = b[i];
            swap++;
            i++;
        }
    }

    if(swap&1){
        result.pb("NO");
        return;
    }

    result.pb("YES");
    return;


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