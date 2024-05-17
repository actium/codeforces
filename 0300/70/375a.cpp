#include <algorithm>
#include <iostream>
#include <string>

void answer(const std::string& x)
{
    std::cout << x << '\n';
}

void no_answer()
{
    std::cout << 0 << '\n';
}

void solve(std::string& s)
{
    std::string p = "1689";
    for (const char c : p) {
        size_t x = 0;
        while (s[x] != c)
            ++x;

        s[x] = s.back();
        s.pop_back();
    }

    std::sort(s.begin(), s.end(), std::greater<char>());

    unsigned z = 0;
    while (!s.empty() && s.back() == '0') {
        ++z;
        s.pop_back();
    }

    const auto process = [](unsigned r, const std::string& q) {
        for (const char c : q) {
            r *= 10;
            r += c - '0';
            r %= 7;
        }
        return r;
    };

    const unsigned b = process(0, s);

    do {
        if (process(b, p) == 0) {
            s.append(p);
            s.append(z, '0');
            return answer(s);
        }
    } while (std::next_permutation(p.begin(), p.end()));

    no_answer();
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    std::string s;
    std::cin >> s;

    solve(s);

    return 0;
}
