#include <iostream>
#include "../lib/include/HRDepartment.h"

int main(void) {
	HRDepartment hr;

	hr.addDepartment(Department("IT"));
	hr.addDepartment(Department("Бухгалтерияя"));
	hr.addDepartment(Department("HR"));

	hr.addPosition(Position("Программист"));
	hr.addPosition(Position("Бухгалтер"));
	hr.addPosition(Position("HR-менеджер"));

	auto e1 = std::make_unique<Employee>("Иванов Иван Иванович", "12.03.1985",  Position("Программист"), Department("IT"), 1.0);
	int e1Id = e1->getId();
	e1->setFlags(false, true, false, true);
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
	e2->setFlags(true, false, true, false);
	hr.addPerson(std::move(e2));

	auto e3 = std::make_unique<Employee>("Сидорова Мария Петровна", "21.11.1986", Position("Программист"), Department("IT"), 1.0);
	e3->addChildId(childId);
	e3->setFlags(false, false, false, true);
	hr.addPerson(std::move(e3));

	std::cout << "Все люди:" << std::endl;
	hr.printAll();

	std::cout << "\nСотрудники-программисты:" << std::endl;
	hr.printByPosition("Программист");

	std::cout << "\nСотрудники со ставкой 0.5:" << std::endl;
	hr.printByRate(0.5);

	std::cout << "\nСотрудники с детьми:" << std::endl;
	hr.printWithChildren();

	std::cout << "\nПенсионеры:" << std::endl;
	hr.printPensioners();

	std::cout << "\nСотрудники с инвалидностью:" << std::endl;
	hr.printDisabled();

	std::cout << "\nВ отпуске:" << std::endl;
	hr.printOnVacation();

	std::cout << "\nВ декретном отпуске:" << std::endl;
	hr.printOnMaternityLeave();

	std::cout << "\nИнформация о должностях:" << std::endl;
	hr.printPositionInfo();

	std::cout << "\nПредыдущие места работы:" << std::endl;
	hr.printPreviousWorkplaces();

	std::cout << "\nПоиск по имени: Петрова Анна Петровна" << std::endl;
	hr.printByFullName("Петрова Анна Петровна");

	hr.printChildrenOf(e1Id);

	return 0;
}
