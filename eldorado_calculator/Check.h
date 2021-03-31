#pragma once

#include <iostream>
#include <vector>

#include "Product.h"

enum class PaymentType
{
	TEAM,
	PERSONAL
};

class Check
{
public:
	Check();
	double getPayment(PaymentType type);
private:
	std::vector<Product> m_productList;
	double getComboPayment();

};

