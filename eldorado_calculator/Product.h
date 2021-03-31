#pragma once

enum class ProductType
{
	MAIN_PRODUCT_0_STARS,//�������� ����� ��� �����
	MAIN_PRODUCT_3_STARS,//�������� ����� 3 ������
	MAIN_PRODUCT_5_STARS,//�������� ����� 5 �����
	SIMCARD,//��������
	ACCESSORY_SOLO,//����������� ���������
	ACCESSORY_DEPENDENT,//��������� ���������
	SERVICE_DEFAULT,//������ �������
	SERVICE_COMFORT,//������ ������� ��� ���������� ������
	USELLES//����� ��� ���������� (��������, ���������� �� � ������)
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
	double m_price;//���� ������
	double m_coefficent;//���������� ����������
	bool m_combo;//��������� �� ����� � ����� ����
	bool m_personal;//���� �� ������� � ������������ ������
	bool m_comboReason;//����� �� ���� ����� ���� �������� � ������ ������� ����� ����
};

