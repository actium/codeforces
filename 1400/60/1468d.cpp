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

void solve(std::vector<unsigned>& s, unsigned a, unsigned b, unsigned w)
{
    const unsigned d = std::max(a, b) - std::min(a, b), x = (a < b ? a - 1 : w - a);

    std::sort(s.begin(), s.end());

    unsigned k = 0;
    for (unsigned t = d; t > 1 && !s.empty(); s.pop_back()) {
        if (s.back() < t + x) {
            ++k;
            --t;
        }
    }

    answer(k);
}

void test_case()
{
    size_t n, m;
    std::cin >> n >> m;

    unsigned a, b;
    std::cin >> a >> b;

    std::vector<unsigned> s(m);
    std::cin >> s;

    solve(s, a, b, n);
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
