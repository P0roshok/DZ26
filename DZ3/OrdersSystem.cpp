#include "OrdersSystem.h"

void OrdersSystem::addOrder(const Order& order)
{
	orders.push_back(order);
	cout << "Order #" << order.getOrderId() << " added.\n";
}

void OrdersSystem::sortByReadinessTime()
{
    if (orders.empty()) return;

    size_t n = orders.size();
    for (size_t i = 0; i < n - 1; i++) {
        for (size_t j = 0; j < n - i - 1; j++) {
            if (orders[j].getReadinessTimeInMinutes() > orders[j + 1].getReadinessTimeInMinutes()) {
                Order temp = orders[j];
                orders[j] = orders[j + 1];
                orders[j + 1] = temp;
            }
        }
    }
    cout << "\nOrders sorted by time.\n";
}

void OrdersSystem::executeFirstOrder()
{
    if (orders.empty()) {
        cout << "\nNo orders left to execute.\n";
        return;
    }
    cout << "\n>>> EXECUTING THE NEXT READY ORDER <<<\n";
    orders.front().display();
    orders.erase(orders.begin());
    cout << "---------------------------------------\n";
}

void OrdersSystem::displayAllOrders() const
{
    if (orders.empty()) {
        cout << "\nNo active orders in the system.\n";
        return;
    }
    cout << "\n========== CURRENT ORDERS LIST ==========\n";
    for (const auto& order : orders) {
        order.display();
    }
    cout << "=========================================\n";
}
