

#include "Player.hpp"

Player::Player() { // construct new player object 
  score_ = 0;
  actiondeck_ = new Deck<ActionCard>; 
  pointdeck_ = new Deck<PointCard>;   
}

Player::~Player() {} // destory  player object 

const Hand &Player::getHand() const { // return player hand
  return hand_; 
}

void Player::setHand(const Hand &hand) { // set players hand 
  hand_ = hand; 
}

int Player::getScore() const { // return current score
  return score_; 
}

void Player::setScore(const int &score) { // set players score 
  score_ = score; 
}

void Player::play(ActionCard &&card) {
  /**
   * @post: Play a given action card
   * @param: an Actioncard object
   * Begin the function by reporting the instruction of the card:
   * PLAYING ACTION CARD: [instruction]
   */
  std::cout << "PLAYING ACTION CARD: " << card.getInstruction() << std::endl; // reporting instruction of the card
  std::regex drawRegex(R"(DRAW (\d+) CARD\(S\))");
  std::regex playRegex(R"(PLAY (\d+) CARD\(S\))");
  std::regex reverseRegex("REVERSE HAND");
  std::regex swapRegex("SWAP HAND WITH OPPONENT");

  const std::string &instruction = card.getInstruction();

  if (std::regex_match(instruction, drawRegex)) {
    std::smatch match;
    if (std::regex_search(instruction, match, drawRegex)) {
      int num_cards_to_draw = std::stoi(match[1]);
      for (int i = 0; i < num_cards_to_draw; ++i) {
        drawPointCard();
      }
    }
  } else if (std::regex_match(instruction, playRegex)) {
    std::smatch match;
    if (std::regex_search(instruction, match, playRegex)) {
      int num_cards_to_play = std::stoi(match[1]);
      for (int i = 0; i < num_cards_to_play; ++i) {
        playPointCard();
      }
    }
  } else if (std::regex_match(instruction, reverseRegex)) {
    // reverse the player's hand
    hand_.Reverse();

  } else if (std::regex_match(instruction, swapRegex)) {
    Hand temp = this->hand_;
    this->hand_ = opponent_->hand_;
    opponent_->hand_ = temp;
  } else {
    std::cout << "Invalid action: " << instruction << std::endl;
  }
}

void Player::drawPointCard() { // draw point card and place in players hand
  if (pointdeck_ != nullptr) {
    PointCard card = pointdeck_->Draw();
    hand_.addCard(std::move(card));
  }
}

void Player::playPointCard() {
  /**
   * @post: Play a point card from the player’s hand and update the player’s
   * score */
  if (!hand_.isEmpty()) {
    int points = hand_.PlayCard();
    score_ += points;
  }
}

void Player::setOpponent(Player *opponent) { // set opponent
  opponent_ = opponent; 
}

Player *Player::getOpponent() { // return a pointer to players opponent
  return opponent_; 
}

void Player::setActionDeck(Deck<ActionCard> *actiondeck) { // set action deck
  actiondeck_ = std::move(actiondeck);
}

Deck<ActionCard> *Player::getActionDeck() { // return a pointer to players action deck
  return actiondeck_; 
}

void Player::setPointDeck(Deck<PointCard> *pointdeck) { // set point deck of player
  pointdeck_ = std::move(pointdeck);
}

Deck<PointCard> *Player::getPointDeck() { // return a pointer to players point deck
  return pointdeck_; 
}
