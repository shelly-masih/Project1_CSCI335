// Shelly Masih
// CSCI 335

#include "Hand.hpp"

Hand::Hand() { // Construct a new Hand object
}

Hand::~Hand() { // Destroy the Hand object
  cards_.clear();
}

Hand::Hand(const Hand &other) { // Copy Constructor
  cards_ = other.cards_;
}

Hand &Hand::operator=(const Hand &other) {
  if (this != &other) {
    cards_ = other.cards_;
  }
  return *this;
}

Hand::Hand(Hand &&other) { // move constructor
  cards_ = std::move(other.cards_);
}

Hand &Hand::operator=(Hand &&other) {
  if (this != &other) { // Check for self-assignment
    // Move the contents of other.cards_ to this->cards_
    cards_ = std::move(other.cards_);
  }
  return *this;
}

const std::deque<PointCard> &Hand::getCards() const { return cards_; }

void Hand::addCard(PointCard &&card) { cards_.push_back(std::move(card)); }

bool Hand::isEmpty() const { return cards_.empty(); }

void Hand::Reverse() {
  std::deque<PointCard> reversedCards;
  for (auto it = cards_.rbegin(); it != cards_.rend(); ++it) {
    reversedCards.push_back(std::move(*it));
  }
  cards_ = std::move(reversedCards);
}

int Hand::PlayCard() {
  if (isEmpty()) {
    throw std::logic_error("The hand is empty.");
  }

  PointCard card = std::move(cards_.front());
  cards_.pop_front();

  if (!card.isPlayable()) {
    // If the card is not playable, do not add its points
    return 0;
  }

  return std::stoi(card.getInstruction());
}