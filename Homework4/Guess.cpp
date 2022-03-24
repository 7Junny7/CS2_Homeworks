#include <iostream>
using namespace std;

const int MAXGUESS = 1000;  // range is [0,MAXGUESS]

// Polymorphic classes

class Player {
public:
    virtual int getGuess() = 0;
    virtual void giveFeedback(int guess, bool feedback) {};
};

class HumanPlayer : public Player {
public:
    int getGuess(){
        int guess;
        cout<<"Guess a number: ";
        cin>>guess;
        return guess;
    }
};

class ComputerPlayer : public Player {
public:
    int getGuess(){
        int guess = rand() % MAXGUESS + 1;
        cout<<"The Computer's guess is "<<guess<<endl;
        return guess;
    }
};


class SmartComputerPlayer : public ComputerPlayer {
public:
    int getGuess(){
        int temp;
        if (guess_Min == 0 && guess_Max == MAXGUESS){
            temp = 500;
        }else if (feedback_I == true){
            temp = ((guess_Max - guess_Min) / 2) + guess_Min;
        }else{
            temp = (guess_Min + guess_Max) / 2;
        }
        cout<<"The Computer's guess is "<<temp<<endl;
        return temp;

    }
    void giveFeedback(int guess, bool feedback){
        if (feedback){
            guess_Max = guess;
        }else{
            guess_Min = guess;
        }
        feedback_I = feedback;
    }
private:
    int guess_Min = 0;
    int guess_Max = MAXGUESS;
    bool feedback_I;
};


// You can change this however you want
bool checkForWin (int guess, int answer, bool &feedback) {
    if (answer == guess) {
        cout << "You're right! You win!" << endl;
        return true;
    }
    else if (answer < guess) {
        cout << "Your guess is too high." << endl;
        feedback = true;
    }
    else {
        cout << "Your guess is too low." << endl;
        feedback = false;
    }
    return  false;
}



int play(Player &player1, Player &player2) {  // do not change this line
    // change anything you like below this line
    int answer = 0, guess = 0;
    int numGuesses = 0;
    int round = 0;
    srand(time(0));
    answer = rand() % MAXGUESS + 1;
    bool win = false;
    bool feedback = true;

    while (!win) {
        round++;
        cout<<"******* - Round "<<round<<" - *******"<<endl;
        cout << "Player 1's turn to guess." << endl;
        guess = player1.getGuess();
        numGuesses++;
        win = checkForWin(guess, answer, feedback);
        player1.giveFeedback(guess, feedback);
        if (win) break;

        cout << "\nPlayer 2's turn to guess." << endl;
        guess = player2.getGuess();
        numGuesses++;
        win = checkForWin(guess, answer, feedback);
        player2.giveFeedback(guess, feedback);
    }
    return numGuesses;
}

int checkPlayer (int num){
    bool flag = true;
    cout << "Please make a selection for Player " << num << endl;
    cout << "1. Human Player" << endl;
    cout << "2. Computer Player" << endl;
    cout << "3. Smart Computer Player" << endl;
    cout << "---------------------------" << endl;
    while (flag) {
        cout << "Please enter a number between 1 and 4: ";
        try {
            char temp_char;
            cin >> temp_char;
            if (!isdigit(temp_char)) {
                throw temp_char;
            } else {
                int temp_int = static_cast<int>(temp_char) - 48;
                if (temp_int < 0 || temp_int > 3) {
                    throw temp_int;
                } else {
                    flag = false;
                    return temp_int;
                }
            }
        } catch (int num) {
            cout << "Error! The number you entered was out of range!" << endl;
            flag = true;
        } catch (char chr) {
            cout << "Error! Please enter a number between 1 and 3" << endl;
            flag = true;
        }
    }
}

Player* madePlayer(int num){
    if (num == 1){
        HumanPlayer *temp = new HumanPlayer;
        return temp;
    }else if (num == 2){
        ComputerPlayer *temp = new ComputerPlayer;
        return temp;
    }else if (num == 3){
        SmartComputerPlayer *temp = new SmartComputerPlayer;
        return temp;
    }
}

int main () {

    // TODO: your code goes here
    int player1 = checkPlayer(1);
    Player *Player1 = madePlayer(player1);

    int player2 = checkPlayer(2);
    Player *Player2 = madePlayer(player2);

    int result = play(*Player1, *Player2);
    cout<<"This game took "<<result<<" guesses to finish"<<endl;
}
