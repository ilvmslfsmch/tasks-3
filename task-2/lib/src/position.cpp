#include "../include/Position.h"
#include <utility>

Position::Position(const std::string title) : title(title) {}

const std::string Position::getTitle() const noexcept {return title;}

