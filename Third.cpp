#include <iostream>
#include <cstdlib>
#include <cmath>
#include <string>

using namespace std;

#pragma region integral_methods

typedef long double(*Formula)(long double);
typedef void(*IntergalMethod)(long double, long double, long double, Formula);

void output(long double n_square, long double eps, long double number_of_steps) {
    cout << "square = " << fixed << n_square << endl;
    cout << "eps = " << eps << endl;
    cout << "n = " << number_of_steps << endl;
    system("pause");
}

void left_rect_integral(long double a, long double b, long double acc, Formula formula) {
    long double eps = 1;
    long double number_of_steps = 2;
    long double length = b - a;
    long double step = length / number_of_steps;
    long double x = 0;
    long double function;
    long double n_square = 0;
    long double n_prev_square = 0;

    while (eps > acc) {
        x = 0;
        n_prev_square = n_square;
        n_square = 0;
        for (int i = 1; i < number_of_steps; i++) {
            function = formula(x);
            n_square = n_square + function * step;
            x += step;
        }
        eps = abs(n_square - n_prev_square);
        number_of_steps *= 2;
        step = length / number_of_steps;
    }
    output(n_square, eps, number_of_steps);
}

void right_rect_integral(long double a, long double b, long double acc, Formula formula) {
    long double eps = 1;
    long double number_of_steps = 2;
    long double length = b - a;
    long double step = length / number_of_steps;
    long double x = 0;
    long double function;
    long double n_square = 0;
    long double n_prev_square = 0;

    while (eps > acc) {
        x = step;
        n_prev_square = n_square;
        n_square = 0;
        for (int i = 1; i < number_of_steps; i++) {
            function = formula(x);
            n_square = n_square + function * step;
            x += step;
        }
        eps = abs(n_square - n_prev_square);
        number_of_steps *= 2;
        step = length / number_of_steps;
    }
    output(n_square, eps, number_of_steps);
}

void mid_rect_integral(long double a, long double b, long double acc, Formula formula) {
    long double eps = 1;
    long double number_of_steps = 2;
    long double length = b - a;
    long double step = length / number_of_steps;
    long double x = 0;
    long double function;
    long double n_square = 0;
    long double n_prev_square = 0;

    while (eps > acc) {
        x = step / 2;
        n_prev_square = n_square;
        n_square = 0;
        for (int i = 1; i < number_of_steps; i++) {
            function = formula(x);
            n_square = n_square + function * step;
            x += step;
        }
        eps = abs(n_square - n_prev_square);
        number_of_steps *= 2;
        step = length / number_of_steps;
    }
    output(n_square, eps, number_of_steps);
}

void trapez_integral(long double a, long double b, long double acc, Formula formula) {
    long double eps = 1;
    long double number_of_steps = 2;
    long double length = b - a;
    long double step = length / number_of_steps;
    long double x = 0;
    long double function;
    long double next_function;
    long double n_square = 0;
    long double n_prev_square = 0;

    while (eps > acc) {
        x = 0;
        n_prev_square = n_square;
        n_square = 0;
        for (int i = 1; i < number_of_steps; i++) {
            function = formula(x);
            next_function = formula(x + step);
            n_square = n_square + step * (function + next_function) / 2;
            x += step;
        }
        eps = abs(n_square - n_prev_square);
        number_of_steps *= 2;
        step = length / number_of_steps;
    }
    output(n_square, eps, number_of_steps);
}

void simpson_integral(long double a, long double b, long double acc, Formula formula) {
    long double eps = 1;
    long double number_of_steps = 2;
    long double length = b - a;
    long double step = length / number_of_steps;
    long double x = 0;
    long double function;
    long double next_function;
    long double mid_function;
    long double n_square = 0;
    long double n_prev_square = 0;

    while (eps > acc) {
        x = 0;
        n_prev_square = n_square;
        n_square = 0;
        for (int i = 1; i < number_of_steps; i++) {
            function = formula(x);
            next_function = formula(x + step);
            mid_function = formula(x + step / 2);
            n_square = n_square + (function + mid_function * 4 + next_function) * step / 6;
            x += step;
        }

        eps = abs(n_square - n_prev_square);
        number_of_steps *= 2;
        step = length / number_of_steps;
    }
    output(n_square, eps, number_of_steps);
}


