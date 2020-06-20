#include <iostream>
#include <string>

void answer(size_t v)
{
    std::cout << v << '\n';
}

void solve(const std::string& s)
{
    const size_t n = s.length();

    size_t c = 0;
    for (size_t i = 0; i < n-1; ++i) {
        if (s[i] != s[i+1])
            ++c, ++i;
    }

    answer(n - c);
}

int main()
{
    size_t n;
    std::cin >> n;

    std::string s;
    std::cin >> s;

    solve(s);

    return 0;
}

