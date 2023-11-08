// Shelly Masih
// CSCI 335

#include "ActionCard.hpp"
#include <iostream>

ActionCard::ActionCard() { // construct new action card object
  setType(ACTION_CARD);
  setInstruction("");
  setImageData(nullptr);
  setDrawn(false);
}

bool ActionCard::isPlayable() { // return true if action card is playable
  bool drawn = getDrawn();
  if (drawn == false) {
    return false;
  }

  const std::string &instruction = getInstruction();

  std::regex drawRegex(R"(DRAW (\d+) CARD\(S\))");
  std::regex playRegex(R"(PLAY (\d+) CARD\(S\))");
  std::regex reverseRegex("REVERSE HAND");
  std::regex sRegex("SWAP HAND WITH OPPONENT");

  if (std::regex_match(instruction, drawRegex) ||
      std::regex_match(instruction, playRegex) ||
      std::regex_match(instruction, reverseRegex) ||
      std::regex_match(instruction, sRegex)) {
    return true;
  }

  return false;
}

void ActionCard::Print() const { // print action card information 
  std::cout << "Type: " << getType() << std::endl;
  std::cout << "Instruction: " << getInstruction() << std::endl;

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
