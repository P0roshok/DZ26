#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include <vector>

using namespace std;

class Order{
private:

    static int total_orders;
    string date;
    string time;
    int duration;
    string description;
    double price;
    int order_id;

public:

    Order(string date, string time, int duration, string description, double price);
    static int getTotalOrders();
    int getOrderId() const;
    int getReadinessTimeInMinutes() const;
    string getReadinessTimeStr() const;
    void display() const;
};
