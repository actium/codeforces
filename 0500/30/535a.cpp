#include <iostream>
#include <string>

void answer(const std::string& v)
{
    std::cout << v << '\n';
}

void solve(unsigned s)
{
    constexpr const char* b[20] = {
        "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten",
        "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"
    };
    constexpr const char* t[8] = {
        "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"
    };

    if (s < 20)
        return answer(b[s]);

    std::string x = t[(s - 20) / 10];
    if (s % 10 != 0) {
        x.push_back('-');
        x.append(b[s % 10]);
    }
    answer(x);
}

int main()
{
    unsigned s;
    std::cin >> s;

    solve(s);

    return 0;
}

