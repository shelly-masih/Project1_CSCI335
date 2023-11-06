// Shelly Masih
// CSCI 335

#include "ActionCard.hpp"
#include <iostream>

ActionCard::ActionCard() {
  setType(ACTION_CARD);
  setInstruction("");
  setImageData(nullptr); // Ensure bitmap_ is initialized to nullptr
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
  std::regex sRegex("SWAP HAND WITH OPPONENT");

  if (std::regex_match(instruction, drawRegex) ||
      std::regex_match(instruction, playRegex) ||
      std::regex_match(instruction, reverseRegex) ||
      std::regex_match(instruction, sRegex)) {
    return true;
  }

  return false;
}

void ActionCard::Print() const {
  std::string output = "Type: " + getType() + "\n";
  output += "Instruction: " + getInstruction() + "\n";

  const int *imgData = getImageData();
  if (imgData) {
    output += "Image Data: ";
    for (int i = 0; i < 80; i++) {
      output += std::to_string(imgData[i]) + " ";
    }
  } else {
    output += "No image data";
  }

  std::cout << output << std::endl;
}
