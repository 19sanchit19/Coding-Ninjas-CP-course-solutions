// Extract Unique characters
// Send Feedback
// Given a string, you need to remove all the duplicates. That means, the output string should contain each character only once. The respective order of characters should remain same.
// Input format :
// String S
// Output format :
// Output String
// Constraints :
// 0 <= Length of S <= 10^8
// Sample Input 1 :
// ababacd
// Sample Output 1 :
// abcd
// Sample Input 2 :
// abcde
// Sample Output 2 :
// abcde

//solution

char* uniqueChar(char *str) {
	// Write your code here
	int n;
	for (int i = 0; str[i] != '\0'; i++) {n = i;}
	int j = 0;
	n++;

	int arr[255] = {0};

	for (int i = 0; i < n; i++)
	{
		arr[int(str[i])]++;
	}
	for (int i = 0; i < 255; i++)
	{
		if (arr[i] != 0)
			j++;
	}
	char* c = new char[j];
	j = 0;
	for (int i = 0; i < n; i++)
	{
		if (arr[str[i]] != 0)
		{
			c[j] = str[i];
			j++;
			arr[str[i]] = 0;
		}
	}
	//cout<<c;
	return c;
}