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

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(const std::vector<unsigned>& a)
{
    const size_t n = a.size();

    std::vector<unsigned> c = { 1 };
    for (size_t i = 1; i < n; ++i) {
        if (a[i] != a[i-1])
            c.push_back(0);

        ++c.back();
    }

    std::sort(c.begin(), c.end(), std::greater<unsigned>());

    unsigned k = 0;
    while (!c.empty()) {
        k = std::max<unsigned>(k, c.back() * c.size());
        c.pop_back();
    }

    answer(k);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
