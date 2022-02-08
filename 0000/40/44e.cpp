#include <iostream>
#include <string>
#include <vector>

void answer(const std::vector<std::string>& v)
{
    for (const std::string& x : v)
        std::cout << x << '\n';
}

void no_answer()
{
    std::cout << "No solution" << '\n';
}

void solve(const std::string& s, unsigned k, unsigned a, unsigned b)
{
    const size_t n = s.length();

    const size_t d = n / k, r = n % k;
    if (d < a || d + (r != 0) > b)
        return no_answer();

    std::vector<std::string> t(k);
    for (size_t i = 0, j = 0; i < k; ++i) {
        const size_t q = d + (i < r);
        t[i] = s.substr(j, q);
        j += q;
    }

    answer(t);
}

int main()
{
    unsigned k, a, b;
    std::cin >> k >> a >> b;

    std::string s;
    std::cin >> s;

    solve(s, k, a, b);

    return 0;
}

