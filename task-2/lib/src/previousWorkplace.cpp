#include "../include/PreviousWorkplace.h"
#include <utility>

PreviousWorkplace::PreviousWorkplace(const std::string company, const std::string position, const std::string period) : company(company), position(position), period(period) {}

std::string PreviousWorkplace::getCompany() const noexcept {return company;}

std::string PreviousWorkplace::getPosition() const noexcept {return position;}

std::string PreviousWorkplace::getPeriod() const noexcept {return period;}

std::string PreviousWorkplace::toString() const {
	return company + " -- " + position + " (" + period + ")";
}
