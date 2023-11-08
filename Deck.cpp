// Shelly Masih
// CSCI 335

#include "Deck.hpp"
#include <random>

template <typename CardType>
Deck<CardType>::Deck() { // construct a new Deck object
}

template <typename CardType>
Deck<CardType>::~Deck() { // destroy the Deck object
  cards_.clear();
}

template <typename CardType>
void Deck<CardType>::AddCard(const CardType &card) { // add card to deck
  cards_.push_back(card);
}

template <typename CardType> CardType &&Deck<CardType>::Draw() { // draw card from deck
  if (cards_.empty()) {
    throw std::out_of_range("Deck is empty, cannot draw a card.");
  }
  CardType &&card = std::move(cards_.back()); // get the last card from the deck
  cards_.pop_back(); // remove the last card from the deck
  return std::move(card);
}

template <typename CardType> bool Deck<CardType>::IsEmpty() const { // return if empty
  return cards_.empty();
}

template <typename CardType> void Deck<CardType>::Shuffle() {
  std::mt19937 rng(2028358904); // random number generator using std::mt19937 with seed
  std::shuffle(cards_.begin(), cards_.end(), rng);
}

template <typename CardType> int Deck<CardType>::getSize() const { // return number of cards
  return cards_.size();
}

template <typename CardType>
std::vector<CardType> Deck<CardType>::getDeck() const { //return vector of cards in deck
  return cards_;
}
