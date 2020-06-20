#include <iostream>
#include <string>

void answer(const std::string& v)
{
    std::cout << v << '\n';
}

void solve(const std::string& t)
{
    const size_t n = t.length();

    std::string s(n, ' ');
    auto it = s.rbegin();

    size_t l = 0, r = n - 1;
    if (n % 2 == 0)
        *it++ = t[r--];

    while (l < r) {
        *it++ = t[l++];
        *it++ = t[r--];
    }

    *it = t[l];

    answer(s);
}

int main()
{
    std::string t;
    std::cin >> t;

    solve(t);

    return 0;
}

