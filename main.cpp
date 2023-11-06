#include "ActionCard.hpp"
#include "Card.hpp"

int main() {
  // Create a Card object
  ActionCard actionCard1;
  ActionCard actionCard2;

  int bitmap1[80];
  for (int i = 0; i < 80; i++) {
    bitmap1[i] = i * 10; // Filling the array with sample data
  }

  int bitmap2[80];
  for (int i = 0; i < 80; i++) {
    bitmap2[i] = i * 20; // Filling the array with sample data
  }

  actionCard1.setDrawn(true);
  actionCard1.setInstruction("DRAW 3 CARDS");
  actionCard1.setImageData(bitmap1);

  actionCard2.setDrawn(true);
  actionCard2.setInstruction("DRAW 2 CARDS"); // Set different instructions
  actionCard2.setImageData(bitmap2);          // Set a different bitmap for
  //  actionCard2

  std::cout << "Source Card 1:" << std::endl;
  actionCard1.Print();

  std::cout << "Source Card 2:" << std::endl;
  actionCard2.Print();

  // std::cout << actionCard1.isPlayable() << std::endl;
  // std::cout << actionCard2.isPlayable() << std::endl;

  return 0;
}