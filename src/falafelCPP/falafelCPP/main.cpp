/*
 * falafelCPP Version1.0
 * Frank Bernal
 * CIS 054 C/C++ Programming
 * Input: Selections
 * Output: Total, tax, itemized list
 * 19 Mar 2022
 */

// Input Output stream
#include <iostream>
// Input Output manipulation for decimal points
#include <iomanip>
// Library to utilize toupper
#include <cctype>
// Std namespace
using namespace std;

//funtction prototype
void displayMenu();

// Constants
const double FALAFEL_PRICE = 5.15;
const double SODA_PRICE = 2.24;
const double EXTRAS_PRICE = 1.57;
const double SALES_TAX = 0.087;   // Tax is 8.7%

// Start main
int main(int argc, const char * argv[]) {
    // Local Variables
    double subtotal = 0.00;
    double total = 0.00;
    double price;
    char selection;
    int falafelCount = 0;
    int sodaCount = 0;
    int extrasCount = 0;
    
    // Call menu
    displayMenu();
    
    // Loop user input until order complete
    do {
        // Zero out price
        price = 0.00;
        cout << "Make your selection [F][S][X][T]: ";
        cin >> selection;
        // Input converted to upper
        switch (toupper(selection)){
            case 'F':   // Falafel selected, count added, price added to subtotal
                price = FALAFEL_PRICE;
                falafelCount++;
                subtotal += price;
                break;
            case 'S':   // Soda selected, count added, price added to subtotal
                price = SODA_PRICE;
                sodaCount++;
                subtotal += price;
                break;
            case 'X':   // Extras selected, count added, price added to subtotal
                price = EXTRAS_PRICE;
                extrasCount++;
                subtotal += price;
                break;
            case 'T':
                break;
            default:   // Input other than F S X or T
                cout << "Illegal Selection, try again." << endl;
        }   // End of switch statement
    } while (selection != 'T' && selection != 't');
    // End of loop
    
    // Compute total
    total = (subtotal + SALES_TAX) + subtotal;
    
    // Display bill
    cout << "===================" << endl;
    cout << "  Items Purchased  " << endl;
    cout << "===================" << endl;
    
    // Zero items
    if (falafelCount == 0 && sodaCount == 0 && extrasCount == 0)
        cout << " 0 Items Purchased " << endl;
    // Singular or Multiple items
    if (falafelCount == 1)
        cout << falafelCount << " Falafel" << endl;
    else if (falafelCount > 1)
        cout << falafelCount << " Falafels" << endl;
    if (sodaCount == 1)
        cout << sodaCount << " Soda" << endl;
    else if (sodaCount > 1)
        cout << sodaCount << " Sodas" << endl;
    if (extrasCount == 1)
        cout << extrasCount << " Extra" << endl;
    else if (extrasCount > 1)
        cout << extrasCount << " Extras" << endl;
    // End of items
    cout << "===================" << endl;
    cout << setiosflags(ios::fixed | ios::showpoint);
    cout << setprecision(2);
    cout << "Subtotal " << subtotal << endl;
    cout << "Tax      " << (subtotal * SALES_TAX) << endl;
    cout << "Total    " << total << endl << endl;
    
    
    return 0;
}   // End of Main

// Start of displayMenu
void displayMenu() {
    // Print the menu
    cout << "[F] = Falafel " << FALAFEL_PRICE << endl;
    cout << "[S] = Soda " << SODA_PRICE << endl;
    cout << "[X] = Extras " << EXTRAS_PRICE << endl;
    cout << "[T] = Total " << endl;
}   // End of displayMenu
