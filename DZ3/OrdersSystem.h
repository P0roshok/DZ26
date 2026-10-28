#pragma once
#include "Order.h"

class OrdersSystem
{

private:
	vector<Order> orders;

public:
	void addOrder(const Order& order);
	void sortByReadinessTime();
	void executeFirstOrder();
	void displayAllOrders() const;
};

