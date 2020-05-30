// Remove Duplicates
// Send Feedback
// Given an integer array A which contains duplicates. Remove duplicates from the array and return a new array without any duplicates.
// That is, it should contain only unique elements.
// NOTE : Best case time complexity-O(n) where n is the no of elements in the array.
// Input Format :
// First element is the size(N) of the array followed by N integers which are elements of the array separated by space
// Sample Input :
// 10 105 106 111 114 105 135 138 111 147 114
// Sample Output :
// 105 106 111 114 135 138 147

//solution

#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;


vector<int> removeDuplicates(vector<int> input) {
	unordered_map<int, bool> ans;
	vector<int> ans1;
	for (int i = 0; i < input.size(); i++) {
		if (ans[input[i]] == false)
			ans1.push_back(input[i]);
		ans[input[i]] = true;
	}
	return ans1;

}


