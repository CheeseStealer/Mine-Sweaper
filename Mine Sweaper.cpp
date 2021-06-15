#include <iostream>
#include <string>
#include <cstdlib.>
#include <ctime>
using namespace std;

int main(){
	srand(time(0));
	int mine_Implementation = rand() % 6;
	int mine_PositionX = 0;
	int mine_PositionY = 0;
	int mine_Count = 1;
	int location[10][10];
	int mine_Y_Axis[6];
	int mine_X_Axis[6];
	for (int i = 0; i < 10; i++){
		for (int j = 0; j < 10; j++){
			location[i][j] = 0;
		}
	}
	string loc_Disp[10][10];
	cout << "welcome to mine sweeper!" << endl;
	for (int i = mine_Implementation; i > 0; i--){
		mine_PositionY = rand() % 10;
		mine_PositionX = rand() % 10;
		location[mine_PositionY][mine_PositionX] = 1; //mine
	}
	for (int i = 0; i < 10; i++){
		for (int j = 0; j < 10; j++){
			if (location[i][j] == 1){
				mine_Count = mine_Count + 1;
				mine_Y_Axis[mine_Count] = i;
				mine_X_Axis[mine_Count] = j;
			}
		}
	}
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
	cout << "Mines: " << mine_Count << endl;
	for (int i = mine_Count; i > 0; i--){
		
	}

    while (1==1) {}
	return 0;
}