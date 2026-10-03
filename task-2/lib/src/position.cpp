#include "../include/Position.h"
#include <utility>

Position::Position(std::string title) : title(std::move(title)) {}

const std::string Position::getTitle() const noexcept {return title;}

