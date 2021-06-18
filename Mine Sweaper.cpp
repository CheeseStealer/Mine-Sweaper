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
	srand(time(0));
	int mine_Implementation = (rand() % 10 + 11);
	int mine_PositionX = 0;
	int mine_PositionY = 0;
	int mine_Count = 0;
	int location[10][10];
	int mine_Y_Axis[10];
	int mine_X_Axis[10];
	for (int i = 0; i < 10; i++){
		for (int j = 0; j < 10; j++){
			location[i][j] = 0;
		}
	}
	string loc_Disp[10][10];
	cout << "welcome to mine sweeper!" << endl;
	for (int i = mine_Implementation; i >= 1; i--){
		mine_PositionY = (rand() % 10) + 1;
		mine_PositionX = (rand() % 10) + 1;
		while (location[mine_PositionY][mine_PositionX] == 1){
			mine_PositionY = (rand() % 10) + 1;
		    mine_PositionX = (rand() % 10) + 1;
			if (location[mine_PositionY][mine_PositionX] == 0){
				location[mine_PositionY][mine_PositionX] = 1; //mine
			}
		}
		if (location[mine_PositionY][mine_PositionX] == 0){
			location[mine_PositionY][mine_PositionX] = 1; //mine
		}
	}
	for (int i = 0; i < 10; i++){
		for (int j = 0; j < 10; j++){
			if (location[i][j] == 1){
				mine_Count++;
				mine_Y_Axis[mine_Count] = i;
				mine_X_Axis[mine_Count] = j;
			}
		}
	}
	mine_Count = mine_Count - 1;
	cout << "1 2 3 4 5 6 7 8 9 10" << endl;
	for (int i = 0; i < 10; i++){
		for (int j = 0; j < 10; j++){
			loc_Disp[i][j] = "~";
			cout << loc_Disp[i][j] << " ";
			if (j == 9){
				cout << i + 1;
			}
		}
		cout << endl;
	}
	cout << "Mines: " << mine_Count << endl << "Actual Mines: " << mine_Implementation << endl;
	for (int i = mine_Count; i > 0; i--){
		setConsoleCursorPosition(mine_X_Axis[i] + 1,mine_Y_Axis[i] + 1);
		cout << "1";
	}
	setConsoleCursorPosition(1,13);
	for (int i = mine_Count; i > 0; i--){
		cout << (mine_X_Axis[i] + 1) << ", " << (mine_Y_Axis[i] + 1) << endl;
	}
    while (1==1) {}
	return 0;
}