void three_eighths_integral(long double a, long double b, long double acc, Formula formula) {
    long double eps = 1;
    long double number_of_steps = 2;
    long double length = b - a;
    long double step = length / number_of_steps;
    long double x = 0;
    long double function;
    long double next_function;
    long double sec_function;
    long double third_function;
    long double n_square = 0;
    long double n_prev_square = 0;

    while (eps > acc) {
        x = 0;
        n_prev_square = n_square;
        n_square = 0;
        for (int i = 1; i < number_of_steps; i++) {
            function = formula(x);
            sec_function = formula(x + step / 4);
            third_function = formula(x + 3 * step / 4);
            next_function = formula(x + step);

            n_square = n_square + step * (function + sec_function * 3 + third_function * 3 + next_function) / 8;
            x += step;
        }

        eps = abs(n_square - n_prev_square);
        number_of_steps *= 2;
        step = length / number_of_steps;
    }
    output(n_square, eps, number_of_steps);
}
#pragma endregion

#pragma region formulas

long double integral1(long double x) {
    return x * x + 2;
}
long double integral2(long double x) {
    return x * x + cos(x);
}
long double integral3(long double x) {
    return cos(x);
}
long double integral4(long double x) {
    return cos(x * x);
}
long double integral5(long double x) {
    return sin(x) + 1;
}
long double integral6(long double x) {
    return x + tan(x);
}
long double integral7(long double x) {
    return 2 * x * x;
}
long double integral8(long double x) {
    return sin(x * x);
}
long double integral9(long double x) {
    return tan(x);
}
long double integral10(long double x) {
    return x * x + tan(x);
}

#pragma endregion

const Formula formulas[] = {
    integral1,
    integral2,
    integral3,
    integral4,
    integral5,
    integral6,
    integral7,
    integral8,
    integral9,
    integral10
};

const IntergalMethod imethods[] = {
    left_rect_integral,
    right_rect_integral,
    mid_rect_integral,
    trapez_integral,
    simpson_integral,
    three_eighths_integral
};

int main() {
    setlocale(LC_ALL, "Russian");
    try {
        while (true) {
            system("cls");
            int integral = 0;
            int method = 0;
            long double acc = 1e-6;
            long double a = 0;
            long double b = 1;

            cout <<
                "Выберите интеграл для решения на отрезке от 0 до 1\n"
                "1) integral(x^2+2)\n"
                "2) integral(x^2+cos(x))\n"
                "3) integral(cos(x))\n"
                "4) integral(cos(x^2))\n"
                "5) integral(sin(x) + 1)\n"
                "6) integral(x + tg(x))\n"
                "7) integral(2*x^2)\n"
                "8) integral(sin(x^2))\n"
                "9) integral(tg(x))\n"
                "10) integral(x^2+tg(x))\n"
                "Для выбора введите число, соответствуюшее интегралу, который вы хотите решить" << endl;

            while (integral < 1 || integral > 10) {
                cin >> integral;
            }

            cout << endl;

            cout <<
                "Выберите метод приближенного вычисления определенных интеграллов\n"
                "1) Метод левых прямоугольников\n"
                "2) Метод правых прямоугольников\n"
                "3) Метод средних прямоугольников\n"
                "4) Метод трапеций\n"
                "5) Метод Симпсона\n"
                "6) Метод 3/8\n"
                "Для выбора введите число, соответствуюшее методу, который вы хотите использовать" << endl;

            while (method < 1 || method > 6) {
                cin >> method;
            }

            imethods[method - 1](a, b, acc, formulas[integral - 1]);
        }
    }
    catch (...) {
        cout << "Что-то не так";
    }
}