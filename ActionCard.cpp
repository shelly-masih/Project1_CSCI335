// Shelly Masih
// CSCI 335

#include "ActionCard.hpp"
#include <iostream>

ActionCard::ActionCard() {
  setType(ACTION_CARD);
  setInstruction("");
  setImageData(nullptr);
  setDrawn(false);
}

bool ActionCard::isPlayable() {
  bool drawn = getDrawn();
  if (drawn == false) {
    return false;
  }

  const std::string &instruction = getInstruction();

  std::regex drawRegex("DRAW (\\d+) CARD(S)?");
  std::regex playRegex("PLAY (\\d+) CARD(S)?");
  std::regex reverseRegex("REVERSE HAND");
  std::regex sRegex("S");

  if (std::regex_match(instruction, drawRegex) ||
      std::regex_match(instruction, playRegex) ||
      std::regex_match(instruction, reverseRegex) ||
      std::regex_match(instruction, sRegex)) {
    return true;
  }

  return false;
}

void ActionCard::Print() const {
  std::cout << "Type: " << getType() << std::endl;
  std::cout << "Instruction: " << getInstruction() << std::endl;

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