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

void solve(const std::vector<unsigned>& a, size_t k)
{
    size_t n = a.size();

    std::vector<unsigned> q = { 1 };
    for (size_t i = 1; i < n; ++i) {
        if (a[i] != a[i-1])
            q.push_back(0);

        ++q.back();
    }

    std::sort(q.begin(), q.end(), std::greater<unsigned>());

    const auto drop = [&](unsigned x) {
        while (!q.empty() && q.back() == x)
            q.pop_back();
    };

    unsigned d = 0;
    while (n > k) {
        n -= q.size();
        drop(++d);
    }

    unsigned c = 0;
    while (n != 0) {
        if ((k - n) % q.size() == 0)
            ++c;

        const unsigned x = q.back();
        n -= (x - d) * q.size();
        drop(x);

        d = x;
    }

    answer(c);
}

void test_case()
{
    size_t n, k;
    std::cin >> n >> k;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a, k);
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
