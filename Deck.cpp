// Shelly Masih
// CSCI 335

#include "Deck.hpp"
#include <random>

template <typename CardType>
Deck<CardType>::Deck() { // Construct a new Deck object
}

template <typename CardType>
Deck<CardType>::~Deck() { // Destroy the Deck object
  cards_.clear();
}

template <typename CardType>
void Deck<CardType>::AddCard(const CardType &card) {
  cards_.push_back(card);
}

template <typename CardType> CardType &&Deck<CardType>::Draw() {
  if (cards_.empty()) {
    throw std::out_of_range("Deck is empty, cannot draw a card.");
  }

  // Get the last card from the deck
  CardType &&card = std::move(cards_.back());

  // Remove the last card from the deck
  cards_.pop_back();

  // Return the card as a right-hand value
  return std::move(card);
}

template <typename CardType> bool Deck<CardType>::IsEmpty() const {
  return cards_.empty();
}

template <typename CardType> void Deck<CardType>::Shuffle() {
  // Create a random number generator with a fixed seed (2028358904)
  std::mt19937 rng(2028358904);

  // Shuffle the cards using the random number generator
  std::shuffle(cards_.begin(), cards_.end(), rng);
}

template <typename CardType> int Deck<CardType>::getSize() const {
  return cards_.size();
}

template <typename CardType>
std::vector<CardType> Deck<CardType>::getDeck() const {
  return cards_;
}
