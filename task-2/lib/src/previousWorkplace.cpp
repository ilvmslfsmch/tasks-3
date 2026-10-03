#include "../include/PreviousWorkplace.h"
#include <utility>

PreviousWorkplace::PreviousWorkplace(std::string company, std::string position, std::string period) : company(std::move(company)), position(std::move(position)), period(std::move(period)) {}

std::string PreviousWorkplace::getCompany() const noexcept {return company;}

std::string PreviousWorkplace::getPosition() const noexcept {return position;}

std::string PreviousWorkplace::getPeriod() const noexcept {return period;}

std::string PreviousWorkplace::toString() const {
	return company + " -- " + position + " (" + period + ")";
}
