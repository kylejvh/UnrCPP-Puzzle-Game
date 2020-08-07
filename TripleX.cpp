
// Int = integer. Whole number with no decimal places.
// int main will return an integer to the OS, it is the enter point of a c++ program
// every C++ program must contain int main()
// returning 0 will tell the OS the program has ran successfully
// any other value will result in an error.

// Compiler will ignore whitespace

// Prepocessor directive - includes libraries before compiling - written at start of file with #

// DOES NOT need a semicolon
#include <iostream>
#include <ctime>

// Rename this Puzzle-introduction-game.exe and send to anthony
void PrintIntroduction(int Difficulty)
{
    if (Difficulty == 1)
    {
        std::cout << "\n\nA pig wizard waddles from the shadows and offers to teach you his magic if you solve his puzzles.\n";
        std::cout << "You need to enter the correct numbers or he will waddle back to his dark world of magic.\n\n";
        std::cout << R"(
                                             )\   /|
                                          .-/'-|_/ |
                       __            __,-' (   / \/          
                   .-'"  "'-..__,-'""          -o.`-._   
                  /                                   '/
          *--._ ./                                 _.-- 
                |                              _.-' 
                :                           .-/   
                 \                       )_ /
                  \                _)   / \(
                    `.   /-.___.---'(  /   \\
                     (  /   \\       \(     L\
                      \(     L\       \\
                       \\              \\
                        L\              L\
        )" << std::endl;
    }
    else
    {
        std::cout << "\n\nThe pig wizard's face looks annoyed as you move to level "
                  << Difficulty << " of his puzzle.\n\n";
    }
}

// Void - means this function will return NO data
bool PlayGame(int Difficulty)
{
    PrintIntroduction(Difficulty);

    // Scale number range with difficulty, add one to avoid zeros
    int CodeA = rand() % Difficulty + Difficulty;
    int CodeB = rand() % Difficulty + Difficulty;
    int CodeC = rand() % Difficulty + Difficulty;

    int CodeSum = CodeA + CodeB + CodeC;
    int CodeProduct = CodeA * CodeB * CodeC;

    std::cout << "There are 3 numbers in the code.";
    std::cout << "\nThe numbers add up to: " << CodeSum;
    std::cout << "\nThe numbers multiplied equal: " << CodeProduct << std::endl
              << std::endl;

    // Store player guesses
    int GuessA, GuessB, GuessC;

    // cin = Character Input
    // >> = Extraction Operator - will take user input and perform operation
    // In this case, the user input will be extracted and stored into variable PlayerGuess
    // These will only extract numbers up until they find a space
    // So 1 2 3 will work, or pressing enter after each entry also works
    std::cin >> GuessA >> GuessB >> GuessC;

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    // Check if player's guess is correct
    if (GuessSum == CodeSum && GuessProduct == CodeProduct)
    {
        std::cout << "\nCorrect! The pig wizard grunts in approval. You're one step closer...";
        return true;
    }
    else
    {
        std::cout << "\nWrong! The pig wizard squeals and starts to casts a spell, but on a last second whim, decides to give you another chance...\n";
        return false;
    }
}

// Prints our game messages to the console and sets up integer values
int main()
{
    srand(time(NULL)); // create a new random sequence based on time of day

    int LevelDifficulty = 1;
    const int MaxDifficulty = 5;

    while (LevelDifficulty <= MaxDifficulty) // Loop game until all levels are completed.
    {
        // Initialize BLevelComplete with result of PlayGame()
        bool bLevelComplete = PlayGame(LevelDifficulty);
        std::cin.clear();  // Clears any errors
        std::cin.ignore(); // Discards the buffer - clears input buffer to handle if anything is left over

        if (bLevelComplete)
        {
            ++LevelDifficulty;
        }
    }

    std::cout << "You've solved the piggy wizard's puzzle! Impossible! His secrets he must now share!";
    return 0;
}
