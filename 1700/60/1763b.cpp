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

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(const std::vector<unsigned>& h, const std::vector<unsigned>& p, int k)
{
    const size_t n = h.size();

    std::vector<size_t> o(n);
    for (size_t i = 0; i < n; ++i)
        o[i] = i;

    std::sort(o.begin(), o.end(), [&p](size_t i, size_t j) { return p[i] > p[j]; });

    for (unsigned d = 0; k > 0; k -= p[o.back()]) {
        d += k;
        while (!o.empty() && h[o.back()] <= d)
            o.pop_back();

        if (o.empty())
            return answer(true);
    }

    answer(false);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    int k;
    std::cin >> k;

    std::vector<unsigned> h(n), p(n);
    std::cin >> h >> p;

    solve(h, p, k);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
