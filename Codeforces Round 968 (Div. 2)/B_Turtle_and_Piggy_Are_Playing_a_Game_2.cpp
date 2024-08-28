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

void solve(vector <ll>& result){
    int n;
    cin >> n;

    vector<int> arr(n,0);
    fcin(n,arr);
    sorta(arr);
    // print(arr);

    int ind = n/2;
    result.pb(arr[ind]);
    return;


    int ans = 0;
    if(n==2){
        ans = max(arr[0],arr[1]);
        result.pb(ans);
        return;
    }

    for(int i=1;i<n-1;i++){
        int a = arr[i-1];
        int b = arr[i];
        int c = arr[i+1];

        int maxi = max(a,max(b,c));
        int mini = min(a,min(b,c));

        ans = max(ans,a+b+c-maxi-mini);
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