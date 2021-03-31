#pragma once

enum class ProductType
{
	MAIN_PRODUCT_0_STARS,
	MAIN_PRODUCT_3_STARS,
	MAIN_PRODUCT_5_STARS,
	SIMCARD,
	ACCESSORY_SOLO,
	ACCESSORY_DEPENDENT,
	SERVICE_DEFAULT,
	SERVICE_COMFORT
};

class Product
{
public:
	Product(ProductType type, float price);
	float getPayment();
	bool getCombo();
	bool getPersonal();
private:
	float m_price = 0.0;
	float m_coefficent = 0.0;
	bool m_combo = false;
	bool m_personal = false;
};

