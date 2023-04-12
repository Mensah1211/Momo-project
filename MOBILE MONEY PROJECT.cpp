#include <iostream>
using namespace std;

// Default PIN and balance
const int DEFAULT_PIN = 0000;
const int DEFAULT_BALANCE = 1000;

// Maximum number of allowed wrong PIN attempts
const int MAX_WRONG_PIN_ATTEMPTS = 3;

int main() {
    int pin = DEFAULT_PIN;
    int balance = DEFAULT_BALANCE;
    int wrongPinAttempts = 0;
    int financial_option;
    int option;

    // Loop for program execution
    while (true) {
        cout << "________________________" << endl;
        cout << "MOBILE MONEY SERVICE." << endl;
        cout << "________________________" << endl;
        cout << "1. AUTHENTICATION" << endl;
        cout << "2. RESET/CHANGE PIN" << endl;
        cout << "3. CHECK BALANCE" << endl;
        cout << "4. SEND MONEY" << endl;
        cout << "5. FINANCIAL SERVICE" << endl;
        cout << "6. EXIT" << endl;
        cout << "ENTER OPTION:";
        cin >> option;

        switch (option) {
            case 1: {
                int enteredPin;
                cout << "ENTER PIN: ";
                cin >> enteredPin;

                if (enteredPin == pin) {
                    cout << "AUTHENTICATION SUCCESSFUL!" << endl <<endl;
                    wrongPinAttempts = 0;
                    // Reset wrong PIN attempts counter
                } else {
                    cout << "INCORRECT PIN! \nPLEASE TRY AGAIN!" << endl <<endl;
                    wrongPinAttempts++;

                    if (wrongPinAttempts >= MAX_WRONG_PIN_ATTEMPTS) {
                        cout << "Maximum wrong PIN attempts reached. Exiting..." << endl;
                        return 0;
                    }
                }
                break;
            }
            // Resetting Pin
            case 2: {
                int oldPin, newPin;
                cout << "ENTER OLD PIN: ";
                cin >> oldPin;
                cout << "ENTER NEW PIN: ";
                cin >> newPin;
                pin = newPin; // Update PIN
                cout << "PIN CHANGED SUCCESSFULLY!" << endl <<endl;
                break;
            }
            // Checking Balance
            case 3: {
                int enteredPin;
                cout << "ENTER PIN: ";
                cin >> enteredPin;
                if (enteredPin == pin) {
                    cout << "YOUR BALANCE IS: GHC" << balance << endl <<endl;
                } else {
                    cout << "PIN INCORRECT" << endl <<endl;
                }
                break;
            }
            // Sending Money
            case 4: {
                int amount, number, enteredPin;
                cout << "ENTER MOBILE MONEY NUMBER:";
                cin >> number;
                cout << "ENTER AMOUNT TO SEND: GHC";
                cin >> amount;
                cout << "ENTER PIN:";
                cin >> enteredPin;
                if (enteredPin == pin) {
                    cout << "PAYMENT MADE FOR GHC" << amount <<" TO " << number <<endl;
                } else {
                    cout << "YOU HAVE ENTER WRONG PIN" <<endl;
                    break;
                }

                if (amount > balance) {
                    cout << "YOU DO NOT HAVE SUFFICIENT FUNDS TO PERFORM THIS TRANSACTION." <<endl;
                } else {
                    balance -= amount; // Deduct sent amount from balance
                    cout << "YOUR BALANCE IS: GHC" << balance << endl <<endl;
                }
                break;
            }
            // Althernative Options
            case 5: {
                int financial_option;
                int amount;
                cout << "\nCHOOSE AN OPTION" << endl;
                cout << "1. BORROW MONEY" << endl;
                cout << "2. REPAY LOAN" << endl;
                cout << "3. BUY AIRTIME" << endl;
                cout << "4. BUY BUNDLE\n" << endl;
                cout << "ENTER AN OPTION:";
    cin >> financial_option;

    switch(financial_option){
    	// borrowing money
        case 1:{
            cout<<"ENTER AN AMOUNT TO BORROW(1 - 200): ";
            cin >> amount;
            if(amount!=1,200){
                cout <<"TRANSACTION FAILED. \nAMOUNT EXCEEDS LIMIT." <<endl <<endl;
            }
            else{
                balance+=amount;
                cout <<"CURRENT BALANCE IS GHC " << balance <<endl <<endl;
                cout <<"MONEY HAS BEEN SENT TO YOUR ACCOUNT SUCCESSFULLY" <<endl <<endl;
            }
        }
        // Repaying Loan
        case 2:{
            cout<<"ENTER AMOUNT TO PAY(1 - 200): ";
            cin>>amount;
            if(amount!=1,200){
                cout <<"REPAY LOAN UNSUCCESSFUL. \nAMOUNT EXCEEDS LIMIT." <<endl;
            }
            else{
                balance-=amount;
                cout << "AN AMOUNT OF  GHC"<< amount << "HAS BEEN DEDUCTED FROM YOUR ACCOUNT. \nCURRENT BALANCE IS GHC" <<balance <<endl;
                cout <<"REPAYING LOAN SUCCESSFUL.\n" <<endl;
            }
            break;
        }
        // buying airtime
        case 3:{
            cout<<"Enter Amount(1 - 500):";
            cin>>amount;
            if(amount!=1,500){
                cout <<"BUYING AIRTIME UNSUCCESSFUL. \nAMOUNT EXCEEDS LIMIT." <<endl <<endl;
            }
            else{
                balance-=amount;
                cout <<"CURRENT BALANCE IS GHC" <<balance <<endl;
                cout <<"BUYING AIRTIME SUCCESSFUL.\n" <<endl <<endl;
            }
            break;
        }
        // buying bundle
        case 4:{
            cout<<"ENTER AMOUNT TO BUY (0.01 - 500):";
            cin>>amount;
            if(amount!=1,500){
                cout <<"BUYING BUNDLE UNSUCCESSFUL. \nAMOUNT EXCEEDS LIMIT." <<endl <<endl;
            }
            else{
                balance-=amount;
                cout <<"BALANCE AVAILABLE IS GHC" <<balance <<endl;
                cout <<"BUYING BUNDLE SUCCESSFUL.\n" <<endl <<endl;
            }
            break;
        }
        default: {
            cout << "INVALID OPTION!PLEASE TRY AGAIN." << endl;
            break;
        }
    }
}

			// exiting program
            case 6: {
                cout << "Exiting..." << endl;
                return 0;
            }
            default: {
                cout << "INVALID OPTION!PLEASE TRY AGAIN." << endl;
                break;
            }
        }
    }
  
	
    return 0;
}
