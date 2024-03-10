#include <iostream>
#include <string>

using namespace std;

const double vatRate = 0.18;
const double shareholderDividendTaxRate = 0.15;

double calculateCorporateTax(double profit) {
    if (profit <= 10000) {
        return profit * 0.10;
    } else if (10000 < profit <= 25000) {
        return profit*0.15;
    } else if (25000 < profit <= 50000) {
        return profit*0.20;
    } else {
        return profit*0.25;
    }
}

int main() {
    string companyName;
    double grossIncome;
    double expenses;
    int numShareholders;
    
    cout<<"This accounting program calculates the state taxes and dividends for the company shareholders."<<endl;
    cout<< "Enter the company name:";
    cin>> companyName;
    cout<<endl;
    cout<< "Enter the gross income of "<< companyName <<":";
    cin>> grossIncome;
    cout<<endl;
    cout<< "Enter the expenses of "<< companyName <<":" ;
    cin>> expenses;
    cout<<endl;
    cout<< "Enter the number of shareholders: ";
    cin>> numShareholders;
    cout<<endl;

    if (grossIncome < 0 || expenses <= 0 || numShareholders <= 1) {
        cout << "Invalid input. Gross income must be greater than 0, expenses non-negative, and at least 1 shareholder." << endl;
    } else {
        double vat = grossIncome * vatRate;

        double profit = grossIncome - expenses - vat;

        double corporateTax = calculateCorporateTax(profit);

        double netProfit = profit - corporateTax;

        double dividend;
        
        double capitalIncrease;

        if (netProfit > 0) {
            dividend = netProfit * 0.5 / numShareholders;
            capitalIncrease = netProfit * 0.5;
        } else {
            dividend = 0;
            capitalIncrease = 0;
        }

        double shareholderDividendTax = dividend * shareholderDividendTaxRate;

        double finalDividend = dividend - shareholderDividendTax;

        cout<< "********* " << companyName << " Financial Report" <<" *********" << endl;
        cout<<endl;
        /*cout << "Gross Income: " << grossIncome << " TL" << endl;
        cout << "Expenses: " << expenses << " TL" << endl;
        cout<< "Dividend per Shareholder: " << dividend << " TL" << endl;
        cout << "Profit: " << profit << " TL" << endl;*/
        cout<< "Net Profit: " << netProfit << " TL" << endl;
        cout<< "VAT: " << vat << " TL" << endl;
        cout<< "Corporate Tax: " << corporateTax << " TL" << endl;
        cout<<endl;
        cout<< "Capital Increase: " << capitalIncrease << " TL" << endl;
        cout<< numShareholders <<" shareholders will have a share of: " << finalDividend << " TL" << endl;
        cout<<endl;
        cout<< "********* " << companyName << " Financial Report" <<" *********" << endl;
    }

    return 0;
}

