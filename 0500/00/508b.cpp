#include <iostream>
#include <string>

void answer(const std::string& v)
{
    std::cout << v << '\n';
}

void no_answer()
{
    std::cout << -1 << '\n';
}

void solve(std::string& s)
{
    const size_t n = s.length();

    for (size_t i = 0; i < n; ++i) {
        if (s[i] % 2 == 0 && s[i] < s.back()) {
            std::swap(s[i], s.back());
            return answer(s);
        }
    }

    for (size_t i = 0; i < n; ++i) {
        if (s[n-1-i] % 2 == 0) {
            std::swap(s[n-1-i], s.back());
            return answer(s);
        }
    }

    no_answer();
}

int main()
{
    std::string s;
    std::cin >> s;

    solve(s);

    return 0;
}

