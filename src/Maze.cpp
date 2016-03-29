/*
Find if there is a connecting path between two given points in the maze.
The maze is a matrix of order MxN, check if there exists a path between (x1,y1) and (x2,y2).
Two points are said to connected if there is a series of 1's non-diagonally.
Example:
Maze of order 4x4:

1	0	1	0
1	1	0	0
0	1	0	1
0	1	1	1

(x1,y1):(0,0)
(x2,y2):(2,3)

In this case, there exists a connected path:
1
1	1
	1		1
	1	1	1

Since there is a connected path, your function has to return 1.
If a path doesn't exist between two co-ordinates then return 0.
If the co-ordinates are invalid or size of the matrix is invalid then return 0.

Function Prototype :path_exists(int *maze, int rows, int columns, int x1, int y1, int x2, int y2) ;
Maze: Pointer to first element of an array .
rows : No of rows
columns : Columns
x1,x2,y1,y2: Co-ordinates

Hint : You can use path_exists as a wrapper function for your original recursive function which might take
more parameters .
*/

#include<stdlib.h>

int canGo(int *maze, int rows, int columns, int x, int y)//To check if it is valid to go
{
	if (x >= 0 && y >= 0 && x < rows && y < columns && *(maze + x * columns + y))
		return 1;
	return 0;
}

int path(int *maze, int rows, int columns, int x1, int y1, int x2, int y2, int dir)//dir = 0 for up, 1 for down, 2 for right, 3 for left
{
	if (x1 == x2 && y1 == y2)
		return 1;

	if (canGo(maze, rows, columns, x1, y1))
	{
		//going down
		if (dir != 0 && path(maze, rows, columns, x1 + 1, y1, x2, y2, 1))// can not go down if previously went up
			return 1;

		//going right
		if (dir != 3 && path(maze, rows, columns, x1, y1 + 1, x2, y2, 2))//can't go right if previously went left
			return 1;

		//going up
		if (dir != 1 && path(maze, rows, columns, x1 - 1, y1, x2, y2, 0))//can't go up if previously went down
			return 1;

		//going left
		if (dir != 2 && path(maze, rows, columns, x1, y1 - 1, x2, y2, 3))//can't go left if previously went right
			return 1;

		return 0;
	}
	return 0;
}

int path_exists(int *maze, int rows, int columns, int x1, int y1, int x2, int y2)
{
	if (rows <= 0 || columns <= 0 || x1 < 0 || y1 < 0 || x2 < 0 || y2 < 0 || *(maze + x1 * columns + y1) == 0 || *(maze + x2 * columns + y2) == 0)
		return 0;
	return path(maze, rows, columns, x1, y1, x2, y2, -1);
}
