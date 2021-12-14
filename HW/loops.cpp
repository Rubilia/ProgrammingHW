#include <iostream>
#include <cmath>


void task1() {
    int n;
    std::cout << "Enter n: ";
    std::cin >> n;

    double s = 0.;

    for (int i = 0; i < n; i++)
    {
        s += 1 / ((float)i + 1);
    }
    std::cout << s << std::endl;
}

void task2() {
    int n;
    std::cout << "Enter n: ";
    std::cin >> n;

    double s = 0., a = 1.;

    for (int i = 0; i < n; i++)
    {
        s += a;
        a /= 2.;
    }
    std::cout << s << std::endl;
}

void task3() {
    int n;
    std::cout << "Enter n: ";
    std::cin >> n;

    double s = 0., a, x;

    std::cout << "Enter x: ";
    std::cin >> x;

    a = x;

    for (int i = 0; i < n; i++)
    {
        a = sin(a);
        s += a;
    }
    std::cout << s << std::endl;
}

void task4() {
    int n = 0;
    double eps, s = 0, sign = 1.;
    std::cout << "Enter eps: ";
    std::cin >> eps;


    while ((1 / ((double) n * 2. + 1)) > eps)
    {
        s += sign / ((double)n * 2. + 1);
        sign *= -1;
        n += 1;
    }
    std::cout << "pi=" << 4. * s << std::endl;
}

double compute_f5(double x, double eps) {
    double s = 0., fact = 1., x_pow = x;
    while (abs(x_pow / fact) > eps)
    {
        s += x_pow / fact;
        x_pow *= -x * x;
        fact *= (fact + 1) * (fact + 2);
    }
    return s;

}

void task5() {
    double x_min, x_max, dx, eps;
    std::cout << "Enter x_min:";
    std::cin >> x_min;
    std::cout << "Enter x_max:";
    std::cin >> x_max;
    std::cout << "Enter dx:";
    std::cin >> dx;
    std::cout << "Enter eps:";
    std::cin >> eps;
    // Computations
    std::cout << "x\t|f(x)\t|sin(x)\t|" << std::endl;
    double x = x_min;
    while (x < x_max)
    {
        std::cout << x << "\t|" << compute_f5(x, eps) << "\t|" << sin(x) << "\t|" << std::endl;
        x += dx;
    }
}


void task6() {
    int n, steps = 0, m;
    std::cout << "Enter n:";
    std::cin >> n;
    m = n;

    while (n > 1)
    {
        if (n % 2 == 0)
            n /= 2;
        else
            n = 3 * n + 1;
        steps += 1;
        if (n > m)
            m = n;
    }
    std::cout << "Steps: " << steps << std::endl;
    std::cout << "Peak: " << m << std::endl;
}

double randd() {
    return (double)rand() / RAND_MAX;
}


void task7() {
    int n;
    std::cout << "Enter n:";
    std::cin >> n;
    double points_in = 0.;
    for (int i = 0; i < n; i++)
    {
        double x = randd(), y = randd();
        points_in += (x * x + y * y) <= 1. ? 1. : 0.;
    }
    std::cout << (points_in / (double)n) << std::endl;
}


void task8() {
    int n;
    std::cout << "Enter n: ";
    std::cin >> n;
    int sum = 0, product = 1;
    while (n > 0)
    {
        sum += n % 10;
        product *= n % 10;
        n /= 10;
    }
    std::cout << "Sum of digits: " << sum << std::endl;
    std::cout << "Product of digits: " << product << std::endl;
}

void task9() {
    int n;
    std::cout << "Enter n: ";
    std::cin >> n;
    int a = 1;
    // Largest 2^(a-1) <= n
    while (a <= n)
        a *= 2;
    std::cout << "N in binary: ";
    while (a > 1)
    {
        a /= 2;
        if (n >= a) {
            std::cout << "1";
            n -= a;
        }
        else
            std::cout << "0";

    }
    std::cout << std::endl;
}

void task10() {
    int n;
    std::cout << "Enter n: ";
    std::cin >> n;
    int a = 1;
    // Largest 16^(a-1) <= n
    while (a <= n)
        a *= 16;
    std::cout << "N in hex: ";
    while (a > 1)
    {
        a /= 16;
        int d = n / a;
        if (d > 0) {
            if (d < 10)
                std::cout << d;
            else if (d == 10)
                std::cout << "A";
            else if (d == 11)
                std::cout << "B";
            else if (d == 12)
                std::cout << "C";
            else if (d == 13)
                std::cout << "D";
            else if (d == 14)
                std::cout << "E";
            else if (d == 15)
                std::cout << "F";
            n %= a;
        }
        else
            std::cout << "0";

    }
    std::cout << std::endl;
}

void task12() {
    int n, base;
    std::cout << "Enter n: ";
    std::cin >> n;
    std::cout << "Enter base: ";
    std::cin >> base;
    int a = 1;

    while (a <= n)
        a *= base;
    std::cout << "N in base " << base << ": ";
    while (a > 1)
    {
        a /= base;
        int d = n / a;
        if (d > 0) {
            if (d < 10)
                std::cout << d;
            else if (d == 10)
                std::cout << "A";
            else if (d == 11)
                std::cout << "B";
            else if (d == 12)
                std::cout << "C";
            else if (d == 13)
                std::cout << "D";
            else if (d == 14)
                std::cout << "E";
            else if (d == 15)
                std::cout << "F";
            n %= a;
        }
        else
            std::cout << "0";

    }
    std::cout << std::endl;
}

void task13() {
    int n;
    std::cout << "Enter n: ";
    std::cin >> n;
    int m = 0, d = 0, c = 0, l = 0, x = 0;
    // Compute thousands
    for (int i = 0; i < n / 1000; i++)
        std::cout << "M";
    n %= 1000;
    // Compute hundreds
    if (n - n % 100 == 900) {
        std::cout << "CM";
        n %= 100;
    }
    else if (n - n % 100 == 400) {
        std::cout << "CD";
        n %= 100;
    }
    else if (n - n % 100 >= 500) {
        std::cout << "D";
        n %= 500;
    }
    // Fill out remaining hundreds
    for (int i = 0; i < n / 100; i++)
        std::cout << "C";
    n %= 100;
    // Compute tens
    if (n - n % 10 == 90) {
        std::cout << "XC";
        n %= 10;
    }
    else if (n - n % 10 == 40) {
        std::cout << "XL";
        n %= 10;
    }
    else if (n - n % 10 >= 50) {
        std::cout << "L";
        n %= 50;
    }
    // Fill out remaining tens
    for (int i = 0; i < n / 10; i++)
        std::cout << "X";
    n %= 10;
    // Compute units
    if (n == 9) {
        std::cout << "IX";
        n = 0;
    }
    else if (n == 4) {
        std::cout << "IV";
        n = 0;
    }
    else if (n >= 5) {
        std::cout << "V";
        n %= 5;
    }
    // Fill out remaining units
    for (int i = 0; i < n; i++)
        std::cout << "I";
    std::cout << std::endl;
}

int main() {
    task12();
	return 0;
}