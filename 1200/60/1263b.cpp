#include <iostream>
#include <set>
#include <string>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(unsigned u, const std::vector<std::string>& v)
{
    std::cout << u << '\n';

    for (const std::string& x : v)
        std::cout << x << '\n';
}

void solve(const std::vector<std::string>& p)
{
    const size_t n = p.size();

    std::vector<std::string> q(n);

    std::set<std::string> v;
    for (size_t i = 0; i < n; ++i) {
        if (v.count(p[i]) == 1)
            continue;

        q[i] = p[i];
        v.insert(q[i]);
    }

    unsigned k = 0;
    for (size_t i = 0; i < n; ++i) {
        if (!q[i].empty())
            continue;

        q[i] = p[i];
        for (size_t j = 0; v.count(q[i]) == 1; ++j)
            q[i][j/10] = '0' + (p[i][j/10] - '0' + j % 10) % 10;

        v.insert(q[i]);

        ++k;
    }

    answer(k, q);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<std::string> p(n);
    std::cin >> p;

    solve(p);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
