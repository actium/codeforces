#include <iostream>
#include <vector>

using integer = unsigned long long;

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

void solve(const std::vector<unsigned>& h, integer m, unsigned k)
{
    const size_t n = h.size();

    for (size_t i = 1; i < n; ++i) {
        const unsigned q = (h[i] > k ? h[i] - k : 0);
        if (h[i-1] > q) {
            m += h[i-1] - q;
            continue;
        }

        const unsigned d = q - h[i-1];
        if (m < d)
            return answer(false);

        m -= d;
    }

    answer(true);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    unsigned m, k;
    std::cin >> m >> k;

    std::vector<unsigned> h(n);
    std::cin >> h;

    solve(h, m, k);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

