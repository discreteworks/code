#include  <iostream>
#include <array>

using namespace std;

int main() {
  const int size = 9;
  int basicPay;
  int totalSales;
  double totalSalary;
  const double commission = 0.09;

  array<int, size> counter = {0};
  cout << "Input sales[-1 to exit]:";
  cin >> totalSales;
  while (totalSales != -1) {
    totalSalary = 200 +  totalSales * commission;
    cout << "Salesman commission:" << totalSalary << endl;
    if  (totalSalary >= 1000 ) {
      counter[8]++;
    }
    for (int i = 0; i < 8 ; i++) {
      if (totalSalary >= (i + 2) * 100 && totalSalary < (i + 3) * 100) {
        counter[i]++;
      }
    }
    cout << "Input sales[-1 to exit]:";
    cin >> totalSales;
  }
  for (int i = 0; i < 9; i++) {
    if (i < 8) {
      cout  << "$" << (i + 2) * 100 <<  "-" << (i + 3) * 100 - 1;
    } else {
      cout  << "$" << "1000 and over";
    }
    for (int j = 0; j < counter[i]; j++) {
      cout << " * ";
    }
    cout << endl;
  }
  return 0;
}
