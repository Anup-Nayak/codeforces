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
 
void print(vector<string> &a){
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

    vector<int> num(n,0);
    fcin(n,num);

    int m;
    cin >> m;

    vector<string> str1;
    for(int i=0;i<m;i++){
        string s;
        cin >> s;
        str1.pb(s);
    }
    // cout<<str1.size()<<endl;
    // print(str1);

    map<int,int> numcount;
    map<int,int> mapping;

    for(auto &elem:num){
        numcount[elem]++;
        mapping[elem] = -1;
    }


    for(int k=0;k<str1.size();k++){
        string s = str1[k];
        bool b = true;
        if(s.size() != n){
            result.pb("NO");
            // cout << s << endl;
        }else{
            map<char,int> strcount;
            for(int i=0;i<n;i++){
                strcount[s[i]]++;
            }
            for(int i=0;i<n;i++){
                if(strcount[s[i]] != numcount[num[i]]){
                    b = false;
                }else{
                    if(mapping[num[i]]==-1){
                        mapping[num[i]]=(s[i]-'a');
                    }else{
                        if(mapping[num[i]]!=(s[i]-'a')){
                            b = false;
                        }
                    }
                }
            }
            if(b){
                result.pb("YES");
            }else{
                result.pb("NO");
            }
        }
        for(auto &elem:num){
            mapping[elem] = -1;
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