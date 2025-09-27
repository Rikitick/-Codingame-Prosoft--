#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;



int main()
{
    map<char, int> masti = {
        {'2', 2},
        {'3', 3},
        {'4', 4},
        {'5', 5},
        {'6', 6},
        {'7', 7},
        {'8', 8},
        {'9', 9},
        {'1', 10},
        {'J', 11},
        {'Q', 12},
        {'K', 13},
        {'A', 14},
        {'D', 1},
        {'H', 2},
        {'C', 3},
        {'S', 4},
    };
    queue<string> player1;
    int n; 
    cin >> n; cin.ignore();
    for (int i = 0; i < n; i++) {
        string cardp_1; 
        cin >> cardp_1; cin.ignore();
        player1.push(cardp_1);
    }
    queue<string> player2;
    int m; 
    cin >> m; cin.ignore();
    for (int i = 0; i < m; i++) {
        string cardp_2; 
        cin >> cardp_2; cin.ignore();
        player2.push(cardp_2);
    }

    int cnt = 0;
    queue<string> player1_cards_in_game;
    queue<string> player2_cards_in_game;

    while (1) {
        if (player1.size() == 0) {
            cout << "2 " << cnt << endl;
            break;
        }
        if (player2.size() == 0) {
            cout << "1 " << cnt << endl;
            break;
        }
        
        string player1_card = player1.front();
        player1.pop();
        string player2_card = player2.front();
        player2.pop();

        player1_cards_in_game.push(player1_card);
        player2_cards_in_game.push(player2_card);

        if (masti[player1_card.front()] > masti[player2_card.front()]) {
            while (player1_cards_in_game.size() > 0) {
                string card = player1_cards_in_game.front();
                player1_cards_in_game.pop();
                player1.push(card);
            }
            while (player2_cards_in_game.size() > 0) {
                string card = player2_cards_in_game.front();
                player2_cards_in_game.pop();
                player1.push(card);
            }
            cnt++;
        }
        else if (masti[player1_card.front()] < masti[player2_card.front()]) {
            while (player1_cards_in_game.size() > 0) {
                string card = player1_cards_in_game.front();
                player1_cards_in_game.pop();
                player2.push(card);
            }
            while (player2_cards_in_game.size() > 0) {
                string card = player2_cards_in_game.front();
                player2_cards_in_game.pop();
                player2.push(card);
            }
            cnt++;
        }
        else {
            if (player1.size() <= 3 || player2.size() <= 3) {
                cout << "PAT" << endl;
                break;
            }

            for (int i = 0; i < 3; ++i) {
                string card = player1.front();
                player1.pop();
                player1_cards_in_game.push(card);
            }
            for (int i = 0; i < 3; ++i) {
                string card = player2.front();
                player2.pop();
                player2_cards_in_game.push(card);
            }
        }
    }

    return 0;
}
