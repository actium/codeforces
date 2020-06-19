#include <iostream>
#include <string>

void answer(size_t v)
{
    std::cout << v << '\n';
}

void solve(const std::string& s)
{
    const size_t n = s.length();

    size_t count = 0;
    for (size_t i = 0; i < n; ++i) {
        if (s[i] % 2 == 0)	// '0' is even
            count += i + 1;
    }

    answer(count);
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

