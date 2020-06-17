#include <algorithm>
#include <iostream>
#include <string>

void answer(const std::string& v)
{
    std::cout << v << '\n';
}

void solve(const std::string& s)
{
    std::string digits;
    for (const char c : s) {
        if (isdigit(c))
            digits.push_back(c);
    }

    std::sort(digits.begin(), digits.end());

    std::string sum;
    for (const char d : digits) {
        sum.push_back(d);
        sum.push_back('+');
    }
    sum.pop_back();

    answer(sum);
}

int main()
{
    std::string s;
    std::cin >> s;

    solve(s);

    return 0;
}

