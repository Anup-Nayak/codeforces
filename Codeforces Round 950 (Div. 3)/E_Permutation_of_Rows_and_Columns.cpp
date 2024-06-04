#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <climits>
#include <vector>
#include <queue>
#include <set>
#include <numeric>
#include <unordered_map>
#include <stack>
#include <numeric>
#include <map>
#include <unordered_map>
 
using namespace std;
 
#define ll long long
#define llu long long unsigned
#define f(i, n) for (int i = 0; i < n; i++)
#define fi(i, a, n) for (int i = a; i < n; i++)
#define fii(i, n, a) for (int i = n; i > a; i--)
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
#define pii pair<int, int>
#define vp vector<pii>
#define vl vector<loc>
#define vvb ve<vb>
#define vvl ve<vll>
#define vvi ve<vi> 
#define ev(a) a.begin(), a.end()
#define pb push_back
#define mp make_pair

 
void print(vector<int> &a){
    f(i,a.size()){
        cout << a[i] << " ";
    }
    cout << endl;
}

void solve(vector <string>& result){
    ll n,m;
    cin>>n>>m;
    vector<vector<int>> a(n,vector<int>(m,0));    
    vector<vector<int>> b(n,vector<int>(m,0));   
    map<int,vector<int>> am;
    map<int,vector<int>> bm;
    f(i,n){
        f(j,m){
            int temp;
            cin>>temp;
            a[i][j]=temp;
            am[temp].pb(i);
            am[temp].pb(j);
        }
    };
    f(i,n){
        f(j,m){
            int temp;
            cin>>temp;
            b[i][j]=temp;
            bm[temp].pb(i);
            bm[temp].pb(j);
        }
    };
    
    vector<bool> visitedi(n,false);
    vector<bool> visitedj(m,false);

    f(i,n*m){

        int num = i+1;
        int row1 = am[num][0];
        int row2 = bm[num][0];
        int col1 = am[num][1];
        int col2 = bm[num][1];

        if(!visitedi[row1]){
            visitedi[row1]=true;

            //check for rows
            vector<int> r1 = a[row1];
            vector<int> r2 = b[row2];
            
            sorta(r1);
            sorta(r2);

            if(r1!=r2){
                result.pb("NO");
                return;
            }
        }

        if(!visitedj[col1]){
            visitedj[col1]=true; 

            //check for colums
            vector<int> c1;
            vector<int> c2;

            f(i,n){
                c1.pb(a[i][col1]);
                c2.pb(b[i][col2]);
            }

            sorta(c1);
            sorta(c2);

            if(c1!=c2){
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