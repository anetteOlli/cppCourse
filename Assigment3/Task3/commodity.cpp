
#include "commodity.hpp"

//Assigment 3, task3, commodity.hpp

const double tax = 0.25;

Commodity::Commodity(const string &name_, const int id_, const double price_) : name(name_), id(id_), price(price_) {}

const string &Commodity::get_name() const {
    return name;
}

const int Commodity::get_id() const {
    return id;
}

double Commodity::get_price() const {
    return price;
}

double Commodity::get_price(const double quantum) const {
    return price * quantum;
}

void Commodity::set_price(const double price_) {
    price = price_;
}

double Commodity::get_price_with_sales_tax() const {
    return price + (price * tax);
}

double Commodity::get_price_with_sales_tax(const double quantum) const {
    return price*quantum + (price*quantum*tax);
}
