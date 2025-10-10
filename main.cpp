#include <iostream>
#include <cstdlib>
#include <ctime>
#include "hangman.h"
#include <fstream>

using namespace std;
/*
// Test Reun pick 1000 times
int main()
{
    srand(time(0)); // seed the RNG

    string words[MAX_WORDS];
    int wordCount = 0;

    loadDictionary(words, wordCount);

    if (wordCount == 0)
    {
        cout << "No words loaded. Exiting." << endl;
        return 1;
    }

    const int TEST_RUNS = 1000;
    int freq[MAX_WORDS] = { 0 };

    for (int i = 0; i < TEST_RUNS; ++i)
    {
        string picked = pickWord(words, wordCount);
        for (int j = 0; j < wordCount; ++j)
        {
            if (words[j] == picked)
            {
                freq[j]++;
                break;
            }
        }
    }

    cout << "Word selection frequency after " << TEST_RUNS << " runs:\n";
    for (int i = 0; i < wordCount; ++i)
    {
        cout << words[i] << ": " << freq[i] << endl;
    }

    return 0;
}
*/

/*
//Test Word Duplicate
int main()
{
    string words[MAX_WORDS];
    int wordCount = 0;

    loadDictionary(words, wordCount);

    if (wordCount == 0)
    {
        cout << "No words loaded from word_1.txt or word_2.txt. Exiting." << endl;
        return 1;
    }

    cout << "Words loaded from word_1.txt and word_2.txt:\n";
    for (int i = 0; i < wordCount; ++i)
    {
        cout << words[i] << endl;
    }

    return 0;
}
*/



int main()
{
    srand(time(0));
    startGameLog();

    string words[MAX_WORDS];
    int wordCount = 0;

    loadDictionary(words, wordCount);
    
    if (wordCount == 0)
    {
        cout << "No words loaded. Exiting." << endl;
        return 1;
    }

    string word = pickWord(words, wordCount);

    ofstream logFile("game_log.txt", ios::app);
    logFile << "The word was: " << word << endl << endl;
    logFile.close();

    char guessedLetters[30];
    int guessedCount = 0;

    char incorrectGuesses[MAX_GUESSES];
    int wrongCount = 0;
    int correctCount = 0;
    
    while (wrongCount < MAX_GUESSES)
    {
        displayBoard(word, guessedLetters, guessedCount, incorrectGuesses, wrongCount);
        drawHangman(wrongCount);
        cout << "Remaining incorrect guesses: " << (MAX_GUESSES - wrongCount) << endl;

        char guess;
        guessLetter(guess);
       
        bool correct = updateGuesses(guess, word, guessedLetters, guessedCount, incorrectGuesses, wrongCount);
        logMove(guess, correct);

        if (correct)
        {
            cout << "Correct guess!" << endl;
            correctCount++;
        }
        else
        {
            cout << "Wrong guess." << endl;
        }


        if (isWordGuessed(word, guessedLetters, guessedCount))
        {
            cout << "\033[32m"; // GREEN
            cout << "\nCongratulations! You guessed the word: " << word << endl;
            cout << "Game Won! Total incorrect guesses: " << wrongCount
                << " | Correct guesses: " << correctCount << endl;
            cout << "\033[0m";  // RESET
            logResult(true, word, wrongCount, correctCount);
            break;
        }
    }

    if (wrongCount >= MAX_GUESSES)
    {
        cout << "\n\033[31m"; // RED
        drawHangman(wrongCount);

        cout << "\033[0m";  // RESET

        cout << "\nThe correct word was: ";

        cout << "\033[32m"; // GREEN

        cout << word << endl;

        cout << "\033[0m";  // RESET

        cout << "\n\033[31m"; // RED

        cout << "Game Lost! Total incorrect guesses: " << wrongCount
            << " | Correct guesses: " << correctCount << endl;
        logResult(false, word, wrongCount, correctCount);

        cout << "\033[0m";  // RESET
    }


    return 0;
}
