// Murder
// Send Feedback
// Once detective Saikat was solving a murder case. While going to the crime scene he took the stairs and saw that a number is written on every stair. He found it suspicious and decides to remember all the numbers that he has seen till now. While remembering the numbers he found that he can find some pattern in those numbers. So he decides that for each number on the stairs he will note down the sum of all the numbers previously seen on the stairs which are smaller than the present number. Calculate the sum of all the numbers written on his notes diary.
// Answer may not fit in integer . You have to take long.
// Input
// First line gives T, number of test cases.

// 2T lines follow.

// First line gives you the number of stairs N

// Next line gives you N numbers written on the stairs.
// Output
// For each test case output one line giving the final sum for each test case.
// Constraints
// T<=10

// 1<=N<=10^5

// All numbers will be between 0 and 10^6.
// Sample Input:
// 1
// 5
// 1 5 3 6 4
// Sample Output:
// 15
// Explanation:
// For the first number, the contribution to the sum is 0.
// For the second number, the contribution to the sum is 1.
// For the third number, the contribution to the sum is 1.
// For the fourth number, the contribution to the sum is 9 (1+5+3).
// For the fifth number, the contribution to the sum is 4 (1+3).
// Hence the sum is 15 (0+1+1+9+4).

//solution

//murder case
#include<bits/stdc++.h>
using namespace std;

long long  merge(int *Arr, int start, int mid, int end) {
	// create a temp array
	int temp[end - start + 1];

	long long sum = 0;
	// crawlers for both intervals and for temp
	int i = start, j = mid, k = 0;

	// traverse both arrays and in each iteration add smaller of both elements in temp
	while (i < mid && j <= end) {
		if (Arr[i] < Arr[j]) {
			sum += (Arr[i]) * (end - j + 1);      ////////changed here
			temp[k] = Arr[i];
			k += 1; i += 1;

		}
		else {
			temp[k] = Arr[j];
			k += 1; j += 1;
		}
	}

	// add elements left in the first interval
	while (i < mid) {
		temp[k] = Arr[i];
		k += 1; i += 1;
	}

	// add elements left in the second interval
	while (j <= end) {
		temp[k] = Arr[j];
		k += 1; j += 1;
	}

	// copy temp to original interval
	for (i = start; i <= end; i += 1) {
		Arr[i] = temp[i - start];
	}
	return sum;
}

// Arr is an array of integer type
// start and end are the starting and ending index of current interval of Arr

long long mergeSort(int *Arr, int start, int end) {
	long long count = 0;


	if (start < end) {
		int mid = (start + end) / 2;



		long long ans1 = mergeSort(Arr, start, mid);
		long long ans2 = mergeSort(Arr, mid + 1, end);
		long long ans3 = merge(Arr, start, mid + 1, end);
		return ans1 + ans2 + ans3;
	}
	return count;
}
// A function to split array into two parts.
long long solve(int A[], int n)
{
	long long ans = mergeSort(A, 0, n - 1);
	return ans;
}

int main()
{
	int t;
	cin >> t;
	//cout<<endl;
	while (t--)
	{
		int n;
		cin >> n;

		int A[n];
		for (int i = 0; i < n; i++)
		{
			cin >> A[i];
		}

		cout << endl;
		cout << solve(A, n) << endl;


	}
	return 0;
}
