#include <iostream>
#include <string>

unsigned search(const std::string& s, char x)
{
    const size_t n = s.length();

    size_t r = s.find(x);
    if (r == std::string::npos)
        return n;

    unsigned k = r + 1;
    for (size_t l = r++; l < n; l = r++) {
        r = s.find(x, r);
        k = std::max<unsigned>(k, std::min(r, n) - l);
    }
    return k;
}

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(const std::string& s)
{
    unsigned k = s.length();
    for (char x = 'a'; x <= 'z'; ++x)
        k = std::min(k, search(s, x));

    answer(k);
}

int main()
{
    std::string s;
    std::cin >> s;

    solve(s);

    return 0;
}
