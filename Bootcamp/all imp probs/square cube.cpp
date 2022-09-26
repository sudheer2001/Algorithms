#include <bits/stdc++.h> 
using namespace std;
#define endl '\n'
#define int long long int 

unordered_set<int>sq,cube;

void solve()
{
    int q,n;cin>>q>>n;
    if(q==1){
        if(sq.find(n)!=sq.end()){cout<<"YES\n";}
        else{cout<<"NO\n";}
    }
    else{
        if(cube.find(n)!=cube.end()){cout<<"YES\n";}
        else{cout<<"NO\n";}
    }   
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int i=1,square=1,cub=1;
    while(square<=1e7){
        sq.insert(square);
        i++;
        square=i*i;
    }
    i=1;
    while(cub<=1e7){
        cube.insert(cub);
        i++;
        cub=pow(i,3);
    }
    int _t;cin>>_t;while(_t--)
    solve();
}