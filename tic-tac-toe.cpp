#include <iostream>
using namespace std;

void printTicTacToe(string positions[9]){
    for (int i=0; i<9; i++){
        if (i == 0){
            cout << endl;
        } else if (i % 3 == 0) {
            cout << endl << " ----------------- " << endl;
        }
        if ((i+1) % 3 != 0) {
            cout << "  " << positions[i] << "  | ";
        } else {
            cout << "  " << positions[i] << " ";
        }
    };
    cout << endl;
}

string checkGameWin(string positions[9]){
    // check rows
    for (int i=0; i<=2; i++){
        if (positions[i] == positions[i+3] && positions[i+3] == positions[i+6]){
            if (positions[i] != " "){
                return positions[i];
            }
        }
    }

    // check cols
    for (int i=0; i<=6; i+=3){
        if (positions[i] == positions[i+1] && positions[i+1] == positions[i+2]){
            if (positions[i] != " ") {
                return positions[i];
            }
        }
    }

    bool diagonalWin = (positions[0] == positions[4] && positions[4] == positions[8]) ||
    (positions[2] == positions[4] && positions[4] == positions[6]);

    if (diagonalWin && positions[4] != " ") {
        return positions[4];
    }

    return "";
}

int main(){
    string positions[9] = {" ", " ", " ", " ", " ", " ", " ", " ", " "};
    string currentMove;
    
    int currentTurn = 0;
    while (true) {
        int position;
        
        if (currentTurn % 2 == 0){currentMove = "X";} else {currentMove = "O";}

        cout << "Where does " << currentMove << " want to go? ";
        cin >> position;
        
        // check if move is valid
        if (positions[position-1] != " ") {
            cout << "That position is already taken" << endl;
            continue;
        } else if (position > 9) {
            cout << "That move is outside the range" << endl;
            continue;
        }
        
        positions[position-1] = currentMove;

        
        printTicTacToe(positions);
        string winner = checkGameWin(positions);

        if (winner != ""){
            cout << winner << " wins!";
            return 0;
        }
        currentTurn++;
    }


    return 0;
}