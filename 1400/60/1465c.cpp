#include <iostream>
#include <utility>
#include <vector>

template <typename T, typename U>
std::istream& operator >>(std::istream& input, std::pair<T, U>& v)
{
    return input >> v.first >> v.second;
}

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

void solve(size_t n, const std::vector<std::pair<unsigned, unsigned>>& p)
{
    unsigned k = p.size();

    std::vector<unsigned> r(1+n);
    for (const auto [x, y] : p) {
        if (x != y)
            r[x] = y;
        else
            --k;
    }

    for (unsigned x = 1; x <= n; ++x) {
        if (r[x] != 0) {
            unsigned y = x;
            while (r[y] != 0)
                y = std::exchange(r[y], 0);

            if (x == y)
                ++k;
        }
    }

    answer(k);
}

void test_case()
{
    size_t n, m;
    std::cin >> n >> m;

    std::vector<std::pair<unsigned, unsigned>> p(m);
    std::cin >> p;

    solve(n, p);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

