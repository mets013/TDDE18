#include <iostream>
#include <iomanip>
using namespace std;

int main() {

    // Variables ------------------------------------------

    float first_price{},
          last_price{}, 
          stride{}, 
          tax_percent{},
          price_with_tax{},
          tax{},
          price{};

    // Input part -----------------------------------------

    cout << "INPUT PART\n" 
         << "==========\n";
    
    do { // add f just to be sure...
        cout << "Enter first price: ";
        cin  >> first_price;
        cin.ignore(1000, '\n');
        if (first_price < 0.0f) {
            cout << "ERROR: First price must be at least 0 (zero) SEK\n";
        }
    }
    while (first_price < 0.0f);
    
    do {
    // makes sense, we don't want to allow the user to decrease between
    // last and first price, could be changed but something might break
    // then... 
         cout << "Enter last price : ";
        cin  >> last_price;
        cin.ignore(1000, '\n');
        if (last_price <= first_price) {
            cout << "ERROR: Last price must be larger than first price\n";
        }
    }
    while (last_price <= first_price);

    do { // same as example
        cout << "Enter stride     : ";
        cin  >> stride;
        cin.ignore(1000, '\n');
        if (stride < 0.01f) {
            cout << "ERROR: Stride must be at least 0.01\n";
        }
    }
    while (stride < 0.01f);

    do { 
        // note it can't be 100 or 0 since it says "between"
        // in the instructions easy fix if 0 and 100 is desired
        cout << "Enter tax percent: ";
        cin  >> tax_percent;
        if (tax_percent >= 100.0f or tax_percent <= 0.0f) {
            cout << "ERROR: Tax percent must be between 0 and 100\n";
        }
    }
    while (tax_percent >= 100.0f or tax_percent <= 0.0f);

    tax_percent = tax_percent/100.0f;

    // Tax table ------------------------------------------

    cout << "TAX TABLE\n"
         << "=========\n"
         << setw(12) << "Price" 
         << setw(17) << "Tax" 
         << setw(20) << "Price with tax\n"
         << setw(50) << setfill('-') << '\n';

    for (int step = 0; first_price+step*stride <= last_price; ++step) {
        // using int steps instead of just ++stride due to
        // float error rounding
        
        price = first_price+step*stride; 
        // define price to make it look nicer and match with
        // the tables header
        tax = price*tax_percent;
        price_with_tax = price+tax;

        cout << setfill(' ') << setprecision(2) << fixed
             << setw(12) << price
             << setw(17) << tax
             << setw(20) << price_with_tax << '\n';
    }

    return 0;
}