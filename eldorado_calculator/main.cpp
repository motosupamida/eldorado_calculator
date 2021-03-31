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
	int teamSize(6);//����������� ����������� �� ������� ������� ������������ ������

	system("cls");

	for (int i = 0; i < checkList.size(); i++)
	{
		std::cout << "\n������� � " << i + 1 << std::endl;
		double teamPayment = checkList[i].getPayment(PaymentType::TEAM) / teamSize;
		teamTotalPayment += teamPayment;
		std::cout << "������� � ������������ ������: " << teamPayment << " ���." << std::endl;
		double personalPayment = checkList[i].getPayment(PaymentType::PERSONAL);
		personalTotalPayment += personalPayment;
		std::cout << "������� � ������������ ������: " << personalPayment << " ���.\n" << std::endl;
	}

	std::cout << "\n\n����������� �������: " << checkList.size() << std::endl;
	std::cout << "�������� ������� � ������������ ������: " << teamTotalPayment << " ���." << std::endl;
	std::cout << "�������� ������� � ������ ������: " << personalTotalPayment << " ���." << std::endl;
	std::cout << "����� �������� ���� ���������: " << teamTotalPayment + personalTotalPayment << " ���." << std::endl;

	return 0;
}