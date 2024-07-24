#include <iostream>
#include <iomanip>

using namespace std;

#define COMMISSION  9/100
#define SALEMAN_PAY 200

int main() {
  double sales = -1;
  double total = 0;

  cout << "Enter sales[-1 to exit]:";
  cin >> sales;
  while(sales != -1) {
    total = SALEMAN_PAY + sales * COMMISSION;
    cout << "Salesman commission:"<< "$" << fixed << setprecision(2) <<  total << endl;
    cout << "Enter sales[-1 to exit]:";
    cin >> sales;
  }
  return  0;
}
