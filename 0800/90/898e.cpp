#include <algorithm>
#include <iostream>
#include <vector>

#include <cmath>

using integer = unsigned long long;

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(integer x)
{
    std::cout << x << '\n';
}

void solve(const std::vector<unsigned>& a)
{
    const size_t n = a.size();

    std::vector<integer> d[2];
    for (size_t i = 0; i < n; ++i) {
        const unsigned x = sqrt(a[i]);
        if (x * x == a[i]) {
            d[0].push_back(1 + (x == 0));
            continue;
        }

        if (x * x < a[i]) {
            d[1].push_back(std::min(a[i] - x * x, (x + 1) * (x + 1) - a[i]));
        } else {
            d[1].push_back(std::min(x * x - a[i], a[i] - (x - 1) * (x - 1)));
        }
    }

    const auto count = [](std::vector<integer>& v, size_t k) {
        std::sort(v.begin(), v.end());

        integer t = 0;
        for (size_t i = 0; i < k; ++i)
            t += v[i];

        return t;
    };

    if (d[0].size() < d[1].size())
        return answer(count(d[1], (d[1].size() - d[0].size()) / 2));

    if (d[0].size() > d[1].size())
        return answer(count(d[0], (d[0].size() - d[1].size()) / 2));

    answer(0);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a);

    return 0;
}
