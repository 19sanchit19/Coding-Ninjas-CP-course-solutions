// Stock Span
// Send Feedback
// The span si of a stock’s price on a certain day i is the minimum number of consecutive days (up to the current day) the price of the stock has been less than its price on that ith day. If for a particular day, if no stock price is greater then just count the number of days till 0th day including current day.
// For eg. if given price array is {3, 6, 8, 1, 2}, span for 4th day (which has price 2) is 2 because minimum count of consecutive days (including 4th day itself) from current day which has price less than 4th day is 2 (i.e. day 3 & 4). Similarly, span for 2nd day is 3 because no stock price in left is greater than 2nd day's price. So count is 3 till 0th day.
// Given an input array with all stock prices, you need to return the array with corresponding spans of each day.
// Note : Try doing it in O(n).
// Input format :
// Line 1 : Integer n, Arrays Size
// Line 2 : Price for n days (separated by space). It can contain duplicate values`
// Constraints:
// Time Limit: 1 second
// Size of input array lies in the range: [1, 1000000]
// Output format :
// Return an array that contain span for each day
// Sample Input 1 :
// 8
// 60 70 80 100 90 75 80 120
// Sample Output 1 :
// 1 2 3 4 1 1 2 8
// Sample Input 2 :
// 4
// 1 1 1 1
// Sample Output 2 :
// 1 1 1 1

//solution

#include<stack>
void calculateSpan(int price[], int n, int S[])
{
	// Create a stack and push index of first
	// element to it
	stack<int> st;
	st.push(0);

	// Span value of first element is always 1
	S[0] = 1;

	// Calculate span values for rest of the elements
	for (int i = 1; i < n; i++)
	{
		// Pop elements from stack while stack is not
		// empty and top of stack is smaller than
		// price[i]
		while (!st.empty() && price[st.top()] < price[i])
			st.pop();

		// If stack becomes empty, then price[i] is
		// greater than all elements on left of it,
		// i.e., price[0], price[1],..price[i-1].  Else
		// price[i] is greater than elements after
		// top of stack
		S[i] = (st.empty()) ? (i + 1) : (i - st.top());

		// Push this element to stack
		st.push(i);
	}
}
int* stockSpan(int *price, int size) {
	// Write your code here
	int s[size];
	calculateSpan(price, size, s);
	int* span = new int[size];
	for (int i = 0; i < size; i++) {
		span[i] = s[i];
	}
	/*int* span=new int[size];
	stack<int> index_max;
	index_max.push(0);
	span[0]=1;
	for(int i=1;i<size;i++){
	  if(arr[i]>arr[index_max.top()]){

	  }
	  else{

	  }
	}
	*/
	return span;

}