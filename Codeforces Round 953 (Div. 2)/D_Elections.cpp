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

void solve(vector<vector <ll>>& result){
    int n, c;
    cin >> n >> c;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    if (n == 1) {
        cout << "0\n";
        return;
    }

    int mx = *max_element(a.begin() + 1, a.end());
    int mxc = max(a[0] + c, mx);
    int winner = mxc == a[0] + c ? 0 : find(a.begin() + 1, a.end(), mx) - a.begin();
    ll sum = c;
    for (int i = 0; i < n; sum += a[i], ++i) {
        int answer;
        if (i == winner) {
            answer = 0;
        } else if (sum + a[i] >= mx) {
            answer = i;
        } else {
            answer = i + 1;
        }
        cout << answer << " \n"[i == n - 1];
    }

}

int main(){

    int t;
    cin >> t;
    vector<vector<ll>> result;

    while(t--){
        solve(result);
    };

    for(int i = 0; i < result.size();i++){
        print(result[i]);
    }
    return 0;
}