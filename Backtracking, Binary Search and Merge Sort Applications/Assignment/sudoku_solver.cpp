// Sudoku Solver
// Send Feedback
// Given a 9*9 sudoku board, in which some entries are filled and others are 0 (0 indicates that the cell is empty), you need to find out whether the Sudoku puzzle can be solved or not i.e. return true or false.
// Input Format :
// 9 Lines where ith line contains ith row elements separated by space
// Output Format :
//  true or false
// Sample Input :
// 9 0 0 0 2 0 7 5 0
// 6 0 0 0 5 0 0 4 0
// 0 2 0 4 0 0 0 1 0
// 2 0 8 0 0 0 0 0 0
// 0 7 0 5 0 9 0 6 0
// 0 0 0 0 0 0 4 0 1
// 0 1 0 0 0 5 0 8 0
// 0 9 0 0 7 0 0 0 4
// 0 8 2 0 4 0 0 0 6
// Sample Output :
// true

//solution

#include<bits/stdc++.h>
vector<int> findoptions(int output[][9], int x, int y) {
	int arr[10];
	for (int i = 0; i < 10; i++)
		arr[i] = 1;
	for (int i = 0; i < 9; i++) {		//checking in col
		if (output[i][y] != 0)
			arr[output[i][y]] = 0;
	}
	for (int j = 0; j < 9; j++) {		//checking in row
		if (output[x][j] != 0)
			arr[output[x][j]] = 0;
	}
	//checking in 3*3 grid
	x = x - x % 3;
	y = y - y % 3;
	for (int i = x; i < x + 3; i++) {
		for (int j = y; j < y + 3; j++) {
			if (output[i][j] != 0)
				arr[output[i][j]] = 0;
		}
	}
	vector<int> finaloptions;
	for (int i = 1; i < 10; i++) {
		if (arr[i] == 1)
			finaloptions.push_back(i);
	}
	return finaloptions;
}
bool sudokuhelper(int board[][9])
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (board[i][j] == 0)
			{
				vector<int> options = findoptions(board, i, j);		//make findoptions function
				for (int k = 0; k < options.size(); k++)
				{
					board[i][j] = options[k];
					bool status = sudokuhelper(board);
					board[i][j] = 0;
					if (status)
						return true;
				}
				return false;
			}
		}
	}
	return true;
}
bool sudokuSolver(int board[][9]) {
	/*int** output=new int*[9];
	for(int i=0;i<9;i++){
	  output[i]=new int[9];
	  for(int j=0;j<9;j++)
	    output[i][j]=board[i][j];
	}//creating dynamically allocated 2d array for testing ====> filled the input values in it*/
	bool ans = sudokuhelper(board);
	/*for(int i=0;i<9;i++)
	  delete []output[i];
	delete []output;*/
	return ans;
}
