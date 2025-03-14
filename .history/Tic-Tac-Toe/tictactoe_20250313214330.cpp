#include<iostream>

using namespace std;


void single_player(){

    return;
}

void multiplayer(){
    

    return;
}


int main(){
    cout << "Welcome to Tic-Tac-Toe" << endl;
    int choice = -1;
    
    while(choice != 0){
        cout << "Single (1), Multiplayer (2) or Exit (0)" << endl;

        cin >> choice;

        switch (choice){
            case 1:
                cout << "Have Fun!" << endl;
                break;
            case 2:
                cout << "May the best player win!" << endl;
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