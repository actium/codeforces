#include <iostream>
#include <vector>

void answer(size_t v)
{
    std::cout << 1 + v << '\n';
}

unsigned dt(unsigned s, unsigned d, unsigned t)
{
    return s < t ? (d - (t - s) % d) % d : s - t;
}

void solve(const std::vector<unsigned>& s, const std::vector<unsigned>& d, unsigned t)
{
    const size_t n = s.size();

    size_t k = 0;
    for (size_t i = 1; i < n; ++i) {
        if (dt(s[i], d[i], t) < dt(s[k], d[k], t))
            k = i;
    }

    answer(k);
}

int main()
{
    size_t n;
    std::cin >> n;

    unsigned t;
    std::cin >> t;

    std::vector<unsigned> s(n), d(n);
    for (size_t i = 0; i < n; ++i)
        std::cin >> s[i] >> d[i];

    solve(s, d, t);

    return 0;
}

