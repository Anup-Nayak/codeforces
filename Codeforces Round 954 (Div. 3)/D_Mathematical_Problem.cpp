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
    string s;
    cin >> s;

    if(n==2){
        result.pb(stoi(s));
        return;
    }else if(n==3){
        if(s[0]==0 or s[2]==0){
            result.pb(0);
            return;
        }else{
            int mini = INT_MAX;
            int a = stoi(s.substr(0,1));
            int b = stoi(s.substr(1,2));
            int c = stoi(s.substr(0,2));
            int d = stoi(s.substr(2,1));

            mini = min(a+b,mini);
            mini = min(a*b,mini);
            mini = min(c+d,mini);
            mini = min(c*d,mini);
            result.pb(mini);
            return;
        }
    }else{
        for(int i=0;i<n;i++){
            if(s[i]=='0'){
                result.pb(0);
                return;
            }
        }

        bool one = true;
        for(int i=0;i<n;i++){
            if(s[i]!='1'){
                one = false;
                break;
            }
        }

        if(one){
            result.pb(11);
            return;
        }else{
            int ans = INT_MAX;
            for(int i=0;i<n-1;i++){
                vector<int> vals;
                for(int j=0;j<n;j++){
                    if(j==i){
                        int a = stoi(s.substr(j,2));
                        vals.pb(a);
                        j++;
                    }else{
                        int a = stoi(s.substr(j,1));
                        vals.pb(a);
                    }    
                    
                }
                int ans1 = vals[0];
                for(int i=1;i<n-1;i++){
                    ans1 = min(ans1*vals[i],ans1+vals[i]);
                }

                ans = min(ans,ans1);

            }
            result.pb(ans);
            return;

        }


        

        // int ind = 0;
        // int mini = INT_MAX;

        // for(int i=0;i<n-1;i++){
        //     if(s[i]!='1' and s[i+1]!='1'){
        //         int a = stoi(s.substr(i,2));
        //         if(a < mini){
        //             mini = a;
        //             ind = i;
        //         }
        //     }
        // }

        // if(mini == INT_MAX){
        //     bool one = true;
        //     for(int i=0;i<n;i++){
        //         if(s[i]!='1'){
        //             one = false;
        //             break;
        //         }
        //     }

        //     if(one){
        //         result.pb(11);
        //         return;
        //     }else{
        //         for(int i=0;i<n-1;i++){
        //             if(s[i]!='1' or s[i+1]!='1'){
        //                 int a = stoi(s.substr(i,2));
        //                 if(a < mini){
        //                     mini = a;
        //                     ind = i;
        //                 }
        //             }
        //         }
        //     }
        // }

        // vector<int> vals;
        // for(int i=0;i<n;i++){
        //     if(i==ind){
        //         int a = stoi(s.substr(i,2));
        //         vals.pb(a);
        //         i++;
        //     }else{
        //         int a = stoi(s.substr(i,1));
        //         vals.pb(a);
        //     }
        // }

        // ll ans = vals[0];
        // for(int i=1;i<n-1;i++){
        //     ans = min(ans*vals[i],ans+vals[i]);
        // }
        
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