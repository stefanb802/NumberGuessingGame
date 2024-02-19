// NumberGuessingGame.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

int upper = 100;
int lower = 1;

int getDifficulty() {
    int difficultyLevel;
    cout << "Choose difficulty! (1 for easy | 2 for medium | 3 for hard)!" << endl;
    cin >> difficultyLevel;
    switch (difficultyLevel) {
    case 1:
        return 10;
    case 2:
        return 7;
    case 3:
        return 5;
    }
    return 0;
}

string generateMessage(int number, int& guesses, int randomNumber) {
    if (number == randomNumber) {
        guesses = -1;
        return "Congrats! The correct answer was "+to_string(number)+ "! You won!";
    }
    guesses--;
    string ans;
    if (number > randomNumber)
        ans="Incorrect! The correct answer is lower than "+to_string(number)+"!";
    if (number < randomNumber)
        ans =  "Incorrect! The correct answer is higher than " + to_string(number) + "!";
    ans+= " You have " +to_string( guesses )+" guesses left!";
    return ans;

}
//Comment the following section if you want to play the game for yourself
int generateAnswer(int& autoL, int& autoH, string message) {
    if (message == "First")
        return (autoL+autoH)/2;
    if (message.find("higher") != string::npos)
        autoL = (autoH + autoL) / 2+1;
    if (message.find("lower") != string::npos)
        autoH = (autoH + autoL) / 2-1;
    return (autoL + autoH) / 2;
}

int main()
{
    srand(time(0));
    int randomNumber = rand() % (upper - lower) + 1;
    int guesses=getDifficulty();
    char playOn = 'y';
    int number;
    string message;
    //Comment the following section if you want to play the game for yourself
    message= "First";
    int autoL = lower;
    int autoH = upper;
    while (guesses > 0) {
        cout << "Do you want to continue?[y/n]" << endl;
        cin >> playOn;
        while (playOn != 'y' && playOn != 'n') {
            cout << "Invalid input! Press y or n!" << endl;
            cin >> playOn;
        }
        if (playOn == 'n')
            break;
        cout << "Insert a number!" << endl;
        //cin >> number; //Uncomment if you want to play for yourself
        number = generateAnswer(autoL, autoH, message); //Comment if you want to play for yourself
        message = generateMessage(number, guesses, randomNumber);
        cout << message << endl;
        if (guesses == -1)
            return 0;
    }
    cout << "Game over! You lost!" << endl;
    return 0;

}


