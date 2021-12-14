#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include <vector>
#include <iostream>


template <typename T>
void print_arr(T arr, int n, int m, bool align = false)
{
    for (int l = 0; l < n; l++)
    {
        for (int i = 0; i < m; i++)
        {
            if (!align)
                std::cout << arr[l][i] << " ";
            else
                std::cout << arr[l][i] << "\t";
        }
        std::cout << std::endl;
    }
}


std::vector<std::vector<int>> task1() {
    int n, m, val = 1;
    std::cout << "Input n: ";
    std::cin >> n;
    std::cout << "Input m: ";
    std::cin >> m;

    std::vector<std::vector<int>> ret(n);

    for (int i = 0; i < n; i++)
    {
        std::vector<int> line(m);
        for (int pos = (i % 2 == 0) ? 0 : m - 1; (i % 2 == 0) ? pos < m : pos >= 0; pos += 1 - 2 * ((i) % 2), val++)
        {
            line.at(pos) = val;
        }
        ret.at(i) = line;
    }

    return ret;
}


std::vector<std::vector<int>> task2() {
    srand(time(0));
    int n, m;
    std::cout << "Input n: ";
    std::cin >> n;
    std::cout << "Input m: ";
    std::cin >> m;

    std::vector<std::vector<int>> ret(n);
    for (int i = 0; i < n; i++)
    {
        std::vector<int> line(m);
        for (int pos = 0; pos < m; pos++)
        {
            line.at(pos) = rand() % 100000;
        }
        ret.at(i) = line;
    }
    print_arr(ret, n, m, true);
    return ret;
}


void snakeArray(int** A, int n, bool forward_fill=true) {
    int val = forward_fill ? 1 : n * n;;
    for (int i = 0; i < n; i++)
    {
        for (int pos = (i % 2 == 0) ? 0 : n - 1; (i % 2 == 0) ? pos < n : pos >= 0; pos += 1 - 2 * ((i) % 2), val+= forward_fill? 1: -1)
        {
            A[i][pos] = val;
        }
    }
}

double mysqrt(double x, double eps = 1e-6) {
    double z_n = 1., z_previous = 0.;
    while (abs(z_n - z_previous) > eps)
    {
        z_previous = z_n;
        z_n = z_previous - (z_previous * z_previous - x) / (2 * z_previous);
    }
    return z_n;
}


std::vector<std::vector<int>> fill_cycle(std::vector<std::vector<int>>& arr, int a, int& val, bool spiral_direction) {
    int n = arr.size(), m = arr[0].size();
    if (spiral_direction) {
        for (int y = a; y < m - a; y++, val++)
            arr[a][y] = val;
        for (int x = a + 1; x < n - a; x++, val++)
            arr[x][m - a - 1] = val;
        for (int y = m - a - 2; y >= a; y--, val++)
            arr[n - a - 1][y] = val;
        for (int x = n - a - 2; x > a; x--, val++)
            arr[x][a] = val;
    }
    else {
        for (int x = a; x < n - a; x++, val++)
            arr[x][a] = val;
        for (int y = a + 1; y < m - a; y++, val++)
            arr[n - a - 1][y] = val;
        for (int x = n - a - 2; x >= a; x--, val++)
            arr[x][m - a - 1] = val;
        for (int y = m - a - 2; y > a; y--, val++)
            arr[a][y] = val;
    }
    return arr;
}

void task5(bool spiral_direction=true) {
    int n, m, val = 1;
    std::cout << "Input n: ";
    std::cin >> n;
    std::cout << "Input m: ";
    std::cin >> m;

    std::vector<std::vector<int>> ret(n, std::vector<int>(m, 0));
    int a = 0;
    for (a = 0; a < ((m >= n)? n : m) / 2; a++)
    {
        ret = fill_cycle(ret, a, val, spiral_direction);
    }

    int min = (m < n) ? m : n;
    if (min % 2 == 1) {
        if (n < m)
            for (int y = a; y < m - a; y++, val++)
                ret[a][y] = val;
        else
            for (int x = a; x < n - a; x ++, val++)
                ret[x][a] = val;
    }

    print_arr(ret, n, m, true);
}


std::vector<std::vector<int>> task6() {
    return task2();
}


void shiftArray(int A[], int n, int k) {
    k %= n;
    if (k == 0)
        return;
    std::vector<int> tmp(k, 0);
    for (int i = 0; i < k; i++)
    {
        tmp[i] = A[i + n - k];
    }
    for (int i = n - 1; i >= k; i--)
    {
        A[i] = A[i - k];
    }
    for (int i = 0; i < k; i++)
    {
        A[i] = tmp[i];
    }
}


int min(int a, int b) {
    return (a > b) ? b : a;
}

void task8(bool direction=true) {
    int n, m, val = 1;
    std::cout << "Input n: ";
    std::cin >> n;
    std::cout << "Input m: ";
    std::cin >> m;

    std::vector<std::vector<int>> ret(n, std::vector<int>(m, 0));


    for (int s = 0; s <= n + m - 2; s++)
    {
        if ((s % 2 == 0 && direction) || (s % 2 == 1 && !direction))
            for (int a = min(n - 1, s), b = s - min(n - 1, s); b <= min(m - 1, s); a--, b++, val++)
                ret[a][b] = val;
        else
            for (int b = min(m - 1, s), a = s - min(m - 1, s); a <= min(n - 1, s); b--, a++, val++)
                ret[a][b] = val;
    }

    print_arr(ret, n, m, true);
}

// Задачи codeforces в отдельной папке

int main()
{
    return 0;
}
