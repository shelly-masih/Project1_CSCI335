// Shelly Masih
// CSCI 335

#include "PointCard.hpp"

PointCard::PointCard() { // construct a new point card object 
  setType(POINT_CARD);
  setInstruction("0");   
  setImageData(nullptr); 
  setDrawn(false);
}

bool PointCard::isPlayable() { // return true if card is playable
  bool drawn = getDrawn();
  const std::string &instruction = getInstruction();

  bool is_number = true; 

  for (char x : instruction) {
    if (!std::isdigit(x)) {
        is_number = false;
      break;
    }
  }

  if (drawn && is_number) {
    int points = std::stoi(instruction);
    return (points >= 0);
  }

  return false;
}

void PointCard::Print() const { // print point card information 
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