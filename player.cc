#include "player.h"
#include "color.h"

Player::Player(Color color, std::shared_ptr<Board> board): color{color}, board{board} {}