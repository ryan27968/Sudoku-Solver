#include <include/backtrack.h>
#include <include/valid.h>
#include <include/sudoku.h>
#include <include/io.h>
#include <stdio.h>

static void	backtrack(int x, int y)
{
	unsigned char	result[9];
	unsigned char	*temp;

	if (y == 8 && x == 9)
		savesudoku(g_globals.sudoku);
	else if (x == 9)
	{
		++y;
		x = 0;
	}
	if (g_globals.sudoku[y][x])
	{
		backtrack(x + 1, y);
		return ;
	}
	temp = possibilities(g_globals.sudoku, x, y);
	for(int i = 0; i < 9; ++i)
		result[i] = temp[i];
	for(int i = 0; result[i]; ++i)
	{
		g_globals.sudoku[y][x] = result[i];
		backtrack(x + 1, y);
	}
	g_globals.sudoku[y][x] = 0;
}

void			start_backtracking(void)
{
	backtrack(0, 0);
}
