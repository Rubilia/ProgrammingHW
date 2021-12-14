#include <vector>
#include <string>
#include <cmath>
#include <unordered_map>
#include <algorithm>


// Maximum subarray sum
int maxSequence(const std::vector<int>& arr) {
    if (arr.size() == 0)
        return 0;
    int m = arr.at(0), m_max = arr.at(0);
    for (size_t i = 1; i < arr.size(); i++)
    {
        m = arr.at(i) > (m + arr.at(i)) ? arr.at(i) : m + arr.at(i);
        if (m_max < m)
            m_max = m;
    }
    return m_max < 0 ? 0 : m_max;
}


// Last digit of a large number
inline int mod_full(int a, int b, int mod) {
	while (b > mod)
		b -= mod;
	if (b == 0)
		b = mod;
	int p = 1;
	for (int i = 0; i < b; i++)
	{
		p *= a;
	}
	return p % 10;
}

int last_digit(const std::string& str1, const std::string& str2) {
	if (str2.size() == 1 && str2.at(0) == '0')
		return 1;
	int a = ((char)str1.at(str1.size() - 1) - '0');
	if (a == 0 || a == 1 || a == 5 || a == 6)
		return a;

	int b = ((char)str2.at(str2.size() - 1) - '0');
	if (str2.size() >= 2)
		b += 10 * ((char)str2.at(str2.size() - 2) - '0');

	return mod_full(a, b, 4);
}


// Pick peaks
struct PeakData {
    std::vector<int> pos, peaks;
};

PeakData pick_peaks(std::vector<int> v) {
    PeakData result;
    int peak_cand = 0;
    for (int i = 1; i < (int)v.size(); i++)
        if (v[i] > v[i - 1])
            peak_cand = i;
        else if (peak_cand > 0 && v[i] < v[i - 1]) {
            result.pos.push_back(peak_cand);
            result.peaks.push_back(v[peak_cand]);
            peak_cand = 0;
        }
    return result;
}

// int32 to IPv4
std::string uint32_to_ip(uint32_t ip)
{
	std::string ip_str = "";
	for (int i = 0; i < 4; i++)
	{
		ip_str = std::to_string(ip % 256) + ip_str;
		ip /= 256;
		if (i != 3)
			ip_str = '.' + ip_str;
	}
	return ip_str;
}


// Simple assembler interpreter
std::vector<std::string> split(std::string str) {
    std::vector<std::string> ret;
    std::string tmp = "";
    for (char c : (str + " ")) {
        if (c != ' ')
            tmp += c;
        else {
            ret.push_back(tmp);
            tmp = "";
        }
    }
    return ret;
}

std::unordered_map<std::string, int> assembler(std::vector<std::string> program) {
    std::unordered_map<std::string, int> reg;
    for (int i = 0; i < program.size(); i++) {
        auto x = program.at(i);
        std::vector<std::string> ins = split(program.at(i));
        std::string cmd = ins.at(0), var = ins.at(1), val = (ins.size() > 2) ? ins.at(2) : "";
        if (cmd == "mov") {
            if (reg.find(val) == reg.end()) reg[var] = stoi(val);
            else reg[var] = reg[val];
        }
        else if (cmd == "inc")
            reg[var] += 1;
        else if (cmd == "dec")
            reg[var] -= 1;
        else if (cmd == "jnz" && (reg.find(var) != reg.end() ? reg[var] : stoi(var)))
            i += stoi(val) - 1;
    }
    return reg;
}


// Simple Pig Latin
std::string pig_it(std::string str)
{
    std::string modification = "", first_letter = "";
    int n = str.length();
    bool is_word = false;

    for (int i = 0; i < n; i++)
    {
        int b = (int)str.at(i);
        if (((int)'a' <= b && b <= (int)'z') || ((int)'A' <= b && b <= (int)'Z')) {
            if (is_word) {
                modification += str.at(i);
            }
            else {
                is_word = true;
                first_letter = str.at(i);
            }
        }
        else {
            if (is_word) {
                is_word = false;
                modification += first_letter + "ay";
                first_letter = "";
            }
            modification += str.at(i);
        }
    }
    if (is_word) {
        modification += first_letter + "ay";
    }
    return modification;
}


// Factorial decomposition
inline bool primeTest(int n) {
    for (int i = 3; i * i <= n; i += 2)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

inline std::string count_p(int p, int n) {
    int power = 0, p_pow = p;
    while (p_pow <= n)
    {
        power += n / p_pow;
        p_pow *= p;
    }
    return (power > 1) ? "^" + std::to_string(power) : "";
}

std::string decomp(int n) {
    std::string ret = "";
    for (int p = 2; p <= n; p += 2)
    {
        if (p != 2 && !primeTest(p))
            continue;
        ret += std::to_string(p) + count_p(p, n) + " * ";
        if (p == 2)
            p--;
    }
    return ret.substr(0, ret.size() - 3);
}


// Rot13
std::string rot13(std::string msg)
{
    for (int i = 0; msg[i] != '\0'; ++i) {
        char& ch = msg[i];

        if (ch >= 'a' && ch <= 'z') {
            if (ch + 13 > 'z')
                ch -= 13;
            else
                ch += 13;
        }

        else if (ch >= 'A' && ch <= 'Z') {
            if (ch + 13 > 'Z')
                ch -= 13;
            else
                ch += 13;
        }
    }
    return msg;
}



// Josephus Permutation
std::vector < int> josephus(std::vector < int > items, int k) {
    std::vector<int> ret;
    std::vector<int> items_;
    for (int i = 0; i < items.size(); i++)
        items_.push_back(i);
    int id = 0;
    while (items_.size() > 0)
    {
        id = (id + k - 1) % items_.size();
        ret.push_back(items.at(items_.at(id)));
        items_.erase(std::next(items_.begin(), id));
    }
    return ret;
}


// Buddy Pairs
namespace Bud
{
    inline long long compute_s(long long n) {
        long long result = 0;
        for (int i = 1; i < sqrt(n) + .5; i++)
        {
            if (n % i != 0)
                continue;
            if (n == i * i)
                result += i;
            else
                result += i + n / i;
        }
        return result - n;
    }

    std::string buddy(long long start, long long limit)
    {
        for (long long i = start; i <= limit; i++)
        {
            long long s = compute_s(i);
            if (s > i + 1) {
                long long s_ = compute_s(s - 1);
                if (s_ - 1 == i)
                    return "(" + std::to_string(i) + " " + std::to_string(s - 1) + ")";
            }
        }
        return "Nothing";
    }
}

int main() {
    return 0;
}