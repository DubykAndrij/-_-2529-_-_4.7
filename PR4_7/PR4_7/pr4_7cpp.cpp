#include <iostream>
#include <iomanip>
#include <cmath>
#include <windows.h>
using namespace std;

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    double x_start, x_end, dx, eps;
    cout << "Введіть xпоч, xкін, dx, eps: ";
    cin >> x_start >> x_end >> dx >> eps;

    cout << fixed << setprecision(8);

    cout << "----------------------------------------------------------------------------\n";
    cout << "|        x        |     ln((x+1)/(x-1))     |   Сума ряду   |  К-ть членів |\n";
    cout << "----------------------------------------------------------------------------\n";

    for (double x = x_start; x <= x_end; x += dx) {
        if (fabs(x) <= 1) {
            cout << "| " << setw(15) << x
                << " | " << setw(23) << "недопустимо"
                << " | " << setw(12) << "-"
                << " | " << setw(12) << "-" << " |\n";
            continue;
        }

        double sum = 0.0;
        double term = 2.0 / x;
        int n = 0;

        while (fabs(term) > eps) {
            sum += term;
            n++;
            term *= (double)(2 * n - 1) / (2 * n + 1) * (1.0 / (x * x));
        }

        double exact = log((x + 1) / (x - 1));

        cout << "| " << setw(15) << setprecision(5) << x
            << " | " << setw(23) << setprecision(8) << exact
            << " | " << setw(12) << setprecision(8) << sum
            << "  | " << setw(12) << n << " |\n";
    }

    cout << "----------------------------------------------------------------------------\n";
    return 0;
}
