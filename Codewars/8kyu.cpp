#include <string>
#include <cmath>


// Grasshopper - Summation
int summation(int num) {
	return num * (num + 1) / 2;
}

// Basic Mathematical Operations
int basicOp(char op, int val1, int val2) {
    if (op == '+')
        return val1 + val2;
    else if (op == '-')
        return val1 - val2;
    else if (op == '*')
        return val1 * val2;
    else
        return val1 / val2;
}

// Century From Year
int centuryFromYear(int year)
{
    if (year % 100 == 0)
        return year / 100;
    else
        return year / 100 + 1;
}

// Even or Odd
std::string even_or_odd(int number)
{
    return (abs(number) % 2 == 0) ? "Even" : "Odd";
}

template <typename T>
void swap(T& a, T& b) {
    T c = a;
    a = b;
    b = c;
}

// Reversed Strings
std::string reverseString(std::string& str)
{
    int m = str.length() / 2;

    for (size_t i = 0; i < m; i++)
    {
        swap(str.at(i), str.at(str.length() - 1 - i));
    }
    return str;
}

// Remove String Spaces
std::string no_space(std::string x)
{
    std::string ret = "";
    int n = x.size();
    for (int i = 0; i < n; ++i) {
        if (x.at(i) != ' ')
            ret += x.at(i);
    }
    return ret;
}

// Convert a Number to a String!
std::string number_to_string(int num) {
    return std::to_string(num);
}

// Opposite number
int opposite(int number)
{
    return -number;
}

// Convert boolean values to strings 'Yes' or 'No'.
std::string bool_to_word(bool value)
{
    if (value)
        return "Yes";
    else
        return "No";
}

// Twice as old
int twice_as_old(int dad, int son) {
    return abs(2 * son - dad);
}

int main() {
	return 0;
}