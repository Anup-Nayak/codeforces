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
    int n,k;
    cin >> n >> k;

    vector<int> arr(n,0);
    int maxi = INT_MIN;

    for(int i=0;i<n;i++){
        int temp;
        cin >> temp;
        arr[i]=temp;
        maxi = max(maxi,temp);
    }

    int start = maxi;
    int end = maxi+k;

    // cout << start << " " << end << endl;

    for(int i=0;i<n;i++){
        if(((maxi-arr[i])/k)%2 == 0){
            int s = arr[i] + ((maxi-arr[i])/k)*k;
            int e = s + k;
            start = max(start,s);
            end = min(end,e);

            // cout << arr[i] << " " << s << " " << e << " " << endl;
        }else{
            int s = arr[i] + ((maxi-arr[i])/k)*k + k;
            int e = s + k;
            start = max(start,s);
            end = min(end,e);
            // cout << arr[i] << " " << s << " " << e << " " << endl;
        }
    }

    // cout << start << " " << end << endl;

    if(start < end){
        result.pb(start);
        return;
    }else{
        result.pb(-1);
        return;
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