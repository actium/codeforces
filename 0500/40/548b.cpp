#include <algorithm>
#include <iostream>
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

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(std::vector<std::vector<unsigned>>& a, const std::vector<std::pair<unsigned, unsigned>>& r)
{
    const size_t n = a.size(), m = a[0].size();

    std::vector<unsigned> x(n);

    const auto update = [&](size_t i) {
        x[i] = 0;

        unsigned k = 0;
        for (size_t j = 0; j < m; ++j) {
            if (a[i][j] == 1) {
                x[i] = std::max(x[i], ++k);
            } else {
                k = 0;
            }
        }
    };

    for (size_t i = 0; i < n; ++i)
        update(i);

    for (const auto& q : r) {
        a[q.first-1][q.second-1] ^= 1;
        update(q.first-1);
        answer(*std::max_element(x.cbegin(), x.cend()));
    }
}

int main()
{
    size_t n, m, q;
    std::cin >> n >> m >> q;

    std::vector<std::vector<unsigned>> a(n, std::vector<unsigned>(m));
    std::cin >> a;

    std::vector<std::pair<unsigned, unsigned>> r(q);
    std::cin >> r;

    solve(a, r);

    return 0;
}
