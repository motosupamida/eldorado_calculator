#include "Product.h"

Product::Product(ProductType type, double price)
	:
	m_price(price),
	m_coefficent(0.0),
	m_combo(false),
	m_comboReason(),
	m_personal(false)

{
	switch (type)
	{
	case ProductType::MAIN_PRODUCT_0_STARS:
		m_coefficent = 0.007;
		m_personal = false;
		m_combo = false;
		m_comboReason = true;
		break;
	case ProductType::MAIN_PRODUCT_3_STARS:
		m_coefficent = 0.015;
		m_personal = false;
		m_combo = false;
		m_comboReason = true;
		break;
	case ProductType::MAIN_PRODUCT_5_STARS:
		m_coefficent = 0.015;
		m_personal = false;
		m_combo = false;
		m_comboReason = true;
		break;
	case ProductType::SIMCARD:
		m_price = 70;
		m_coefficent = 1;
		m_personal = true;
		m_combo = true;
		m_comboReason = false;
		break;
	case ProductType::ACCESSORY_SOLO:
		m_coefficent = 0.02;
		m_personal = true;
		m_combo = true;
		m_comboReason = false;
		break;
	case ProductType::ACCESSORY_DEPENDENT:
		m_coefficent = 0.02;
		m_personal = true;
		m_combo = true;
		m_comboReason = false;
		break;
	case ProductType::SERVICE_DEFAULT:
		m_coefficent = 0.02;
		m_personal = true;
		m_combo = true;
		m_comboReason = false;
		break;
	case ProductType::SERVICE_COMFORT:
		m_coefficent = 0.05;
		m_personal = true;
		m_combo = true;
		m_comboReason = false;
		break;
	default:
		break;
	}
}

double Product::getPayment()
{
	return (m_price * m_coefficent);
}

double Product::getPrice()
{
	return m_price;
}

bool Product::getCombo()
{
	return m_combo;
}

bool Product::getPersonal()
{
	return m_personal;
}

bool Product::getComboReason()
{
	return m_comboReason;
}
