// Shelly Masih
// CSCI 335

#include "Card.hpp"

Card::~Card() {  // destroy the Card object
  if (bitmap_) {
    delete[] bitmap_;
  }
}

Card::Card(const Card &rhs) { // copy constructor
  cardType_ = rhs.cardType_;
  instruction_ = rhs.instruction_;

  if (rhs.bitmap_) {
    bitmap_ = new int[80]; 
    for (int i = 0; i < 80; i++) {
      bitmap_[i] = rhs.bitmap_[i];
    }
  } else {
    bitmap_ = nullptr;
  }
  drawn_ = rhs.drawn_;
}

Card &Card::operator=(const Card &rhs) { // copy assignment
  if (this != &rhs) {
    delete[] bitmap_;

    cardType_ = rhs.cardType_;
    instruction_ = rhs.instruction_;

    if (rhs.bitmap_) {
      bitmap_ = new int[80]; 
      for (int i = 0; i < 80; i++) {
        bitmap_[i] = rhs.bitmap_[i];
      }
    } else {
      bitmap_ = nullptr;
    }

    drawn_ = rhs.drawn_;
  }
  return *this;
}

Card::Card(Card &&rhs) {  // move constructor
  cardType_ = rhs.cardType_;
  instruction_ = std::move(rhs.instruction_);
  drawn_ = rhs.drawn_;

  if (rhs.bitmap_) {
    bitmap_ = new int[80]; 
    for (int i = 0; i < 80; i++) {
      bitmap_[i] = rhs.bitmap_[i];
    }
  } else {
    bitmap_ = nullptr;
  }

  rhs.cardType_ = POINT_CARD;
  rhs.instruction_ = "";
  rhs.bitmap_ = nullptr;
  rhs.drawn_ = false;
}

Card &Card::operator=(Card &&rhs) {  // move assignment
  if (this != &rhs) {
    delete[] bitmap_;

    cardType_ = rhs.cardType_;
    instruction_ = std::move(rhs.instruction_);
    drawn_ = rhs.drawn_;

    if (rhs.bitmap_) {
      bitmap_ = new int[80]; 
      for (int i = 0; i < 80; i++) {
        bitmap_[i] = rhs.bitmap_[i];
      }
    } else {
      bitmap_ = nullptr;
    }

    rhs.cardType_ = POINT_CARD;
    rhs.instruction_ = "";
    rhs.bitmap_ = nullptr;
    rhs.drawn_ = false;
  }
  return *this;
}

Card::Card() { // default constructor
}

std::string Card::getType() const { // return the string of card type
  if (cardType_ == POINT_CARD) {
    return "POINT_CARD";
  } else {
    return "ACTION_CARD";
  }
}

void Card::setType(const CardType &type) { // set card type
  cardType_ = type;
}

const std::string &Card::getInstruction() const { // return the instruction
  return instruction_; 
}

void Card::setInstruction(const std::string &instruction) { // set instruction
  instruction_ = instruction;
}

const int *Card::getImageData() const { // return the image data
  return bitmap_; 
}

void Card::setImageData(int *data) { // set the image data
  if (data) {
    bitmap_ = new int[80];

    for (int i = 0; i < 80; i++) {
      bitmap_[i] = data[i];
    }
  } else {
    bitmap_ = nullptr;
  }
}

bool Card::getDrawn() const { // return drawn status
  return drawn_; 
}

void Card::setDrawn(const bool &drawn) { // set the drawn status
  drawn_ = drawn; 
}
