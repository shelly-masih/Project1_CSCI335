#include "Card.hpp"
#include "ActionCard.hpp"
#include "PointCard.hpp"

int main() {

    std::string type = "Action";
    std::string text = "Draw 4 cards";
    // Create a Card object
    ActionCard MyCard(type, text); // This is allowed because ActionCard is a concrete class

    return 0;
}
