#include <string>
#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>


// Count the smiley faces!
int countSmileys(std::vector<std::string> arr)
{
    int counter = 0;
    for (size_t i = 0; i < arr.size(); i++)
    {
        if (arr.at(i).size() == 2) {
            counter += (arr.at(i).at(0) == ':' || arr.at(i).at(0) == ';') && (arr.at(i).at(1) == ')' || arr.at(i).at(1) == 'D') ? 1 : 0;
        }
        else if (arr.at(i).size() == 3) {
            counter += (arr.at(i).at(0) == ':' || arr.at(i).at(0) == ';') && (arr.at(i).at(1) == '-' || arr.at(i).at(1) == '~') && (arr.at(i).at(2) == ')' || arr.at(i).at(2) == 'D') ? 1 : 0;
        }
    }
    return counter;
}


// Bit Counting
unsigned int countBits(unsigned long long n) {
    unsigned int counter = 0;
    while (n > 0)
    {
        counter += n % 2;
        n /= 2;
    }
    return counter;
}


// Find the missing term in an Arithmetic Progression
static long findMissing(std::vector<long> list) {
    if (abs(list.at(1) - list.at(0)) > abs(list.at(2) - list.at(1)))
        return  list.at(0) + (list.at(2) - list.at(1));
    long d = list.at(1) - list.at(0);

    for (int i = 0; i < list.size() - 1; i++)
    {
        if (d != list.at(i + 1) - list.at(i))
            return list.at(i) + d;
    }
}


// Create Phone Number
std::string createPhoneNumber(const int arr[10]) {
    std::string phone = "(";
    phone += std::to_string(arr[0]) + std::to_string(arr[1]) + std::to_string(arr[2]) + ") " + std::to_string(arr[3]) + std::to_string(arr[4]) + std::to_string(arr[5]) + '-' + std::to_string(arr[6]) + std::to_string(arr[7]) + std::to_string(arr[8]) + std::to_string(arr[9]);
    return phone;
}


// Duplicate Encoder
std::string duplicate_encoder(const std::string& word) {
    std::string word_lower = "";
    for (char c : word)
        word_lower += std::tolower(c);

    std::string s = "";
    for (int i = 0; i < word.length(); i++)
    {
        if (std::count(word_lower.begin(), word_lower.end(), word_lower.at(i)) > 1)
            s += ")";
        else
            s += "(";
    }
    return s;
}


// Sum of Digits / Digital Root
int digital_root(int n)
{
    if (n == 0)
        return 0;
    if (n % 9 == 0)
        return 9;
    return n % 9;
}


// Tribonacci Sequence
std::vector<int> tribonacci(std::vector<int> signature, int n)
{
    std::vector<int> ret = {};
    if (n == 0)
        return ret;
    ret.push_back(signature.at(0));
    if (n == 1)
        return ret;
    ret.push_back(signature.at(1));
    if (n == 2)
        return ret;
    ret.push_back(signature.at(2));
    if (n == 3)
        return ret;

    for (int i = 3; i < n; i++)
    {
        ret.push_back(ret.at(i - 1) + ret.at(i - 2) + ret.at(i - 3));
    }
    return ret;
}


// Does my number look big in this?
bool narcissistic(int value) {
    int power = std::to_string(value).length(), sum = 0, n = value;
    while (value > 0)
    {
        sum += pow(value % 10, power);
        value /= 10;

    }
    return sum == n;
}


// 1/n- Cycle
int cycle(int n) {
    if (n % 2 == 0 || n % 5 == 0)
        return -1;
    int m = 0, n_div = 10;

    do
    {
        m += 1;
        n_div = (n_div % n) * 10;
        if (n_div == 10)
            return m;
    } while (true);
}


// A disguised sequence (I)
class HiddenSeq
{
public:
    static unsigned long long fcn(int n) {
        if (n == 0)
            return 1;
        return (long long)1 << n;
    }
};


int main() {
    duplicate_encoder("recede");
    return 0;
}