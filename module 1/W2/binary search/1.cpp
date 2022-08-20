// Description

// Given a rotated sorted array. Find the index of the minimum element in the array.

// All the elements are distinct.

 


// Input Format

// The first line contains T, the number of test cases (1<=T<=10000).

// The first line contains an integer N where 1<=N<=10^5.

// The second line contains N space-separated integers A1,A2....AN where -1e9<=Ai<=1e9.

// Sum of N over all test cases ≤10^6.


// Output Format

// For each test case print the index of the minimum element in the array.

// 0-indexed.


// Sample Input 1

// 5
// 5
// 3 4 5 1 2
// 5
// 4 5 1 2 3
// 5
// 5 1 2 3 4
// 5
// 1 2 3 4 5
// 5
// 2 3 4 5 1

// Sample Output 1

// 3
// 2
// 1
// 0
// 4


//---------------------- Answer-------------------------


#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int

int n,X;
int arr[100100];

bool check(int x){
	if(arr[x]<X){return 1;}
	return 0;
}

void solve(){
	int n;cin>>n;
	// int arr[n];
	for (int i = 0; i < n; ++i)
		{
			cin>>arr[i];
		}
	X=arr[0];	
	int lo=0,hi=n-1,ans=0;
	while(lo<=hi){
		int mid=(lo+hi)/2;
		if(check(mid)){ans=mid;hi=mid-1;}
		else{lo=mid+1;}
	}
	cout<<ans<<endl;
}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int _t;cin>>_t;while(_t--)
	solve();
}