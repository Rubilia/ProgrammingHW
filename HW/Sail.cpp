#include <iostream>
#include <cmath>


void sail() {
    double x, y;
    std::cout << "Enter x: ";
    std::cin >> x;
    std::cout << "Enter y: ";
    std::cin >> y;

    if (y < 0 && (((x - 1) * (x - 1) + y * y <= 1)) || ((x + 1) * (x + 1) + y * y <= 1))
        std::cout << "Point is inside the sail" << std::endl;
    else if (y >= 0 && (y <= 2 - x * 2.) && (y <= 2 + 2 * x))
        std::cout << "Point is inside the sail" << std::endl;
    else
        std::cout << "Point is not inside the sail" << std::endl;
}

int main()
{
    sail();
    return 0;
}

