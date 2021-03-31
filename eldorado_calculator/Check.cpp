#include "Check.h"

Check::Check()
{
	system("cls");
	std::cout << "1 - �������� ����� ��� �����" << std::endl;
	std::cout << "2 - ������ ��������" << std::endl;
	std::cout << "3 - �������� ����� 3 ������" << std::endl;
	std::cout << "4 - ������ �������, ���������� ������, ���������" << std::endl;
	std::cout << "5 - �������� ����� 5 �����" << std::endl;
	std::cout << "6 - ��������� �����������" << std::endl;
	std::cout << "7 - ��������" << std::endl;
	std::cout << "8 - ��������� ���������" << std::endl;
	std::cout << "9 - ����� ��� ���������� (��������, ���������� �� � ������)" << std::endl;
	std::cout << "0 - �����" << std::endl;

	double userInput(0);
	bool oneMoreProduct(false);

	do
	{
		std::cout << "\n��� ������: ";
		std::cin >> userInput;
		double type = userInput;
		if (type != 0)
		{
			oneMoreProduct = true;
		}
		else
		{
			oneMoreProduct = false;
			continue;
		}
		std::cout << "���� ������: ";
		std::cin >> userInput;
		double price = userInput;

		if (type == 1)
			m_productList.push_back(Product(ProductType::MAIN_PRODUCT_0_STARS, price));
		else if (type == 2)
			m_productList.push_back(Product(ProductType::SERVICE_DEFAULT, price));
		else if (type == 3)
			m_productList.push_back(Product(ProductType::MAIN_PRODUCT_3_STARS, price));
		else if (type == 4)
			m_productList.push_back(Product(ProductType::SERVICE_COMFORT, price));
		else if (type == 5)
			m_productList.push_back(Product(ProductType::MAIN_PRODUCT_5_STARS, price));
		else if (type == 6)
			m_productList.push_back(Product(ProductType::ACCESSORY_SOLO, price));
		else if (type == 7)
			m_productList.push_back(Product(ProductType::SIMCARD, price));
		else if (type == 8)
			m_productList.push_back(Product(ProductType::ACCESSORY_DEPENDENT, price));
		else if (type == 9)
			m_productList.push_back(Product(ProductType::USELLES, price));
		else
			std::cout << "\n������ ���������� ������." << std::endl;

	} while (oneMoreProduct);
}

double Check::getPayment(PaymentType type)
{
	double answer(0.0);
	int comboCounter(0);
	bool comboReason(false);
	double comboPrice(0.0);

	switch (type)
	{
	case PaymentType::TEAM:
		for (int i = 0; i < m_productList.size(); i++)
		{
			if (!m_productList[i].getPersonal())
				answer += m_productList[i].getPayment();
		}
		break;
	case PaymentType::PERSONAL:
		for (int i = 0; i < m_productList.size(); i++)
		{
			if (m_productList[i].getPersonal())
			{
				answer += m_productList[i].getPayment();
				if (m_productList[i].getCombo())
				{
					comboCounter++;
					comboPrice += m_productList[i].getPrice();
				}
			}
			else if (m_productList[i].getComboReason())
				comboReason = true;
		}
		break;
	default:
		break;
	}

	if ((comboReason) && (type == PaymentType::PERSONAL))
	{
		if ((comboPrice >= 2500) && (comboCounter >= 3))
			answer += 200;
		else if ((comboPrice >= 2000) && (comboCounter >= 2))
			answer += 150;
		else if ((comboPrice >= 1500) && (comboCounter >= 1))
			answer += 100;
	}
	
	return answer;
}

double Check::getComboPayment()
{
	return 0.0;
}
