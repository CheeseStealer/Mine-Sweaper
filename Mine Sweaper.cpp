#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <Windows.h>
using namespace std;

void setConsoleCursorPosition(int x, int y){
	HANDLE aHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD position = {(SHORT) ((x * 2) - 2), (SHORT) (y + 1)};
	SetConsoleCursorPosition(aHandle, position);
}

int main(){
	srand(time(NULL));
	int grid[10][10];
	int num_of_mines = (rand() % 10) + 11;
	int mine_x, mine_y;
	int actual_mine_count = 0;
	string cell;

	cout << "Welcome to mine sweeper!" << endl << endl;
	
	// Initialize Grid
	for (int i = 0; i < 10; i++) { for (int j = 0; j < 10; j++) { grid[i][j] = 0; } }

	// Spawn Mines
	for (int i = 0; i < num_of_mines; i++) {
		mine_x = rand() % 10; mine_y = rand() % 10;
		while (grid[mine_x][mine_y] == 1) { mine_x = rand() % 10; mine_y = rand() % 10; }
		grid[mine_x][mine_y] = 1;
	}

	// Count mines
	for (int i=0; i<10; i++){ for (int j=0; j<10; j++) { if (grid[i][j] == 1) actual_mine_count++; } }
	
	// Display grid
	cout << "x > 1 2 3 4 5 6 7 8 9 10   y\n  |---------------------|  v" << endl;
	for (int i = 0; i < 10; i++){
		cout << "  | ";
		for (int j = 0; j < 10; j++){
			if (grid[j][i] == 0) { cell = "~"; }
			else { cell = "X"; }
			cout << cell << " ";
		}
		cout << "|  " << i+1 << endl;
	}
	cout << "  |---------------------|" << endl << endl;

	// Show the user how many "mines" there are and how many mines were actually spawned (for debug purposes)
	cout << "\"Mines\": " << num_of_mines << endl << "Actual Mines: " << actual_mine_count << endl;
	
	// Reset the cursor back to a good starting position
	setConsoleCursorPosition(1, 1);

	// Infinate loop to keep the window open
    while (1==1) {}

	// Return statement to show that everything is ok
	return 0;
}