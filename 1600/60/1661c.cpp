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

void answer(integer x)
{
    std::cout << x << '\n';
}

void solve(const std::vector<unsigned>& h)
{
    const size_t n = h.size();

    const unsigned x = *std::max_element(h.begin(), h.end());

    const auto count = [&](unsigned x) {
        integer f[2] = {};
        for (size_t i = 0; i < n; ++i) {
            const unsigned d = x - h[i];
            f[0] += d / 2;
            f[1] += d % 2;
        }

        const integer t = f[0] * 2 + f[1];
        return std::max(f[1] != 0 ? f[1] * 2 - 1 : 0, t / 3 * 2 + t % 3);
    };

    answer(std::min(count(x), count(x+1)));
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> h(n);
    std::cin >> h;

    solve(h);
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