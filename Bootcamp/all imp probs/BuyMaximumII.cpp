#include <bits/stdc++.h> 
using namespace std;
#define endl '\n'
#define int long long int 

signed main(){
int n=1000;int ans=0;
for (int i = 1; i < 1000; i++)
{
    int x=(i+1)*(i+3);
    for (int j = 2; j < sqrt(x)+1; j++)
    {
        if(x==j*j){ans++;}
    }    
}
cout<<ans<<endl;
}

