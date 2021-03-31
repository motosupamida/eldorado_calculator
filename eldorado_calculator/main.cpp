#include <iostream>
#include <vector>
#include <Windows.h>

#include "Check.h"

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	std::vector<Check> checkList;

	bool oneMoreCheck(false);
	do
	{
		checkList.push_back(Check());
	} while (oneMoreCheck);
	
	double teamTotalPayment(0.0);
	double personalTotalPayment(0.0);
	int teamSize(6);//колличество сотрудников на которых делится коллективная премия

	system("cls");

	for (int i = 0; i < checkList.size(); i++)
	{
		std::cout << "\nВыписка № " << i + 1 << std::endl;
		double teamPayment = checkList[i].getPayment(PaymentType::TEAM) / teamSize;
		teamTotalPayment += teamPayment;
		std::cout << "Выплата в коллективную премию: " << teamPayment << " руб." << std::endl;
		double personalPayment = checkList[i].getPayment(PaymentType::PERSONAL);
		personalTotalPayment += personalPayment;
		std::cout << "Выплата в персональную премию: " << personalPayment << " руб.\n" << std::endl;
	}

	std::cout << "\n\nКолличество выписок: " << checkList.size() << std::endl;
	std::cout << "Итоговая выплата в коллективную премию: " << teamTotalPayment << " руб." << std::endl;
	std::cout << "Итоговая выплата в личную премию: " << personalTotalPayment << " руб." << std::endl;
	std::cout << "Всего продавец себе заработал: " << teamTotalPayment + personalTotalPayment << " руб." << std::endl;

	return 0;
}