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

void solve(vector <string>& result){
    int n,m;
    cin >> n >> m;
    vector<vector<int>> a(n,vector<int>(m,0));
    vector<vector<int>> b(n,vector<int>(m,0));

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            char t;
            cin >> t;
            a[i][j]= t-'0';
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            char t;
            cin >> t;
            b[i][j]=t-'0';
        }
    }

    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         cout << a[i][j];
    //     }
    // }

    for(int i=0;i<n-1;i++){
        for(int j=0;j<m-1;j++){
            if(a[i][j]==b[i][j]) continue;
            else if(a[i][j] > b[i][j]){
                int r = (3+b[i][j])-a[i][j];
                if(r==2){
                    a[i][j] = (a[i][j]+2)%3;
                    a[i+1][j+1] = (a[i+1][j+1]+2)%3;
                    a[i+1][j] = (a[i+1][j]+1)%3;
                    a[i][j+1] = (a[i][j+1]+1)%3;

                }else{
                    a[i][j] = (a[i][j]+1)%3;
                    a[i+1][j+1] = (a[i+1][j+1]+1)%3;
                    a[i+1][j] = (a[i+1][j]+2)%3;
                    a[i][j+1] = (a[i][j+1]+2)%3;
                }
            }else{
                int r = b[i][j]-a[i][j];
                if(r==2){
                    a[i][j] = (a[i][j]+2)%3;
                    a[i+1][j+1] = (a[i+1][j+1]+2)%3;
                    a[i+1][j] = (a[i+1][j]+1)%3;
                    a[i][j+1] = (a[i][j+1]+1)%3;

                }else{
                    a[i][j] = (a[i][j]+1)%3;
                    a[i+1][j+1] = (a[i+1][j+1]+1)%3;
                    a[i+1][j] = (a[i+1][j]+2)%3;
                    a[i][j+1] = (a[i][j+1]+2)%3;
                }
            }
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(a[i][j] != b[i][j]){
                result.pb("NO");
                return;
            } 
        }
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