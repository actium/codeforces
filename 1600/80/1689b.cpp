#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(const std::vector<unsigned>& v)
{
    const char* separator = "";
    for (const unsigned x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void no_answer()
{
    std::cout << -1 << '\n';
}

void solve(const std::vector<unsigned>& p)
{
    const size_t n = p.size();
    if (n == 1)
        return no_answer();

    std::vector<unsigned> q(n);
    for (size_t i = 0; i < n; ++i) {
        q[i] = 1 + i;
    }

    for (size_t i = 0; i + 1 < n; ++i) {
        if (q[i] == p[i])
            std::swap(q[i], q[i+1]);
    }

    if (q[n-1] == p[n-1])
        std::swap(q[n-2], q[n-1]);

    answer(q);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> p(n);
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
