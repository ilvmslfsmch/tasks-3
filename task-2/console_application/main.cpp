#include <iostream>
#include "../lib/include/HRDepartment.h"

int main(void) {
	HRDepartment hr;

	auto e1 = std::make_unique<Employee>("Иванов Иван Иванович", "12.03.1985",  Position("Программист"), Department("IT"), 1.0);
	e1->addPreviousWorkplace(PreviousWorkplace("ООО Ромашка", "Junior", "2010-2013"));
	e1->addPreviousWorkplace(PreviousWorkplace("ЗАО лютик", "Middle", "2013-2020"));
	int childId = 0;
	{
		auto child = std::make_unique<Person>("Иванов Пётр Иванович", "29.10.2007");
		childId = child->getId();
		e1->addChildId(childId);
		hr.addPerson(std::move(child));
	}
	hr.addPerson(std::move(e1));

	auto e2 = std::make_unique<Employee>("Петрова Анна Петровна", "10.12.1960", Position("Бухгалтер"), Department("Бухгалтерия"), 0.5);
	e2->setFlags(true, false, false, false);
	hr.addPerson(std::move(e2));

	auto e3 = std::make_unique<Employee>("Сидорова Мария Петровна", "21.11.1986", Position("Программист"), Department("IT"), 1.0);
	e3->addChildId(childId);
	e3->setFlags(false, false, false, true);
	hr.addPerson(std::move(e3));

	hr.printAll();

	hr.printByPosition("Программист");

	hr.printByRate(0.5);

	hr.printPensioners();

	hr.printOnMaternityLeave();

	hr.printPositionInfo();

	hr.printPreviousWorkplaces();

	hr.printByFullName("Петрова Анна Сергеевна");

	hr.printChildrenOf(childId - 0);

	return 0;
}
