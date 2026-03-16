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

void solve(std::vector<unsigned>& a, size_t k, size_t p, unsigned m)
{
    const size_t n = a.size();

    if (k == n)
        return answer(m / a[p]);

    const auto use = [&](auto it) {
        const unsigned x = *it;
        if (x > m)
            return false;

        m -= x;
        a.erase(it);
        a.push_back(x);
        return true;
    };

    for ( ; p >= k; --p) {
        if (!use(std::min_element(a.begin(), a.begin() + k)))
            return answer(0);
    }

    if (!use(a.begin() + p))
        return answer(0);

    std::sort(a.begin(), a.end() - 1);

    unsigned s = a.back();
    for (size_t i = 0; i < n - k; ++i)
        s += a[i];

    answer(1 + m / s);
}

void test_case()
{
    size_t n, k, p;
    std::cin >> n >> k >> p;

    unsigned m;
    std::cin >> m;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a, k, p-1, m);
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
