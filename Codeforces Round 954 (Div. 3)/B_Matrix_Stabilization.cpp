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
    int n,m;
    cin >> n >> m;
    vector<vector<int>> a(n,vector<int>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int temp;
            cin >> temp;
            a[i][j] = temp;
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int maxi = INT_MIN;
            if(i-1>=0){
                maxi = max(a[i-1][j],maxi);
                // cout << a[i][j] << "1" << endl;
            }
            if(i+1<n){
                maxi = max(a[i+1][j],maxi);
                // cout << a[i][j] << "2" << endl;
            }
            if(j-1>=0){
                maxi = max(a[i][j-1],maxi);
                // cout << a[i][j] << "3" << endl;
            }
            if(j+1<m){
                maxi = max(a[i][j+1],maxi);
                // cout << a[i][j] << "4" << endl;
            }

            if(maxi < a[i][j]){
                a[i][j] = maxi;
            }


        }
    }


    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout << a[i][j] << " " ;
        }
        cout << endl;
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