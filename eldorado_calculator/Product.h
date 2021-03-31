#pragma once

enum class ProductType
{
	MAIN_PRODUCT_0_STARS,//основной товар без звезд
	MAIN_PRODUCT_3_STARS,//основной товар 3 звезды
	MAIN_PRODUCT_5_STARS,//основной товар 5 звезд
	SIMCARD,//симкарта
	ACCESSORY_SOLO,//независимый аксессуар
	ACCESSORY_DEPENDENT,//зависимый аксессуар
	SERVICE_DEFAULT,//услуга стандар
	SERVICE_COMFORT,//услуга комфорт или финансовый сервис
	USELLES//товар без отчислений (доставка, добавление бк и прочее)
};

class Product
{
public:
	Product(ProductType type, double price);
	double getPayment();
	double getPrice();
	bool getCombo();
	bool getPersonal();
	bool getComboReason();
private:
	double m_price;//цена товара
	double m_coefficent;//коэффицент отчислений
	bool m_combo;//участвует ли товар в комбо чеке
	bool m_personal;//идет ли выплата в персональную премию
	bool m_comboReason;//может ли этот товар быть основным и давать причину комбо чека
};

