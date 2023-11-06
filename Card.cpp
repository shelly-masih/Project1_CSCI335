// Shelly Masih
// CSCI 335

#include "Card.hpp"

Card::~Card() {
  // Deleting allocated memory only if it's not a nullptr
  if (bitmap_) {
    delete[] bitmap_;
  }
}

// copy
Card::Card(const Card &rhs) {
  cardType_ = rhs.cardType_;
  instruction_ = rhs.instruction_;

  if (rhs.bitmap_) {
    bitmap_ = new int[80]; // Replace 80 with the actual size of your bitmap
    for (int i = 0; i < 80; i++) {
      bitmap_[i] = rhs.bitmap_[i];
    }
  } else {
    bitmap_ = nullptr;
  }
  drawn_ = rhs.drawn_;
}

Card &Card::operator=(const Card &rhs) {
  if (this != &rhs) {
    delete[] bitmap_;

    cardType_ = rhs.cardType_;
    instruction_ = rhs.instruction_;

    // Create a deep copy of the bitmap data
    if (rhs.bitmap_) {
      bitmap_ = new int[80]; // Replace SIZE with the actual size of your bitmap
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

Card::Card(Card &&rhs) {
  cardType_ = rhs.cardType_;
  instruction_ = std::move(rhs.instruction_);
  drawn_ = rhs.drawn_;

  // Perform a deep copy of the bitmap data
  if (rhs.bitmap_) {
    bitmap_ = new int[80]; // Replace 80 with the actual size of your bitmap
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

Card &Card::operator=(Card &&rhs) {
  if (this != &rhs) {
    // Release the current object's resources
    delete[] bitmap_;

    // Copy the values from the source object
    cardType_ = rhs.cardType_;
    instruction_ = std::move(rhs.instruction_);
    drawn_ = rhs.drawn_;

    // Perform a deep copy of the bitmap data
    if (rhs.bitmap_) {
      bitmap_ = new int[80]; // Replace 80 with the actual size of your bitmap
      for (int i = 0; i < 80; i++) {
        bitmap_[i] = rhs.bitmap_[i];
      }
    } else {
      bitmap_ = nullptr;
    }

    // Reset the source object to a valid state
    rhs.cardType_ = POINT_CARD;
    rhs.instruction_ = "";
    rhs.bitmap_ = nullptr;
    rhs.drawn_ = false;
  }
  return *this;
}

Card::Card() { // default constructor
}

std::string Card::getType() const { // return string of card type
  if (cardType_ == POINT_CARD) {
    return "POINT_CARD";
  } else {
    return "ACTION_CARD";
  }
}

void Card::setType(const CardType &type) { // set card type
  cardType_ = type;
}

const std::string &Card::getInstruction() const { return instruction_; }

void Card::setInstruction(const std::string &instruction) {
  instruction_ = instruction;
}

const int *Card::getImageData() const { return bitmap_; }

void Card::setImageData(int *data) {
  if (data) {
    // Allocate memory for bitmap_ with the same size as data
    bitmap_ = new int[80];

    for (int i = 0; i < 80; i++) {
      bitmap_[i] = data[i];
    }
  } else {
    bitmap_ = nullptr;
  }
}

bool Card::getDrawn() const { return drawn_; }

void Card::setDrawn(const bool &drawn) { drawn_ = drawn; }
