#include<iostream>
#include<vector>
#include<ctime>

using namespace std;

#if defined(_WIN32) || defined(__MSDOS__)
   #define SPADE   "\u2660"
   #define CLUB    "\u2663"
   #define HEART   "\u2661"
   #define DIAMOND "\u2662"
#else
   #define SPADE   "\xE2\x99\xA0"
   #define CLUB    "\xE2\x99\xA3"
   #define HEART   "\xE2\x99\xA5"
   #define DIAMOND "\xE2\x99\xA6"
#endif



void shuffle(vector<string>& deck)
{
    for(int i = 0; i < deck.size(); i++)
    {
        int j = rand() % (deck.size() - i) + i;
        swap(deck[i], deck[j]);
    }
}

void deal(vector<string>& deck, vector<string>& hand)
{
    hand.push_back(deck.back());
    deck.pop_back();
}

int blackjack_score(vector<string>& hand)
{
    int score = 0;
    int aceCount = 0;
    for(int i = 0; i < hand.size(); i++)
    {
        cout << hand[0] << endl;
        string value = hand[0];
        if(value == "A"){
            score += 11;
            aceCount++;
        }
        else if(value == "J" || value == "Q" || value == "K"){
            score += 10;
        }
        else{
            cout << value << endl;
            score += stoi(value);
        }
        cout << score << endl;
    }
    while(score > 21 && aceCount > 0)
    {
        score -= 10;
        aceCount--;
    }
    return score;
}

void blackjack(vector<string>& deck)
{
    vector<string> player;
    vector<string> dealer;
    deal(deck, player);
    deal(deck, dealer);
    deal(deck, player);
    deal(deck, dealer);

    cout << "Player: " << player[0] << " " << player[1] << endl;
    cout << "Dealer: " << dealer[0] << " ?" << endl;

    while(blackjack_score(player) < 21)
    {
        cout << "Would you like to hit or stay?" << endl;
        string choice;
        cin >> choice;
        if(choice == "hit")
        {
            deal(deck, player);
            cout << "Player: ";
            for(int i = 0; i < player.size(); i++)
            {
                cout << player[i] << " ";
            }
            cout << endl;
        }
        else if(choice == "stay")
        {
            break;
        }
        else
        {
            cout << "Invalid choice" << endl;
        }
    }

    if(blackjack_score(player) > 21)
    {
        cout << "Player busts!" << endl;
    }
    else
    {
        cout << "Player: ";
        for(int i = 0; i < player.size(); i++)
        {
            cout << player[i] << " ";
        }
        cout << endl;
        cout << "Dealer: ";
        for(int i = 0; i < dealer.size(); i++)
        {
            cout << dealer[i] << " ";
        }
        cout << endl;

        while(blackjack_score(dealer) < 17)
        {
            deal(deck, dealer);
            cout << "Dealer: ";
            for(int i = 0; i < dealer.size(); i++)
            {
                cout << dealer[i] << " ";
            }
            cout << endl;
        }

        if(blackjack_score(dealer) > 21)
        {
            cout << "Dealer busts!" << endl;
        }
        else if(blackjack_score(dealer) > blackjack_score(player))
        {
            cout << "Dealer wins!" << endl;
        }
        else if(blackjack_score(dealer) < blackjack_score(player))
        {
            cout << "Player wins!" << endl;
        }
        else
        {
            cout << "Push!" << endl;
        }
    }

}

int main()
{
    srand(time(NULL));
    vector<vector<char>> deck;
    for(int i = 0; i < 52; i++)
    {
        string symbol;
        if(i < 13){
            symbol = SPADE;
        }
        else if(i < 26){
            symbol = CLUB;
        }
        else if(i < 39){
            symbol = HEART;
        }
        else{
            symbol = DIAMOND;
        }
        if(i % 13 == 0)
        {
            vector<char> test = {'A', symbol};
            deck.push_back(test);
        }
        else if(i % 13 == 10)
        {
            deck.push_back("J" + symbol);
        }
        else if(i % 13 == 11)
        {
            deck.push_back("Q" + symbol);
        }
        else if(i % 13 == 12)
        {
            deck.push_back("K" + symbol);
        }
        else
        {
        deck.push_back(to_string(i % 13 + 1) + symbol);
        }
    }
    shuffle(deck);
    for(int i = 0; i < 52; i++)
    {
        cout << deck[i] << " ";
    }
    cout << endl;

    cout << "Welcome to the Casino!" << endl;
    int choice;
    while(choice != 0){

        cout << "What game would you like to play?" << endl;
        cout << "1. Poker" << endl;
        cout << "2. Blackjack" << endl;
        cout << "0. Exit" << endl;

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

    return 0;
}