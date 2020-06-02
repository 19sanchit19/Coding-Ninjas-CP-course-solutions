// Aggressive Cows Problem
// Send Feedback
// Farmer John has built a new long barn, with N (2 <= N <= 100,000) stalls. The stalls are located along a straight line at positions x1,...,xN (0 <= xi <= 1,000,000,000).
// His C (2 <= C <= N) cows don't like this barn layout and become aggressive towards each other once put into a stall. To prevent the cows from hurting each other, FJ wants to assign the cows to the stalls, such that the minimum distance between any two of them is as large as possible. What is the largest minimum distance?
// Input
// t – the number of test cases, then t test cases follows.
// * Line 1: Two space-separated integers: N and C
// * Lines 2..N+1: Line i+1 contains an integer stall location, xi
// Output
// For each test case output one integer: the largest minimum distance.
// Sample Input :
// 1
// 5 3
// 1
// 2
// 8
// 4
// 9
// Sample Output:
// 3
// Output details:
// FJ can put his 3 cows in the stalls at positions 1, 4 and 8,
// resulting in a minimum distance of 3.


//solution

#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;

	while (t--)
	{
		vector<ll> A;
		int n;
		cin >> n;
		int c;
		cin >> c;

		for (int i = 0 ; i < n ; i ++)
		{
			ll x;
			cin >> x;
			A.push_back(x);
		}

		sort(A.begin() , A.end());

		ll begin = 0 ;
		ll end = A[A.size() - 1] - A[0];
		ll ans = INT_MIN;

		while (begin <= end)
		{

			ll mid = (begin) + (end - begin) / 2;
			ll last = 0 ;
			ll ctr = 1;
			int flag = 0;

			for (ll i = 1 ; i  < A.size() ; i ++)
			{

				if ( A[i] - A[last] >= mid  )
				{
					last = i;
					ctr++;
				}

				if ( ctr == c )
				{
					flag = 1;
					break;
				}

			}
			// cout<<begin <<" "<<end<<" "<<flag<<" #";
//
			if (flag == 1)
			{
				ans = max(mid , ans);
				begin = mid + 1;
			}
			else
			{
				end = mid - 1;
			}

		}

		cout << ans << "\n";
	}
}