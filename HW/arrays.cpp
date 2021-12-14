#include <iostream>
#include <cmath>


void task1() {
    int h1, m1, s1, h2, m2, s2, diff = 0;
    std::cout << "Enter hours: ";
    std::cin >> h1;
    std::cout << "Enter minutes: ";
    std::cin >> m1;
    std::cout << "Enter seconds: ";
    std::cin >> s1;

    std::cout << "Enter hours: ";
    std::cin >> h2;
    std::cout << "Enter minutes: ";
    std::cin >> m2;
    std::cout << "Enter seconds: ";
    std::cin >> s2;

    diff = 3600 * (h1 - h2) + 60 * (m1 - m2) + (s1 - s2);
    std::cout << "Time difference: " << diff / 3600 << ":" << (diff / 60) % 60 << ":" << diff % 60 << std::endl;
}

double task2() {
    double c[] = { -5., 13., -19. };
    int N = 2;

    double x, f = 0.;
    std::cout << "Enter x: ";
    std::cin >> x;
    f = c[N];
    for (int i = N-1; i >= 0; i--)
    {
        f = f * x + c[i];
    }
    return f;
}

void task3_one() {
    int n, base = 16, len = 0, t;
    std::cout << "Enter n: ";
    std::cin >> n;
    int a = 1;

    while (a <= n) {
        a *= base;
        len++;
    }
    t = len - 1;
    char *base16 = new char[len];

    while (n > 0) {
        int d = n % base;
        if (d > 0) {
            if (d == 0)
                base16[t] = '0';
            else if (d < 10)
                base16[t] = (char)((d - 1) + '1');
            else if (d >= 10)
                base16[t] = (char)('A' + d - 10);
            n %= a;
            t += 1;
        }
        else
            base16[t] = '0';
        t--;
        n /= base;
    }
}

void task3_two() {
    int len = 3, result = 0;
    char base16[3] = {'A', '0', 'B'};

    for (int i = 0; i < len; i++)
    {
        result *= 16;
        if ('1' <= base16[i] && base16[i] <= '9')
            result += (base16[i] - '1');
        else if ('A' <= base16[i] && base16[i] <= 'F')
            result += (base16[i] - 'A') + 10;
    }
    std::cout << result << std::endl;
}


void task4() {
    int N = 7;
    int A[7] = {1, 2, 3, 4, 5, 6, 7};

    for (int i = 0; i < N / 2; i++)
    {
        std::cout << A[i] << ", " << A[N - i - 1] << ", ";
    }
    if (N % 2 == 1)
        std::cout << A[N / 2];
    std::cout << std::endl;
}


void task5() {
    int N = 7, S_m, i_max = 0;
    int A[7] = { 1, 2, 3, 4, 5, 6, 7 };
    S_m = A[0] + A[1];

    for (int i = 0; i < N - 1; i++)
    {
        if (A[i] + A[i + 1] > S_m) {
            S_m = A[i] + A[i + 1];
            i_max = i;
        }
    }
    std::cout << "Max: " << A[i_max] << ", " << A[i_max + 1] << std::endl;
}


void task6() {
    int d, N = 7;
    int A[7] = { 1, 2, 3, 4, 5, -6, 7 };
    d = A[1] - A[0];

    if (N < 3) {
        std::cout << "No" << std::endl;
        return;
    }

    for (int i = 1; i < N - 1; i++)
    {
        if (A[i + 1] - A[i] != d) {
            std::cout << "No" << std::endl;
            return;
        }
    }
    std::cout << "Yes" << std::endl;

}

inline int special_mod(int room, int section) {
    int in_block = room - section * (section + 1) * (2 * section + 1) / 6, mod = section + 1;
    return (in_block - 1) / mod + 1;
}

void task7() {
    int section = 1, f = 1, room;
    std::cout << "Enter room number: ";
    std::cin >> room;

    if (room == 1) {
        std::cout << "Floor: 1, Number from left: 1" << std::endl;
        return;
    }

    while (f < room)
    {
        section += 1;
        f = section * (section + 1) * (2 * section + 1) / 6;
    }
    section -= 1;

    int floor_number = section * (section + 1) / 2 + special_mod(room, section);
    int room_num = (room - section * (section + 1) * (2 * section + 1) / 6 - 1) % (section + 1) + 1;

    std::cout << "Floor: " << floor_number << ", Number from left : " << room_num << std::endl;
}

