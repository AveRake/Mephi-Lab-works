#include "SmartPointer.h"


int main() {
    SmrtPtr<int> sp1(new int(42));
    SmrtPtr<int> sp2 = sp1;
    SmrtPtr<int> sp3(new int(100));

    *sp3 = 10;

    cout << *sp1 << endl;
    cout << *sp2 << endl;
    cout << *sp3 << endl;

    SmrtPtr<int> sp4(new int(42));

    if (sp4) {
        cout << "SmartPointer is not null.\n";
    } else {
        cout << "SmartPointer is null.\n";
    }

    SmrtPtr<double> sp5(new double[5]{1.5, 2.5, 3.5, 4.5, 5.5}, 5);
    SmrtPtr<double> sp7(new double[5]{2.5, 4.5, 6.5, 8.5, 10.5}, 5);
    sp7 = sp5;

    for (size_t i = 0; i < 5; ++i) {
        cout << sp5[i] << " ";
    }

    cout << endl;

    for (size_t i = 0; i < 5; ++i) {
        cout << sp7[i] << " ";
    }

    cout << endl;

    system("pause");
    return 0;
}