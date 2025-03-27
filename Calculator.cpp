#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int user_choice;
char exit_char;

//=============Counting Functions===========//
int sqr(int b) {
    return b * b;
}

long int factorial(int x) {
    long int result = 1;
    for (int i = 1; i <= x; i++) {
        result *= i;
    }
    return result;
}

bool quadratic_trinomial(float a, float b, float c, float& x1, float& x2) {
    float delta = b * b - 4 * a * c;
    if (delta > 0) {
        x1 = (-b - sqrt(delta)) / (2 * a);
        x2 = (-b + sqrt(delta)) / (2 * a);
        return true;
    }
    else if (delta == 0) {
        x1 = x2 = -b / (2 * a);
        return true;
    }
    else {
        return false;
    }
}

long int fib(int x) {
    if (x <= 0) return 0;
    if (x == 1) return 1;
    long int a = 0, b = 1, temp;
    for (int i = 2; i <= x; i++) {
        temp = a + b;
        a = b;
        b = temp;
    }
    return b;
}

float median(int* tab, int table_length) {
    sort(tab, tab + table_length);
    if (table_length % 2 != 0) {
        return tab[table_length / 2];
    }
    else {
        return (tab[table_length / 2 - 1] + tab[table_length / 2]) / 2.0f;
    }
}

float arithmeticMean(int* tab, int table_length) {
    float sum = 0;
    for (int i = 0; i < table_length; i++) {
        sum += tab[i];
    }
    return sum / table_length;
}

int power(int base, int exponent) {
    return pow(base, exponent);
}

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

//=============Void Functions===========//
void interface() {
    cout << "1. Factorial\n";
    cout << "2. Quadratic trinomial\n";
    cout << "3. Fibonacci sequence\n";
    cout << "4. Median and arithmetic mean\n";
    cout << "5. Power function\n";
    cout << "6. Greatest Common Divisor (GCD)\n";
    cout << "7. Least Common Multiple (LCM)\n";
    cout << "Choose action: ";
}

void calculator() {
    do {
        system("cls");
        interface();
        cin >> user_choice;

        if (user_choice < 1 || user_choice > 7) {
            system("cls");
            cout << "You made a mistake in typing action!";
        }
        else if (user_choice == 1) {
            system("cls");
            int x;
            cout << "Type number: ";
            cin >> x;
            cout << x << "! = " << factorial(x);
        }
        else if (user_choice == 2) {
            system("cls");
            cout << "Provide coefficients a, b, c:\n";
            float a, b, c, x1, x2;
            cin >> a >> b >> c;
            if (quadratic_trinomial(a, b, c, x1, x2)) {
                cout << "x1 = " << x1 << "\nx2 = " << x2;
            } else {
                cout << "Quadratic trinomial has no real solutions";
            }
        }
        else if (user_choice == 3) {
            system("cls");
            cout << "Enter the term of the sequence: ";
            int x;
            cin >> x;
            cout << "\nTerm nr " << x << " is " << fib(x);
        }
        else if (user_choice == 4) {
            system("cls");
            cout << "Enter the table length: ";
            int table_length;
            cin >> table_length;
            
            int* tab = new int[table_length];
            cout << "Enter " << table_length << " numbers: ";
            for (int i = 0; i < table_length; i++) {
                cin >> tab[i];
            }

            cout << "\nMedian: " << median(tab, table_length);
            cout << "\nArithmetic mean: " << arithmeticMean(tab, table_length);
            
            delete[] tab;
        }
        else if (user_choice == 5) {
            system("cls");
            int base, exponent;
            cout << "Enter base and exponent: ";
            cin >> base >> exponent;
            cout << "Result: " << power(base, exponent);
        }
        else if (user_choice == 6) {
            system("cls");
            int a, b;
            cout << "Enter two numbers: ";
            cin >> a >> b;
            cout << "GCD: " << gcd(a, b);
        }
        else if (user_choice == 7) {
            system("cls");
            int a, b;
            cout << "Enter two numbers: ";
            cin >> a >> b;
            cout << "LCM: " << lcm(a, b);
        }
        
        cout << "\nWould you like to exit the application? [Y/N] ";
        cin >> exit_char;
    } while (exit_char == 'n' || exit_char == 'N');
}

int main() {
    calculator();
    return 0;
}
