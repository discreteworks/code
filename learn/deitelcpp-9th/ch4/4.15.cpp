#include <iostream>
#include <iomanip>

using namespace std;

#define COMMISSION  9/100
#define SALEMAN_PAY 200


int main()
{
  double sales;
  double total;

  cin >> sales;

  while(sales != -1)
  {
    total = SALEMAN_PAY + sales * COMMISSION;
    cout << "Sales is :"<< "$" << fixed << setprecision(2) <<  total << endl;
    cin >> sales;
  }
  return  0;

}
