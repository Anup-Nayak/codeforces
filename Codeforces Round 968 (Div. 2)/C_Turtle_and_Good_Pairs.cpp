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
bool sortbysec(const pair<int,int> &a,
            const pair<int,int> &b)
{
    return (a.first > b.first);
}

void solve(vector <ll>& result){
    int n;
    cin >> n;

    string s;
    cin >> s;

    vector<pair<int,char>> count(26,make_pair(0,'-'));
    for(int i=0;i<n;i++){
        count[s[i]-'a'].first++;
        count[s[i]-'a'].second = s[i];
    }

    sort(count.begin(),count.end(),sortbysec);

    vector<char> ans1(n,'-');
    int ind = 0;
    for(int i=0;i<26;i++){
        if(count[i].first == 0 or count[i].second == '-'){
            break;
        }
        int a = count[i].first;
        char b = count[i].second;
        while(a){
            ans1[ind]=b;
            a--;
            ind++;
        }
    }
    
    vector<char> ans(n,'-');

    int full = 0;
    int offset = 1;

    int ind1 = 0;
    int ind0 = 0;
    
    while(full != n){
        if(ans[ind0]!='-' or ind0 >= n){
            ind0 = offset;
            offset+=2;
        }else{
            ans[ind0] = ans1[ind1];
            ind0+=2;
            ind1++;
            full++;
        }
    }


    string as = "";
    for(int i=0;i<n;i++){
        as += ans[i];
    }

    cout << as << endl;

    

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