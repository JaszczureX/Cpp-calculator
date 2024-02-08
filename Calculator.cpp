#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;

int user_choice;
char exit_char;
//=============Counting Functions===========//
int sqr(int b) {
    b = b * b;
    return b;
}
long int factorial(int x) {
    long int result = 1;
    for (int i = 1; i <= x; i++) {
        result *= i;
    }
    return result;
}
float quadric_tritomial(float a, float b, float c, float& x1, float& x2) {
    float delta = sqr(b) - 4 * a * c;
    if (delta > 0) {
        x1 = (-b - sqrt(delta) / 2 * a);
        x2 = (-b + sqrt(delta) / 2 * a);
        return true;
    }
    else if (delta == 0) {
        x1 = x2 = (-b / 2 * a);
        return true;
    }
    else {
        return false;
    }
}

long int fib(int x) {
    if (x < 3) {
        return 1;
    }
    else {
        return fib(x - 2) + fib(x - 1);
    }
}
//=============Counting Functions===========//
//=============Void Functions===========//
void interface() {
    cout << "1. Factorial\n";
    cout << "2. Quadratic trinomial\n";
    cout << "3. Fibonacci sequence\n";
    cout << "4. Median and arithmetic mean\n";
    cout << "Choose actions: ";
}

static void calculator() {
    do
    {
        system("cls");
        interface();
        cin >> user_choice;
        if (user_choice > 4 || user_choice < 1) {
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
            cout << "Provide coefficients a, b, c.\n";
            float a, b, c;
            float x1{ 0 }, x2{ 0 };
            cin >> a >> b >> c;
            if (quadric_tritomial(a, b, c, x1, x2)) {
                system("cls");
                cout << "x1 = " << x1;
                cout << "\nx2 = " << x2;
            }
            else {
                cout << "Quadric tritomial has no solutions";
            }
        }
        else if (user_choice == 3) {
            system("cls");
            cout << "Enter the term of the sequence: ";
            int x;
            cin >> x;
            cout << "\nterm nr: " << x << " is " << fib(x);
        }
        else if (user_choice == 4) {
            system("cls");
            cout << "Enter the table length: ";
            int table_length = 0;
            cin >> table_length;
            int* tab = new int[table_length];
            float sum = 0;
            for (int i = 0; i < table_length; i++) {
                cin >> tab[i];
                sum += tab[i];
            }
            sort(tab, tab + table_length);
            cout << "\nArithmetic mean: " << sum / table_length;
            if (table_length % 2 != 0)
            {
                cout << "\nMedian :" << tab[table_length / 2];
            }
            else {
                cout << "\nMedian :" << (tab[table_length / 2 - 1] + tab[table_length / 2]) / 2;
            }
        }
        cout << "\nWould you like to exit the application?[Y/N]";
        cin >> exit_char;
    } while (exit_char == 'n' || exit_char == 'N');
}
//=============Void Functions===========//
int main()
{
    calculator();
}