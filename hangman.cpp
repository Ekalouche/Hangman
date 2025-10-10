#include <iostream>
#include <fstream>
#include <cstdlib>
#include "hangman.h"

using namespace std;

string toLowerCase(const string& str)
{
    string lower = str;
    for (char& c : lower)
    {
        c = tolower(c);
    }
    return lower;
}

void loadDictionary(string words[], int& wordCount)
{
    ifstream file1("word_1.txt");
    ifstream file2("word_2.txt");
    string word;
    wordCount = 0;

    if (!file1)
    {
        cout << "Sorry, word_1.txt is missing or empty." << endl;
        return;
    }
    if (!file2)
    {
        cout << "Sorry, word_2.txt is missing or empty." << endl;
        return;
    }

    // Load from file1
    while (file1 >> word && wordCount < MAX_WORDS)
    {
        string lowerWord = toLowerCase(word);
        bool duplicate = false;

        for (int i = 0; i < wordCount; i++)
        {
            if (words[i] == lowerWord)
            {
                duplicate = true;
                break;
            }
        }

        if (!duplicate)
        {
            words[wordCount++] = lowerWord;
        }
    }

    // Load from file2
    while (file2 >> word && wordCount < MAX_WORDS)
    {
        string lowerWord = toLowerCase(word);
        bool duplicate = false;

        for (int i = 0; i < wordCount; i++)
        {
            if (words[i] == lowerWord)
            {
                duplicate = true;
                break;
            }
        }

        if (!duplicate)
        {
            words[wordCount++] = lowerWord;
        }
    }

    file1.close();
    file2.close();
}


string pickWord(const string words[], int wordCount)
{
        int index = rand() % wordCount;
        return words[index];
}

void displayBoard(const string& word, const char guessedLetters[], int guessedCount, const char incorrectGuesses[], int wrongCount)
{
    cout << endl << "Word: ";
    for (int i = 0; i < word.length(); i++)
    {
        bool found = false;
        for (int j = 0; j < guessedCount; j++)
        {
            if (word[i] == guessedLetters[j])
            {
                cout << word[i] << " ";
                found = true;
                break;
            }
        }
        if (!found)
        {
            cout << "_ ";
        }
    }
    cout << endl;

    cout << "Guessed letters: ";
    for (int i = 0; i < guessedCount; i++)
    {
        cout << guessedLetters[i] << " ";
    }
    cout << endl;

    cout << "Incorrect guesses: ";
    for (int i = 0; i < wrongCount; i++)
    {
        cout << incorrectGuesses[i] << " ";
    }
    cout << endl;
}

void guessLetter(char& guessedLetter)
{
    string input;
    bool valid = false;

    while (!valid)
    {
        cout << "Enter a letter: ";
        cin >> input;

        if (input.length() != 1)
        {
            cout << "Please enter exactly one character." << endl;
        }
        else if (!isalpha(input[0]))
        {
            cout << "Please enter a letter (A-Z only)." << endl;
        }
        else
        {
            guessedLetter = tolower(input[0]);
            valid = true;
        }
    }
}

bool updateGuesses(char guessedLetter, const string& word, char guessedLetters[], int& guessedCount, char incorrectGuesses[], int& wrongCount)
{
    for (int i = 0; i < guessedCount; i++)
    {
        if (guessedLetters[i] == guessedLetter)
        {
            cout << "You already guessed that letter." << endl;
            return false;
        }
    }

    guessedLetters[guessedCount] = guessedLetter;
    guessedCount++;

    for (int i = 0; i < word.length(); i++)
    {
        if (word[i] == guessedLetter)
        {
            return true;
        }
    }

    incorrectGuesses[wrongCount] = guessedLetter;
    wrongCount++;
    return false;
}

void drawHangman(int wrongCount)
{
    switch (wrongCount)
    {
    case 0:
        cout << "+" << endl;
        cout << "|" << endl;
        cout << "|" << endl;
        cout << "|" << endl;
        cout << "|" << endl;
        cout << "|" << endl;
        cout << "|" << endl;
        cout << "+-------" << endl;
        break;
    case 1:
        cout << "+----+" << endl;
        cout << "|" << endl;
        cout << "|" << endl;
        cout << "|" << endl;
        cout << "|" << endl;
        cout << "|" << endl;
        cout << "|" << endl;
        cout << "+-------" << endl;
        break;
    case 2:
        cout << "+----+" << endl;
        cout << "|    O" << endl;
        cout << "|" << endl;
        cout << "|" << endl;
        cout << "|" << endl;
        cout << "|" << endl;
        cout << "|" << endl;
        cout << "+-------" << endl;
        break;
    case 3:
        cout << "+----+" << endl;
        cout << "|    O" << endl;
        cout << "|    |" << endl;
        cout << "|    |" << endl;
        cout << "|" << endl;
        cout << "|" << endl;
        cout << "|" << endl;
        cout << "+-------" << endl;
        break;
    case 4:
        cout << "+----+" << endl;
        cout << "|    O" << endl;
        cout << "|   /|" << endl;
        cout << "|    |" << endl;
        cout << "|" << endl;
        cout << "|" << endl;
        cout << "|" << endl;
        cout << "+-------" << endl;
        break;
    case 5:
        cout << "+----+" << endl;
        cout << "|    O" << endl;
        cout << "|   /|\\ " << endl;
        cout << "|    |" << endl;
        cout << "|" << endl;
        cout << "|" << endl;
        cout << "|" << endl;
        cout << "+-------" << endl;
        break;
    case 6:
        cout << "+----+" << endl;
        cout << "|    O" << endl;
        cout << "|   /|\\ " << endl;
        cout << "|    |" << endl;
        cout << "|   /" << endl;
        cout << "|" << endl;
        cout << "|" << endl;
        cout << "+-------" << endl;
        break;
    case 7:
        cout << "+----+" << endl;
        cout << "|    O" << endl;
        cout << "|   /|\\ " << endl;
        cout << "|    |" << endl;
        cout << "|   / \\ " << endl;
        cout << "|" << endl;
        cout << "|" << endl;
        cout << "+-------" << endl;
        break;
    }
}

bool isWordGuessed(const string& word, const char guessedLetters[], int guessedCount)
{
    for (int i = 0; i < word.length(); i++)
    {
        bool found = false;
        for (int j = 0; j < guessedCount; j++)
        {
            if (word[i] == guessedLetters[j])
            {
                found = true;
                break;
            }
        }
        if (!found)
        {
            return false;
        }
    }
    return true;
}

void startGameLog()
{
    ofstream logFile("game_log.txt", ios::out);
    logFile << "Starting new Hangman game..." << endl;
    logFile << "Loading words from word_1.txt and word_2.txt" << endl;
    logFile << "Generating random word..." << endl;
    logFile.close();
}

void logMove(char guessedLetter, bool correct)
{
    ofstream logFile("game_log.txt", ios::app);
    logFile << "Guessed: " << guessedLetter;
    if (correct)
        logFile << " - Correct" << endl;
    else
        logFile << " - Incorrect" << endl;
    logFile.close();
}

void logResult(bool win, const string& word, int wrongAttempts, int correctAttempts)
{
    ofstream logFile("game_log.txt", ios::app);
    logFile << endl << "Game Result: " << (win ? "WIN" : "LOSS") << endl;
    logFile << "The word was: " << word << endl;
    logFile << "Incorrect guesses: " << wrongAttempts << endl;
    logFile << "Correct guesses: " << correctAttempts << endl;
    logFile.close();
}


