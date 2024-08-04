#include <iostream>
#include <string>
#include <vector>

void answer(const std::string& x, const std::string& y)
{
    std::cout << "YES" << '\n';
    std::cout << x << '\n';
    std::cout << y << '\n';
}

void no_answer()
{
    std::cout << "NO" << '\n';
}

void solve(const std::string& s, unsigned a, unsigned b)
{
    const size_t n = s.length();

    std::vector<unsigned> ra(1+n);
    {
        for (size_t i = 0; i < n; ++i)
            ra[i+1] = (10 * ra[i] + (s[i] - '0')) % a;
    }

    std::vector<unsigned> rb(n+1);
    {
        unsigned x = 1;
        for (size_t i = n-1; ~i != 0; --i) {
            rb[i] = (x * (s[i] - '0') + rb[i+1]) % b;
            x = 10 * x % b;
        }
    }

    for (size_t i = 1; i < n; ++i) {
        if (s[i] != '0' && rb[i] == 0 && ra[i] == 0)
            return answer(s.substr(0, i), s.substr(i));
    }

    no_answer();
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    std::string s;
    std::cin >> s;

    unsigned a, b;
    std::cin >> a >> b;

    solve(s, a, b);

    return 0;
}
