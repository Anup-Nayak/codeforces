#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
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

void printl(int a, int b, int c, int d)
{
    cout << "? " << a << " " << b << " " << c << " " << d << endl;
}
void printll(vector<ll> &a)
{
    f(i, a.size())
    {
        cout << a[i] << " ";
    }
    cout << endl;
}
void printvll(ve<vll>& a){
    f(i,a.size()){
        printll(a[i]);
    }
}


// int same(vector<int> a, vector<int> b){
//     int ans = 0;
//     for(int i = 0; i < 3; i++){
//         for(int j = 0; j < 2; j++){
//             if(a[i] == b[j]){
//                 ans++;
//             }
//         }
//     }
//     return ans;
// }

void solve(vector <unsigned long long>& result){
    int n;
    cin >> n;

    vector<int> arr;
    for(int i=0;i<n;i++){
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }

    unsigned long long ans = 0;

    //logic
    // for(int i = 0;i < n-2; i++ ){
    //     int j = i+1;
    //     while(j < n-2){
    //         if(arr[i] == arr[j] and arr[i+1] == arr[j+1] and arr[i+2] != arr[j+2]){
    //             ans ++;
    //             j++;
    //         }else if(arr[i] == arr[j] and arr[i+1] != arr[j+1] and arr[i+2] == arr[j+2]){
    //             ans ++;
    //             j++;
    //         }else if(arr[i] != arr[j] and arr[i+1] == arr[j+1] and arr[i+2] == arr[j+2]){
    //             ans ++;
    //             j++;
    //         }else {
    //             vector<int> a = {arr[i],arr[i+1],arr[i+2]};
    //             vector<int> b = {arr[j+1],arr[j+2]};
    //             if(same(a,b) >=1){
    //                 j++;
    //             }else{
    //                 j=j+2;
    //             }
    //         }
    //     }
    // }

    map<int,map<int,long long>> first,second,third;
    map<int,map<int,map<int, long long>>> same;
    int a,b,c;
    
    for(int i=0;i<n-2;i++){
        a=arr[i];
        b=arr[i+1];
        c=arr[i+2];
        ans += first[b][c] + second[a][c] + third[a][b] - 3*same[a][b][c];
        first[b][c]++;
        second[a][c]++;
        third[a][b]++;
        same[a][b][c]++;
    }

    result.push_back(ans);

}

int main(){

    int t;
    cin >> t;
    vector<unsigned long long> result;

    while(t--){
        solve(result);
    };

    for(int i = 0; i < result.size();i++){
        cout << result[i] << endl;
    }
    return 0;
}