#include <iostream>
#include <cmath>


void task1() {
    int n;
    std::cout << "Enter n: ";
    std::cin >> n;

    for (int i = 1; i < n+1; i++)
    {
        for (int j = 0; j < i; j++)
        {
            std::cout << "*";
        }
        std::cout << std::endl;
    }
}


void task2() {
    int h;
    std::cout << "Enter h: ";
    std::cin >> h;
    for (int i = 0; i < h; i++)
    {
        int stars = 2 * i + 1;
        for (int j = 0; j < 2 * h + 1; j++)
        {
            if (j < h - i || j > h + i)
                std::cout << " ";
            else
                std::cout << "*";
        }
        std::cout << std::endl;
    }
}

void task3() {
    int h;
    std::cout << "Enter h/2: ";
    std::cin >> h;
    for (int i = 0; i < h; i++)
    {
        int stars = 2 * i + 1;
        for (int j = 0; j < 2 * h + 1; j++)
        {
            if (j < h - i || j > h + i)
                std::cout << " ";
            else
                std::cout << "*";
        }
        std::cout << std::endl;
    }

    for (int i = h; i >= 0; i--)
    {
        int stars = 2 * i + 1;
        for (int j = 0; j < 2 * h + 1; j++)
        {
            if (j < h - i || j > h + i)
                std::cout << " ";
            else
                std::cout << "*";
        }
        std::cout << std::endl;
    }
}


void task4() {
    int h, rombs;
    std::cout << "Enter h/2: ";
    std::cin >> h;
    std::cout << "Enter number: ";
    std::cin >> rombs;
    for (int i = 0; i < h; i++)
    {
        int stars = 2 * i + 1;
        for (int k = 0; k < rombs; k++)
        {
            for (int j = 0; j < 2 * h + 1; j++)
            {
                if (j < h - i || j > h + i)
                    std::cout << " ";
                else
                    std::cout << "*";
            }
        }
        std::cout << std::endl;
    }

    for (int i = h; i >= 0; i--)
    {
        int stars = 2 * i + 1;
        for (int k = 0; k < rombs; k++)
        {
            for (int j = 0; j < 2 * h + 1; j++)
            {
                if (j < h - i || j > h + i)
                    std::cout << " ";
                else
                    std::cout << "*";
            }
        }
        std::cout << std::endl;
    }
}


void task5() {
    int h;
    std::cout << "Enter h: ";
    std::cin >> h;
    for (int i = 0; i < h; i++)
    {
        int stars = 2 * i + 1, s = 1;
        for (int j = 0; j < 2 * h + 1; j++)
        {
            if (j < h - i || j > h + i)
                std::cout << " ";
            else {
                if (s == 1)
                    std::cout << "*";
                else 
                    std::cout << " ";
                s *= -1;
            }
        }
        std::cout << std::endl;
    }

    for (int i = h; i >= 0; i--)
    {
        int stars = 2 * i + 1, s = 1;
        for (int j = 0; j < 2 * h + 1; j++)
        {
            if (j < h - i || j > h + i)
                std::cout << " ";
            else {
                if (s == 1)
                    std::cout << "*";
                else
                    std::cout << " ";
                s *= -1;
            }
        }
        std::cout << std::endl;
    }
}

void task6() {
    int h;
    std::cout << "Enter h/2: ";
    std::cin >> h;
    for (int i = 0; i < h; i++)
    {
        int stars = 2 * i + 1;
        for (int j = 0; j < 2 * h + 1; j++)
        {
            if (j == h - i || j == h + i)
                std::cout << "*";
            else
                std::cout << " ";
        }
        std::cout << std::endl;
    }

    for (int i = h; i >= 0; i--)
    {
        int stars = 2 * i + 1;
        for (int j = 0; j < 2 * h + 1; j++)
        {
            if (j == h - i || j == h + i)
                std::cout << "*";
            else
                std::cout << " ";
        }
        std::cout << std::endl;
    }
}


int main() {
    task6();
	return 0;
}