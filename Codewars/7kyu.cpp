#include <string>
#include <cmath>
#include <vector>
#include <algorithm>


// Reverse words
std::string reverseString(std::string str) {
    int n = str.length();
    std::string reverse = "";
    for (int i = n - 1; i >= 0; i--)
    {
        reverse += str.at(i);
    }
    return reverse;
}

std::string reverse_words(std::string str)
{
    std::string modification = "", word = "";
    int n = str.length();
    bool is_word = false;

    for (int i = 0; i < n; i++)
    {
        int b = (int)str.at(i);
        if (b != ' ') {
            word += str.at(i);
            is_word = true;
        }
        else {
            if (is_word) {
                is_word = false;
                modification += reverseString(word);
                word = "";
            }
            modification += str.at(i);
        }
    }
    if (is_word) {
        modification += reverseString(word);
    }
    return modification;
}


// Get the Middle Character
std::string get_middle(std::string input)
{
    int n = input.size();
        int m = (n - 1) / 2;
    std::string ret = "";

    if (n % 2 == 1)
        ret = input.at(m);
    else {
        ret = input.at(m);
        ret += input.at(m + 1);
    }
    return ret;
}


// Exes and Ohs
bool XO(const std::string& str)
{
    int x = 0, o = 0;
    for (int i = 0; i < str.size(); i++)
    {
        if (str.at(i) == 'o' || str.at(i) == 'O')
            o++;
        else if (str.at(i) == 'x' || str.at(i) == 'X')
            x++;
    }

    return (o == x);
}


// Complementary DNA
std::string DNAStrand(const std::string& dna)
{
    std::string ret = "";
    for (int i = 0; i < dna.size(); i++)
    {
        switch (dna.at(i))
        {
        case 'A':
            ret += "T";
            break;
        case 'T':
            ret += "A";
            break;
        case 'G':
            ret += "C";
            break;
        case 'C':
            ret += "G";
        }
    }
    return ret;
}


// Isograms
char asciitolower(char in) {
    if (in <= 'Z' && in >= 'A')
        return in - ('Z' - 'z');
    return in;
}

bool is_isogram(std::string str) {
    std::string w = "";
    for (int i = 0; i < str.length(); i++)
    {
        w += asciitolower(str.at(i));
    }

    for (int i = 0; i < w.length(); i++)
    {
        char c = w.at(i);
        int counter = 0;
        for (int j = 0; j < w.length(); j++)
        {
            if ((int)c == (int)w.at(j))
                counter++;
        }
        if (counter > 1)
            return false;
    }
    return true;
}


// Anagram Detection
bool isAnagram(std::string test, std::string original) {
    int n1 = test.length();
    int n2 = original.length();

    if (n1 != n2)
        return false;

    for (char& c : test)
        c = std::tolower(c);
    for (char& c : original)
        c = std::tolower(c);

    std::sort(test.begin(), test.end());
    std::sort(original.begin(), original.end());

    for (int i = 0; i < n1; i++)
        if (test[i] != original[i])
            return false;
    return true;
}


// Are the numbers in order?
bool isAscOrder(std::vector<int> arr)
{
    for (int i = 1; i < arr.size(); i++)
    {
        if (arr.at(i) < arr.at(i - 1))
            return false;
    }
    return true;

}


// Shortest Word
int find_short(std::string str)
{
    int min_l = str.size(), current_l = 0;

    for (int i = 0; i < str.size(); i++)
    {
        if (str.at(i) != ' ')
            current_l += 1;
        else {

            if (current_l > 0 && min_l > current_l)
                min_l = current_l;
            current_l = 0;
        }
    }
    if (min_l > current_l)
        return current_l;
    return min_l;
}


// Sum of two lowest positive integers
long min(long a, long b) {
    return a > b ? b : a;
}

long max(long a, long b) {
    return a + b - min(a, b);
}

long sumTwoSmallestNumbers(std::vector<int> numbers)
{
    long first_min = min(numbers.at(0), numbers.at(1)), second_min = max(numbers.at(0), numbers.at(1));
    for (size_t i = 2; i < numbers.size(); i++)
    {
        if (numbers.at(i) < first_min) {
            second_min = first_min;
            first_min = numbers.at(i);
        }
        else if (numbers.at(i) < second_min)
            second_min = numbers.at(i);
    }
    return first_min + second_min;
}


// You're a square!
bool is_square(int n)
{
    if (n >= 0) {

        long long sr = sqrt(n);

        return (sr * sr == n);
    }
    return false;
}

int main() {
    isAnagram("foefet", "toffee");
    return 0;
}