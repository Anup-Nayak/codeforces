#include <bits/stdc++.h>
 
using namespace std;
 

#define f(i, n) for (int i = 0; i < n; i++)
#define fcin(n, arr)            \
    for (int i = 0; i < n; i++) \
    {                           \
        cin >> arr[i];          \
    }
#define sorta(a) sort(a.begin(),a.end())
#define sortd(a) sort(a.begin(),a.end(),greater<int>())
 

#define pb push_back
 
void print(vector<long long> &a){
    f(i,a.size()){
        cout << a[i] << " ";
    }
    cout << endl;
}

string binary(long long n) {
    if (n == 0) return "0";
    
    string binary = "";
    while (n > 0) {
        binary = (n % 2 == 0 ? "0" : "1") + binary;
        n /= 2;
    }
    
    return binary;
}

void solve(vector <long long>& result){
    long long n,k;
    cin >> n >> k;

    vector<long long> a(n,0);
    vector<long long> b(n,0);

    fcin(n,a);
    fcin(n,b);

    vector<long long> one;
    vector<long long> zero;

    for(long long i=0;i<n;i++){
        if(b[i]==1){
            one.pb(a[i]);
        }else{
            zero.pb(a[i]);
        }
    }

    long long maxOne = INT_MIN;
    long long maxZero = INT_MIN;

    if(one.size())  maxOne = *max_element(one.begin(),one.end());
    if(zero.size())  maxZero = *max_element(zero.begin(),zero.end());

    if(one.size()==0){
        sorta(a);
        long long ans = a[n-1]+a[(n-1)/2];
        result.pb(ans);
        return;
    }else if(zero.size()==0){
        sorta(a);
        long long ans = a[n-1]+a[(n-1)/2]+k;
        result.pb(ans);
        return;
    }

    if(maxOne+k > maxZero){
        for(long long i=0;i<n;i++){
            if(a[i]==maxOne){
                a[i]=a[i]+k;
                break;
            } 
        }

        sorta(a);
        long long ans = a[n-1]+a[(n-1)/2];
        result.pb(ans);
        return;
    }else{
        // sorta(zero);
        // sortd(one);
        // long long nn = zero.size();
        // long long med = zero[(nn-1)/2];
        // vector<int> newOne;
        // for(int i=0;i<one.size();i++){
        //     if(one[i]+k < med){
        //         zero.pb(one[i]);
        //     }else{
        //         newOne.pb(one[i]);
        //     }
        // }

        // sorta(zero);
        // nn = zero.size();
        // med = zero[(nn-1)/2];

        // for(auto el:newOne){
        //     if(el > med){
        //         nn++;
        //         med = zero[(nn-1)/2];
        //     }
        //     else if(med-el < k){
        //         zero.pb(med+1);
        //         k = k - (med-el) - 1;
        //         nn++;
        //         med = zero[(nn-1)/2];

        //     }else{
        //         zero.pb(el);
        //     }
        // }

        // nn = zero.size();
        // med = zero[(nn-1)/2];
        // long long ans  = a[n-1]+med;
        long long ans = 0;
        result.pb(ans);
        return;
    }

    cout << maxOne << " " << maxZero << endl;

}

int main(){

    int t;
    cin >> t;
    vector<long long> result;

    while(t--){
        solve(result);
    };

    for(int i = 0; i < result.size();i++){
        cout << result[i] << endl;
    }
    return 0;
}