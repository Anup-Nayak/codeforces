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
    int n;
    cin >> n;

    string s = to_string(n);

    if(s.size()<3){
        result.pb("NO");
        return;
    }else if(s.size()==3){
        string a = s.substr(0,2);
        string b = s.substr(2,1);
        if(a=="10" and b != "0" and b!="1"){
            result.pb("YES");
            return;
        }else{
            result.pb("NO");
            return;
        }
    }
    else{
        string a = s.substr(0,2);
        string b = s.substr(2,1);
        if(a=="10" and b != "0"){
            result.pb("YES");
            return;
        }else{
            result.pb("NO");
            return;
        }
    }
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