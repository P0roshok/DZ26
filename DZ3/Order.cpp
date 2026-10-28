#include "Order.h"

Order::Order(string date, string time, int duration, string description, double price)
{
	this->date = date;
	this->time = time;
	this->duration = duration;
	this->description = description;
	this->price = price;

	total_orders++;
	this->order_id = total_orders;
}

int Order::getTotalOrders()
{
	return total_orders;
}

int Order::getOrderId() const
{
	return order_id;
}

int Order::getReadinessTimeInMinutes() const
{
	int hours = 0, minutes = 0;
	size_t colon = time.find(':');
	if (colon != string::npos) {
		hours = stoi(time.substr(0, colon));
		minutes = stoi(time.substr(colon + 1));
	}
	return hours * 60 + minutes + duration;
}

string Order::getReadinessTimeStr() const
{
	int total_mins = getReadinessTimeInMinutes() % (24 * 60);
	int hours = total_mins / 60;
	int minutes = total_mins % 60;
	return (hours < 10 ? "0" : "") + to_string(hours) + ":" + (minutes < 10 ? "0" : "") + to_string(minutes);
}

void Order::display() const
{
	cout << "Order #" << order_id
		<< " | Time: " << time
		<< " | Ready: " << getReadinessTimeStr()
		<< " | Price: " << price << " hrn\n"
		<< "   Description: " << description << "\n";
}

int Order::total_orders = 0;