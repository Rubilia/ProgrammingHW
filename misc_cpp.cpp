#include <iostream>
#include <cmath>


void task1() {
    for (int i = 0; i < 255; i++)
    {
        std::cout << (unsigned char)i;
    }
}

void task2() {
    double a, b, c, x1, x2, D, realPart, imaginaryPart;
    std::cout << "Enter a: ";
    std::cin >> a;
    std::cout << "Enter b: ";
    std::cin >> b;
    std::cout << "Enter c: ";
    std::cin >> c;
    D = b * b - 4 * a * c;

    if (D > 0) {
        std::cout << "x1 = " << (-b + sqrt(D)) / (2 * a) << std::endl;
        std::cout << "x2 = " << (-b - sqrt(D)) / (2 * a) << std::endl;
    }

    else if (D == 0) {
        std::cout << "x1 = x2 =" << -b / (2 * a) << std::endl;
    }

    else {
        std::cout << "x1 = " << -b / (2 * a) << "+" << sqrt(-D) / (2 * a) << "i" << std::endl;
        std::cout << "x2 = " << -b / (2 * a) << "-" << sqrt(-D) / (2 * a) << "i" << std::endl;
    }
}

void task3() {
    double R, r, x, y;
    std::cout << "Enter R: ";
    std::cin >> R;
    std::cout << "Enter r: ";
    std::cin >> r;

    std::cout << "Enter x: ";
    std::cin >> x;
    std::cout << "Enter y: ";
    std::cin >> y;

    if ((x * x + y * y <= R * R) && (x * x + y * y >= r * r))
        std::cout << "Point is inside" << std::endl;
    else
        std::cout << "Point is not inside" << std::endl;
}

void task4() {
    double x, eps, s = 0., pow = 1.;
    std::cout << "Enter eps: ";
    std::cin >> eps;
    std::cout << "Enter x: ";
    std::cin >> x;

    while (pow > eps)
    {
        s += pow;
        pow *= x;
    }

    std::cout << "Series value: " << s << std::endl;
    std::cout << "Function value: " << 1/(1-x) << std::endl;
}

void task5() {
    double a, b, c, d, x;
    std::cout << "Enter A: ";
    std::cin >> a;
    std::cout << "Enter B: ";
    std::cin >> b;
    std::cout << "Enter C: ";
    std::cin >> c;
    std::cout << "Enter D: ";
    std::cin >> d;
    std::cout << "Enter x: ";
    std::cin >> x;

    std::cout << "y = " << b + (x - a) * (d - b) / (c - a) << std::endl;
}

bool compute_f(double x, double y) {
    return ((x * x + y * y - 1) * (x * x + y * y - 1) * (x * x + y * y - 1) - x * x * y * y * y <= 0);

}


void task6() {
    for (int y = 20; y >= 0; y--)
    {
        for (int x = 0; x < 41; x++)
        {
            if (compute_f(-1.5 + 3. / 40. * (double)x, -1.5 + 3. / 20. * (double)y))
                std::cout << "*";
            else
                std::cout << ".";
        }
        std::cout << std::endl;
    }
}

int compute_r2(int n) {
    int r_2 = 0;

    for (int d = 1; d <= n; d += 2)
    {
        if (n % d == 0)
            r_2 += d % 4 == 1 ? 1 : -1;
    }
    return r_2 * 4;
}


void task7() {
    int R, n = 1;
    std::cout << "Enter R: ";
    std::cin >> R;

    for (int i = 1; i <= R * R; i++)
    {
        n += compute_r2(i);
    }
    std::cout << n << std::endl;
}

void task8() {
    for (int n = 1; n <= 100; n++)
    {
        if (n % 15 == 0)
            std::cout << "FooBar" << std::endl;
        else if (n % 5 == 0)
            std::cout << "Bar" << std::endl;
        else if (n % 3 == 0)
            std::cout << "Foo" << std::endl;
        else
            std::cout << n << std::endl;
    }
}


int main() {
    task8();
	return 0;
}