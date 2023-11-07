

#include "Player.hpp"

Player::Player() {
  score_ = 0;
  opponent_ = nullptr;
  actiondeck_ = nullptr;
  pointdeck_ = nullptr;
}

Player::~Player() {
  delete actiondeck_;
  delete pointdeck_;
  actiondeck_ = nullptr;
  pointdeck_ = nullptr;
}

const Hand &Player::getHand() const { return hand_; }

void Player::setHand(const Hand &hand) { hand_ = hand; }

int Player::getScore() const { return score_; }

void Player::setScore(const int &score) { score_ = score; }

void Player::play(ActionCard &&card) {
  /**
   * @post: Play a given action card
   * @param: an Actioncard object
   * Begin the function by reporting the instruction of the card:
   * PLAYING ACTION CARD: [instruction]
   */
  std::cout << "PLAYING ACTION CARD: " << card.getInstruction()
            << std::endl; // reporting instruction of the card
}

void Player::drawPointCard() {
  if (pointdeck_ != nullptr) {
    PointCard card = pointdeck_->Draw();
    hand_.addCard(std::move(card));
  }
}

void Player::playPointCard() {
  /**
   * @post: Play a point card from the player’s hand and update the player’
  s score */
  if (!hand_.isEmpty()) {
    int points = hand_.PlayCard();
    score_ += points;
  }
}

void Player::setOpponent(Player *opponent) { opponent_ = opponent; }

Player *Player::getOpponent() { return opponent_; }

void Player::setActionDeck(Deck<ActionCard> *actiondeck) {
  actiondeck_ = actiondeck;
}

Deck<ActionCard> *Player::getActionDeck() { return actiondeck_; }

void Player::setPointDeck(Deck<PointCard> *pointdeck) {
  pointdeck_ = pointdeck;
}

Deck<PointCard> *Player::getPointDeck() { return pointdeck_; }
