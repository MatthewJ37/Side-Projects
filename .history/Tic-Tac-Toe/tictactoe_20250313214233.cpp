#include<iostream>

using namespace std;


int main(){
    cout << "Welcome to Tic-Tac-Toe" << endl;
    int choice = -1;
    
    while(choice != 0){
        cout << "Single (1), Multiplayer (2) or Exit (0)" << endl;

        cin >> choice;

        switch (choice){
            case 1:
                cout << "Welcome to Poker!" << endl;
                break;
            case 2:
                cout << "Welcome to Blackjack!" << endl;
                blackjack(deck);
                break;
            case 0:
                cout << "Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice" << endl;
                break;
        }
    }
    
}