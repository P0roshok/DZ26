#include "OrdersSystem.h"

int main() {
    OrdersSystem system;

    system.addOrder(Order("28.10.2026", "15:30", 15, "Big Mac, Coca-Cola", 8.99));
    system.addOrder(Order("28.10.2026", "15:20", 30, "Double Cheeseburger, Filet-O-Fish", 11.50));
    system.addOrder(Order("28.10.2026", "15:25", 10, "Large Cappuccino, Muffin", 5.20));

    system.displayAllOrders();
    system.sortByReadinessTime();
    system.displayAllOrders();
    system.executeFirstOrder();
    system.displayAllOrders();

    cout << "\nTotal orders created: " << Order::getTotalOrders() << "\n";

    return 0;
}