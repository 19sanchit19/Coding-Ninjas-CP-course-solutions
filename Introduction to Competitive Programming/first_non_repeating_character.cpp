// Find Non-Repeating Character
// Send Feedback
// In a given string, find the first non-repeating character .You are given a string, that can contain repeating characters. Your task is to return the first character in this string that does not repeat. i.e., occurs exactly once. The string will contain characters only from English alphabet set, i.e., ('A' - 'Z') and ('a' - 'z'). If there is no non-repeating character print the first character of string.
// Input Format :
// Line 1 : A String , as mentioned above.
// Output Format :
// First non-repeating character
// Sample Input 1 :
// aDcadhc
// Sample Output 1:
// D
// Sample Input 2 :
// gdhIgHada
// Sample Output 2 :
// h

//solution

#include<iostream>
#include<cstring>
#include<unordered_map>
using namespace std;


char nonRepeatingCharacter(string str) {

	//Write your code here
	unordered_map<char, int> freq;
	for (int i = 0; i < str.size(); i++) {
		freq[str[i]]++;
	}
	char ans;
	int flag = 0, i;
	for (i = 0; i < str.size(); i++) {
		if (freq[str[i]] == 1) {
			flag = 1;
			break;
		}
	}
	if (flag == 1)
		ans = str[i];
	else
		ans = str[0];
	return ans;


}


