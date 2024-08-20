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

    vector<int> arr(n,0);

    int maxiOdd = INT_MIN;
    int maxiEven = INT_MIN;

    int evens = 0;
    int odds = 0;
    vector<int> even;

    for(int i=0;i<n;i++){
        int temp;
        cin >> temp;

        arr[i]=temp;

        if(temp&1){
            maxiOdd = max(maxiOdd,temp);
            odds++;
        }else{
            maxiEven = max(maxiEven,temp);
            even.pb(temp);
            evens++;
        }
    }

    int ans = 0;
    sorta(even);

    if(evens==0 or odds ==0){
        result.pb(ans);
        return;
    }else{
        for(int i=0;i<even.size();i++){
            if(even[i]>maxiOdd){
                ans++;
                ans += evens;
                result.pb(ans);
                return;
            }else{
                evens--;
                maxiOdd = max(maxiOdd,maxiOdd+even[i]);
                ans++;
            }
        }
        result.pb(ans);
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