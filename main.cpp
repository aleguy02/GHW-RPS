#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

std::string getEnemyMove()
{
    // initialize random seed based on time
    srand(time(nullptr));

    // generate psuedo-random number
    int num = rand() % 3;

    if (num == 0) {
        return "Rock";
    }
    if (num == 1) {
        return "Paper";
    }
    return "Scissors";
}

int checkWin(const std::string& player_move, const std::string& enemy_move)
{
    // early return. ICBM = automatic win
    if (player_move == "Intercontinental Ballistic Missile") {
        std::cout <<
            "The sky ignites with a searing flash, brighter than the sun, "
            "as the intercontinental ballistic missile reaches its grim destination. "
            "A deafening roar follows, shattering the heavens, and in an instant, "
            "the heart of the city becomes a cauldron of fire and fury."
        << "\n\n" <<
            "Shockwaves tear through the land, reducing steel and concrete to ash, "
            "while the earth itself trembles in anguish."
        << "\n\n" <<
            "Where life once thrives, there is now a void of charred ruin, cloaked "
            "in a suffocating shroud of radioactive dust. Silence reigns in the aftermath, "
            "broken only by the faint crackle of distant flames and the mournful cries of "
            "wind over desolation. The air carries the acrid stench of devastation—a harbinger "
            "of humanity's most horrifying triumph over itself. Rock, paper, scissors; all "
            "return to dust under the might of the ICBM"
        << std::endl;
        return 1;
    }

    // Player wins
    if (enemy_move == "Rock" && player_move == "Paper") {
        return 1;
    }
    if (enemy_move == "Paper" && player_move == "Scissors") {
        return 1;
    }
    if (enemy_move == "Scissors" && player_move == "Rock") {
        return 1;
    }

    // Enemy wins
    if (enemy_move == "Paper" && player_move == "Rock") {
        return -1;
    }
    if (enemy_move == "Scissors" && player_move == "Paper") {
        return -1;
    }
    if (enemy_move == "Rock" && player_move == "Scissors") {
        return -1;
    }

    return 0;
}
int main()
{
    std::string player_move;

    // Introduce player to game
    std::cout << "Welcome to Rock, Paper, Intercontinental Ballistic Missile, Scissors!" << std::endl;

    // Get player move
    std::cout << "What will you play? (capitalize the first letter of each word)" << std::endl;
    while (true) {
        std::getline(std::cin, player_move);
        if (
            player_move == "Rock" ||
            player_move == "Paper" ||
            player_move == "Intercontinental Ballistic Missile" ||
            player_move == "Scissors"
            )
            {
                break;
            }

        std::cout << "Choice invalid, please try again." << std::endl;
    }

    // Get enemy move
    std::string enemy_move = getEnemyMove();

    int win = checkWin(player_move, enemy_move);

    std::cout << "You played: " << player_move << std::endl;
    std::cout << "Enemy played: " << enemy_move << std::endl;
    if (win == 1) {
        std::cout << "You win!" << std::endl;
    }
    if (win == -1) {
        std::cout << "You lose!" << std::endl;
    }
    if (win == 0) {
        std::cout << "Tie!" << std::endl;
    }

    return 0;
}
