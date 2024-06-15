#include <algorithm>
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

void answer(unsigned x)
{
    std::cout << x << '\n';
}

unsigned count(unsigned r, unsigned d, unsigned m)
{
    integer v = 1;
    for (unsigned i = 2; i <= r; ++i) {
        if (i % 2 == 0 && d != 0) {
            v = v * (i / 2) % m;
            --d;
        } else {
            v = v * i % m;
        }
    }
    return v;
}

void solve(const std::vector<unsigned>& a, const std::vector<unsigned>& b, unsigned m)
{
    const size_t n = a.size();

    std::vector<std::pair<unsigned, unsigned>> s;
    for (size_t i = 0; i < n; ++i) {
        s.emplace_back(a[i], i);
        s.emplace_back(b[i], i);
    }

    std::sort(s.begin(), s.end());

    integer k = 1;
    {
        s.emplace_back(0, 0);

        unsigned r = 1, d = 0;
        for (size_t i = 1; i <= 2 * n; ++i) {
            if (s[i].first == s[i-1].first) {
                ++r;
                d += (s[i].second == s[i-1].second);
            } else {
                k = k * count(r, d, m) % m;
                r = 1;
                d = 0;
            }
        }
    }

    answer(k);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    std::vector<unsigned> a(n), b(n);
    std::cin >> a >> b;

    unsigned m;
    std::cin >> m;

    solve(a, b, m);

    return 0;
}
