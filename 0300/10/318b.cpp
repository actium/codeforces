#include <iostream>
#include <string>

using integer = unsigned long long;

void answer(integer v)
{
    std::cout << v << '\n';
}

void solve(const std::string& s)
{
    const size_t n = s.length();

    const auto check = [&s](size_t i, const char* w) {
        for (size_t d = 0; d < 5; ++d) {
            if (s[i+d] != w[d])
                return false;
        }
        return true;
    };

    integer h = 0, k = 0;
    for (size_t i = 0; i + 4 < n; ++i) {
        if (check(i, "heavy")) {
            ++h;
            i += 4;
        } else if (check(i, "metal")) {
            k += h;
            i += 4;
        }
    }

    answer(k);
}

int main()
{
    std::string s;
    std::cin >> s;

    solve(s);

    return 0;
}

