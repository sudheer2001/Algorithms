#include <bits/stdc++.h> 
using namespace std;
#define endl '\n'
#define int long long int 

void solve()
{
    string n1;cin>>n1;
    int len=n1.length();
    int a,b;cin>>a>>b;
    int val=0,pa=1;

    for (int i = len-1; i >=0 ; i--)
    {
        if(n1[i]-'0'<=9){val+=(n1[i]-'0')*pa;}
        else{
            val+=(n1[i]-'A'+10)*pa;
        }
        pa*=a;
        // cout<<val<<"--";

    }

    vector<char>ans;
    while(val>0){
        int rem=val%b;
        if(rem<=9)ans.push_back(rem+'0');
        else{ans.push_back(rem+'A'-10);}
        val/=b;
    }
    for (int i = ans.size() - 1; i >= 0; i--)
    {
        cout<<ans[i];
    }
    cout<<endl;
    
    

}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int _t;cin>>_t;while(_t--)
    solve();
}