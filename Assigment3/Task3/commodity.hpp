#include <string>
using namespace std;


class Commodity {
public:
    Commodity(const string &name_, const int id_, const double price_ );
    const string &get_name() const;
    const int get_id() const;
    double get_price() const;
    double get_price(const double quantum) const;
    void set_price(const double price_);
    double get_price_with_sales_tax() const;
    double get_price_with_sales_tax(const double quantum) const;
private:
    const string name;
    const int id;
    double price;
};



