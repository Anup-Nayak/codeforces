#include <bits/stdc++.h>

using namespace std;
#define int int64_t

int max3pair(int a, int b , int c)
{
    int maaa = max(a,max(b,c));
    int miii = min(a,min(b,c));

    return a+b+c-miii-maaa;
}

void solve()
{
    int n; cin >> n;
    vector<int> arr(n);
    
    for(int i =0; i < n; i++)
    {
        cin >> arr[i];
        
    }
    vector<int> ans;

    for (size_t i = 0; i < n; i++)
    {
        if (i == 0)
        {
            ans.push_back(max3pair(arr[i],arr[i+1],0));
        }
        
        else if (i == n-1)
        {
            ans.push_back(max3pair(0,arr[i-1],arr[i]));
        }

        else
        {
            ans.push_back(max3pair(arr[i-1],arr[i],arr[i+1]));
        }
        
        
    }

    cout << *max_element(ans.begin(),ans.end()) << endl; return;
    
    
    
    
    
    
}

int32_t main()
{
    int t; cin>>t;
    while(t--){solve();}
}