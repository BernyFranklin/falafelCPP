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
// Input Output Manipulation (Decimal placement)
#include <iomanip>
// Library to utilize toupper
#include <cctype>
// Std namespace
using namespace std;

// Function prototypes
char menu();
void displayMenu();

// Defining Constants
const double FALAFEL_PRICE = 5.15;
const double SODA_PRICE = 2.24;
const double EXTRAS_PRICE = 1.57;
const double TAX_RATE = 0.087;   // 8.7% tax

// Start main
int main(int argc, const char * argv[]) {
    // Local Variables
    char selection;
    double price = 0.00;
    int falafelCount = 0;
    int sodaCount = 0;
    int extrasCount = 0;
    double subTotal = 0.00;
    double salesTax = 0.00;
    double finalTotal = 0.00;
    
    // Make selection for delicious falafels
    // Loop until order is done.
    do {
        // Clear previous price
        price = 0.00;
        // Display Menu and get user selection
        selection = menu();
    } while (selection != 'T');   // Exit after user selects T
    return 0;
}   // End of Main

// Start menu
char menu() {
    // Clear any previous selection
    char choice = ' ';
    // Flag for too many characters
    bool tooLong;
    // Used to display menu once
    bool menuDisplayed = false;
    // Display menu only one time
    if (!menuDisplayed) {
        // Blank line
        cout << endl;
        // Menu
        cout << "F = falafel " << FALAFEL_PRICE;
        cout << "S = soda    " << SODA_PRICE;
        cout << "X = extras  " << EXTRAS_PRICE;
        cout << "T = total   " << endl << endl;
        // Set flag to true
        menuDisplayed = true;
    }   // End of menu display
    
    // Prompt user and check for proper input length
    // Loop until correct
    //do {
        // Assume good at first
        //tooLong = false;
        // Used to check length of choice
       // int choiceLength;
        // Prompt for input
        cout << "Make a selection: ";
        // Get input
        cin >> choice;
        choice = toupper(choice);
        
    //} while (tooLong);   // Do until menu selection is only 1 char
    return choice;
}   // End of menu
