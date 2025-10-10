#ifndef HANGMAN_H
#define HANGMAN_H

#include <string>
using namespace std;

const int MAX_WORDS = 200;
const int MAX_WORD_LENGTH = 30;
const int MAX_GUESSES = 7;

string toLowerCase(const string& str);
void loadDictionary(string words[], int& wordCount);
string pickWord(const string words[], int wordCount);
void displayBoard(const string& word, const char guessedLetters[], int guessedCount, const char incorrectGuesses[], int wrongCount);
void guessLetter(char& guessedLetter);
bool updateGuesses(char guessedLetter, const string& word, char guessedLetters[], int& guessedCount, char incorrectGuesses[], int& wrongCount);
void drawHangman(int wrongCount);
bool isWordGuessed(const string& word, const char guessedLetters[], int guessedCount);

// Logging functions
void startGameLog();
void logMove(char guessedLetter, bool correct);
void logResult(bool win, const string& word, int wrongAttempts, int correctAttempts);


#endif

