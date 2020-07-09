#include <iostream>
#include <string>

bool palindromic(const std::string& s, size_t n)
{
    for (size_t i = 0; i < n/2; ++i) {
        if (s[i] != s[n-1 - i])
            return false;
    }
    return true;
}

void answer(size_t v)
{
    std::cout << v << '\n';
}

void solve(const std::string& s)
{
    size_t k = s.length();
    while (k > 0 && palindromic(s, k))
        --k;

    answer(k);
}

int main()
{
    std::string s;
    std::cin >> s;

    solve(s);

    return 0;
}

