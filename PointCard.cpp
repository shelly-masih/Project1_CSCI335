#include "PointCard.hpp"

PointCard::PointCard() {
  setType(POINT_CARD);
  setInstruction("0");   // Initialize points to 0
  setImageData(nullptr); // No image data for a PointCard
  setDrawn(false);
}

bool PointCard::isPlayable() {
  bool drawn = getDrawn();
  const std::string &instruction = getInstruction();

  bool isNumeric = true; // Assume the instruction is numeric

  for (char c : instruction) {
    if (!std::isdigit(c)) {
      isNumeric = false;
      break;
    }
  }

  if (drawn && isNumeric) {
    int points = std::stoi(instruction);
    return (points >= 0);
  }

  return false;
}

void PointCard::Print() const {
  std::cout << "Type: " << getType() << std::endl;
  std::cout << "Points: " << getInstruction() << std::endl;

  const int *imgData = getImageData();
  std::cout << "Card:" << std::endl;
  if (imgData) {
    for (int i = 0; i < 80; i++) {
      std::cout << imgData[i] << " ";
    }
    std::cout << std::endl;
  } else {
    std::cout << "No image data" << std::endl;
  }
}