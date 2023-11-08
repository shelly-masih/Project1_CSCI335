// Shelly Masih
// CSCI 335

#include "Hand.hpp"

Hand::Hand() { // construct a new Hand object
}

Hand::~Hand() { // destroy the Hand object
  cards_.clear();
}

Hand::Hand(const Hand &other) { // copy Constructor
  cards_ = other.cards_;
}

Hand &Hand::operator=(const Hand &other) { // copy assignment
  if (this != &other) {
    cards_ = other.cards_;
  }
  return *this;
}

Hand::Hand(Hand &&other) { // move constructor
  cards_ = std::move(other.cards_);
}

Hand &Hand::operator=(Hand &&other) { // move assignment
  if (this != &other) { 
    cards_ = std::move(other.cards_);
  }
  return *this;
}

const std::deque<PointCard> &Hand::getCards() const { // return cards in hand
  return cards_; 
}

void Hand::addCard(PointCard &&card) { // add card to hand
  card.setDrawn(true);
  cards_.push_back(std::move(card));
}

bool Hand::isEmpty() const {  // empty card in hand
  return cards_.empty(); 
}

void Hand::Reverse() { // reverse hand 
  std::deque<PointCard> reversedCards;
  for (auto it = cards_.rbegin(); it != cards_.rend(); ++it) {
    reversedCards.push_back(std::move(*it));
  }
  cards_ = std::move(reversedCards);
}

int Hand::PlayCard() { // play card at front
  if (isEmpty()) {
    throw std::logic_error("The hand is empty.");
  }

  PointCard card = std::move(cards_.front());
  cards_.pop_front();

  if (!card.isPlayable()) {
    // If the card is not playable, no points
    return 0;
  }

  return std::stoi(card.getInstruction());
}