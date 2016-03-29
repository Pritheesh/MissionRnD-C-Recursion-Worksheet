/*
Write a program to generate elements of a matrix in spiral order.
Store the generated elements in single dimensional array and return that array.

Directions for Spiral are : Go Right ,Go Down ,Go Left, Go Up
Ex:

Matrix:
1	2	3
4	5	6
7	8	9

Spiral order:
1	2	3	6	9	8	7	4	5

Given matrix is a two dimensional array(input_array) with dimensions rows, columns.
If rows, columns are invalid then return NULL.
If input_array is NULL then return NULL.

Example Input :
int board[2][3]={
				 {4,6,7},
				 {1,3,8}
				};
spiral(2,2,(int **)board); // Rows followed by columns followed by board

Example Output : Return an array consisting of {4,6,7,8,3,1};

Note : Check the function Parameters ,Its a double pointer .

*/


#include "stdafx.h"
#include<stdlib.h>

void getSpiral(int * result, int **arr, int rows, int columns, int left, int right, int top, int down, int dir, int index)
{
	if (left <= right && top <= down)
	{
		if (dir == 0)//go right
		{
			for (int i = left; i <= right; i++)
				result[index++] = (int)arr[top][i];

			getSpiral(result, arr, rows, columns, left, right, top + 1, down, 1, index);
		}
		else if (dir == 1)//go down
		{
			for (int i = top; i <= down; i++)
				result[index++] = (int)arr[i][right];

			getSpiral(result, arr, rows, columns, left, right - 1, top, down, 2, index);
		}
		else if (dir == 2)//go left
		{
			for (int i = right; i >= left; i--)
				result[index++] = (int)arr[down][i];

			getSpiral(result, arr, rows, columns, left, right, top, down - 1, 3, index);
		}
		else if (dir == 3)//go top
		{
			for (int i = down; i >= top; i--)
				result[index++] = (int)arr[i][left];

			getSpiral(result, arr, rows, columns, left + 1, right, top, down, 0, index);
		}
	}
}

int *spiral(int rows, int columns, int **input_array)
{
	if (rows <= 0 || columns <= 0 || !input_array)
		return NULL;
	int *result = (int *)malloc(sizeof(int) * rows * columns);
	int top = 0, down = rows - 1, right = columns - 1, left = 0, dir = 0;
	getSpiral(result, input_array, rows, columns, left, right, top, down, dir, 0);
	return result;
}
