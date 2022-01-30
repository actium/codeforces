#include <iostream>
#include <string>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

bool test(const std::string& s1, const std::string& s2, size_t k)
{
    const size_t n = s1.length(), m = s2.length();
    if (n % k != 0 || m % k != 0)
        return false;

    for (size_t i = 0; i < n; i += k) {
        if (s1.compare(i, k, s1, 0, k) != 0)
            return false;
    }
    for (size_t i = 0; i < m; i += k) {
        if (s2.compare(i, k, s1, 0, k) != 0)
            return false;
    }
    return true;
}

void solve(std::string& s1, std::string& s2)
{
    if (s1.length() > s2.length())
        s1.swap(s2);

    const size_t n = s1.length();

    unsigned k = 0;
    for (unsigned i = 1; i * i <= n; ++i) {
        if (n % i != 0)
            continue;

        k += test(s1, s2, i);

        if (n / i != i)
            k += test(s1, s2, n / i);
    }

    answer(k);
}

int main()
{
    std::string s1, s2;
    std::cin >> s1 >> s2;

    solve(s1, s2);

    return 0;
}
