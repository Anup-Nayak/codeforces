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

void solve(vector <vector<int>>& result){
    int n;
    cin >> n;

    vector<int> a(n,0);
    vector<int> b(n,0);
    vector<int> c(n,0);

    fcin(n,a);
    fcin(n,b);
    fcin(n,c);

    ll tot = 0;
    for(int i=0;i<n;i++){
        tot += a[i];
    }

    if(tot%3==0){
        tot/=3;
    }else{
        tot = tot/3 + 1;
    }


    int i = 0;
    vector<int> ans(6,0);
    int aa = 0;

    ll sum1 = 0;
    ll sum2 = 0;
    ll sum3 = 0;

    int s = 0;

    while(i<n){

        

        if (sum1 != -1) sum1 += a[i];
        if (sum2 != -1) sum2 += b[i];
        if (sum3 != -1) sum3 += c[i];

        ll a = max(sum1,max(sum2,sum3));
        

        if(a >= tot){
            // ll a = INT_MAX;
            // if(sum1 >= tot) a = min(a,sum1);
            // if(sum2 >= tot) a = min(a,sum2);
            // if(sum3 >= tot) a = min(a,sum3);

            if(sum1 == a){
                ans[0]=s+1;
                ans[1]=i+1;
                sum1 = -1;
                sum2 = 0;
                sum3 = 0;
                aa = aa + 2;
            }
            else if(sum2 == a){
                ans[2]=s+1;
                ans[3]=i+1;
                sum1 = 0;
                sum2 = -1;
                sum3 = 0;
                aa = aa + 2;
            }
            else if(sum3 == a){
                ans[4]=s+1;
                ans[5]=i+1;
                sum1 = 0;
                sum2 = 0;
                sum3 = -1;
                aa = aa + 2;
            }
            s=i+1;
        }
        i++;

        if(aa == 6){
            result.pb(ans);
            return;
        }
    }
    vector<int> aw = {-1};
    result.pb(aw);
    return;
}

int main(){

    int t;
    cin >> t;
    vector<vector<int>> result;

    while(t--){
        solve(result);
    };

    for(int i = 0; i < result.size();i++){
        print(result[i]);
    }
    return 0;
}