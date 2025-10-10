# Hangman
A command-line Hangman game built in C++ for RIT's CPET-121 course. This project reinforces modular design, unit testing, and file I/O by guiding students through the development of a fully interactive word-guessing game

🧩 Features
- Modular Codebase: Functions like loadDictionary(), chooseRandomWord(), displayProgress(), getPlayerGuess(), and saveResult() keep the code clean and maintainable.
- File I/O: Reads words from dictionary.txt, removes duplicates, and logs game results to output.txt.
- Random Word Selection: Ensures fair play with equal probability for each word.
- Game Loop: Tracks guesses, displays progress, and handles win/loss conditions.
- Unit Testing: Includes test cases for dictionary loading, word selection, progress display, input validation, and result saving.
- User-Friendly Interface: Clear prompts, progress updates, and error handling for invalid inputs.

🧪 Testing Highlights
- ✅ Dictionary loading with empty, unique, and duplicate entries
- 🎲 Random selection fairness over 1000 iterations
- 🔍 Progress display with partial and full guesses
- 🛡️ Input validation for repeated and invalid characters
- 📝 Output logging for both win and loss scenarios

📁 File Structure
├── Hangman.h           # Header file declaring game functions and structures

├── hangman.cpp         # Main game logic: word selection, progress tracking, input handling
├── main.cpp            # Entry point that initializes and runs the game loop
├── word1.txt           # First dictionary file containing word list
├── word2.txt           # Second dictionary file containing word list
├── output.txt          # Game results log (generated after each round)


👥 Team Guidelines
- Max 2 students per team (new partner required from Project 3)
- Solo work allowed but not recommended
- Peer testing encouraged


🛠️ Technologies
- C++
- Standard Library
- File Streams
- Randomization
- Manual Unit Testing