inline void f(int n, bool b = true) {
    switch (n / 100)
    {
    case 1:
        std::cout << "сто ";
        break;
    case 2:
        std::cout << "двести ";
        break;
    case 3:
        std::cout << "триста ";
        break;
    case 4:
        std::cout << "четыреста ";
        break;
    case 5:
        std::cout << "п€тьсот ";
        break;
    case 6:
        std::cout << "шестьсот ";
        break;
    case 7:
        std::cout << "семьсот ";
        break;
    case 8:
        std::cout << "восемьсот ";
        break;
    case 9:
        std::cout << "дев€тьсот ";
        break;
    default:
        break;
    }
    n %= 100;
    if (n >= 10 && n <= 19) {
        switch (n)
        {
        case 10:
            std::cout << "дес€ть ";
            break;
        case 11:
            std::cout << "одинадцать ";
            break;
        case 12:
            std::cout << "двенадцать ";
            break;
        case 13:
            std::cout << "тринадцать ";
            break;
        case 14:
            std::cout << "четырнадцать ";
            break;
        case 15:
            std::cout << "п€тнадцать ";
            break;
        case 16:
            std::cout << "шестнадцать ";
            break;
        case 17:
            std::cout << "семнадцать ";
            break;
        case 18:
            std::cout << "восемнадцать ";
            break;
        case 19:
            std::cout << "дев€тнадцать ";
            break;
        default:
            break;
        }
        return;
    }

    switch ((n / 10) % 10)
    {
    case 2:
        std::cout << "двадцать ";
        break;
    case 3:
        std::cout << "тридцать ";
        break;
    case 4:
        std::cout << "сорок ";
        break;
    case 5:
        std::cout << "п€тьдес€т ";
        break;
    case 6:
        std::cout << "шестьдес€т ";
        break;
    case 7:
        std::cout << "семьдес€т ";
        break;
    case 8:
        std::cout << "восемьдес€т ";
        break;
    case 9:
        std::cout << "дев€носто ";
        break;
    default:
        break;
    }
    n %= 10;

    switch (n % 10)
    {
    case 1:
        if (b)
            std::cout << "один ";
        else
            std::cout << "одна ";
        break;
    case 2:
        if (b)
            std::cout << "два ";
        else
            std::cout << "две ";
        break;
    case 3:
        std::cout << "три ";
        break;
    case 4:
        std::cout << "четыре ";
        break;
    case 5:
        std::cout << "п€ть ";
        break;
    case 6:
        std::cout << "шесть ";
        break;
    case 7:
        std::cout << "семь ";
        break;
    case 8:
        std::cout << "восемь ";
        break;
    case 9:
        std::cout << "дев€ть ";
        break;
    default:
        break;
    }
}



void task8() {
    int N;
    std::cout << "Enter N: ";
    std::cin >> N;
    if (N == 1000000000) {
        std::cout << "один миллиард" << std::endl;
        return;
    }

    if (N >= 1000000) {
        int m = N / 1000000;
        if (m > 0) {
            f(m);
            if (m == 11)
                std::cout << "миллионов ";
            else if (m % 10 == 1)
                std::cout << "миллион ";
            else if ((m % 10 == 2 || m % 10 == 3 || m % 10 == 4) && (m / 10 != 1))
                std::cout << "миллионa ";
            else
                std::cout << "миллионов ";
        }
    }
    N = N % 1000000;

    if (N >= 1000) {
        int t = N / 1000;
        if (t > 0) {
            f(t, false);
            if (t == 11)
                std::cout << "тыс€ч ";
            else if (t % 10 == 1)
                std::cout << "тыс€ча ";
            else if ((t % 10 == 2 || t % 10 == 3 || t % 10 == 4) && (t / 10 != 1))
                std::cout << "тыс€чи ";
            else
                std::cout << "тыс€ч ";
        }
    }
    N = N % 1000;


    if (N > 0) {
        f(N);
        std::cout << std::endl;
    }

}

void task9() {
    int N = 8;
    int A[8] = { 1, 2, 3, 4, 5, 6, 7, 0};

    int s = 0;
    for (int i = 0; i < N; i++)
    {
        s += A[i];
    }
    std::cout << N * (N + 1) / 2 - s << std::endl;
}


int main() {
    task8();
	return 0;
}