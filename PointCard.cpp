#include "PointCard.hpp"

PointCard::PointCard() {
  setType(POINT_CARD);
  setInstruction("");
  setImageData(nullptr);
  setDrawn(false);
}

bool PointCard::isPlayable() {
  bool drawn = getDrawn();
  std::string instruction = getInstruction();

  if (drawn) {
    try {
      int points = std::stoi(instruction);
      return true;

    } catch (const std::invalid_argument &e) {
      std::cout << "Invalid Argument: " << e.what() << std::endl;
    }
  }

  return false;
}

void PointCard::Print() const {
  std::cout << "Type: " << getType() << std::endl;
  std::cout << "Points: " << getInstruction() << std::endl;

  const int *imgData = getImageData();
  if (imgData) {
    std::cout << "Image Data: ";
    for (int i = 0; imgData[i] != 0; i++) {
      std::cout << imgData[i] << " ";
    }
    std::cout << std::endl;
  } else {
    std::cout << "Image Data: None" << std::endl;
  }
}