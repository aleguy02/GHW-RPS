#include <iostream>

bool checkWin(const std::string& input)
{
    // early return. ICBM = automatic win
    if (input == "Intercontinental Ballistic Missile") {
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
            "of humanity's most horrifying triumph over itself."
        << std::endl;
        return true;
    }

}
int main()
{
    std::string input;

    // Introduce player to game
    std::cout << "Welcome to Rock, Paper, Intercontinental Ballistic Missile, Scissors!" << std::endl;

    // Get user input
    std::cout << "What will you play? (capitalize the first letter of each word)" << std::endl;
    while (true) {
        std::getline(std::cin, input);
        if (input == "Rock" || input == "Paper" || input == "Intercontinental Ballistic Missile" || input == "Scissors") {
            break;
        }

        std::cout << "Choice invalid, please try again." << std::endl;
    }

    bool win = checkWin(input);

    if (win) {
        std::cout << "You win!" << std::endl;
    } else {
        std::cout << "You lose!" << std::endl;
    }

    return 0;
}
