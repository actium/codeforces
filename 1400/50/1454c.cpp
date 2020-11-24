#include <algorithm>
#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(size_t b, const std::vector<unsigned>& a)
{
    const size_t n = a.size();

    std::vector<std::vector<size_t>> p(b);
    for (size_t i = 0; i < n; ++i)
        p[a[i]-1].push_back(i);

    unsigned k = ~0u;
    for (unsigned i = 0; i < b; ++i) {
        const unsigned c = p[i].size();
        if (c != 0)
            k = std::min(k, c + 1 - (p[i].front() == 0) - (p[i].back() == n-1));
    }

    answer(k);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> a(n);
    std::cin >> a;

    a.resize(std::unique(a.begin(), a.end()) - a.begin());

    solve(n, a);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

