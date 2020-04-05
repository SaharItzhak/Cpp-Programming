//======================== INCLUDE ========================//
#include <iostream>
//========================= USING =========================//
using namespace std;
//========================= CONST =========================//
const int ROWS = 5;
const int COLS = 4;
enum maze_vals_t {EMPTY, WALL, PATH, DEAD};
//======================= PROTOTYPE =======================//
bool maze(maze_vals_t mat[][COLS], int curr_row, int curr_col);
//========================= MAIN ==========================//
int main()
{
	maze_vals_t mat[ROWS][COLS] =
	{{WALL, WALL, WALL, WALL},
	{EMPTY, EMPTY, EMPTY, WALL},
	{WALL, EMPTY, EMPTY, WALL},
	{WALL, EMPTY, WALL, WALL},
	{WALL, WALL, WALL, WALL}};

	cout << maze(mat, 3, 1);


	return EXIT_SUCCESS;
}
//======================= FUNCTIONS =======================//
bool maze(maze_vals_t mat[][COLS], int curr_row, int curr_col)
{
	if (mat[curr_row][curr_col] != EMPTY)
		return false;

	mat[curr_row][curr_col] = PATH;
	
	if (curr_col == 0 || curr_col == COLS - 1 ||
		curr_row == 0 || curr_row == ROWS - 1)
		return true;

	if (maze(mat, curr_row - 1, curr_col)) // up
		return true;
	if (maze(mat, curr_row, curr_col + 1)) // right
		return true;
	if (maze(mat, curr_row + 1, curr_col)) // down
		return true;
	if (maze(mat, curr_row, curr_col - 1)) // left
		return true;

	mat[curr_row][curr_col] = DEAD;
	return false;
}
