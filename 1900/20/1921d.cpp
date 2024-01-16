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

void solve(std::vector<unsigned>& a, std::vector<unsigned>& b)
{
    std::sort(a.begin(), a.end());
    std::sort(b.begin(), b.end());

    const auto delta = [](unsigned a, unsigned b) {
        return a < b ? b - a : a - b;
    };

    integer s = 0;
    for (size_t i = 0, j = 0; i < a.size(); ) {
        const unsigned d[] = {
            delta(a[i], b[j]),
            delta(a[i], b.back()),
            delta(a.back(), b[j]),
            delta(a.back(), b.back()),
        };

        const size_t x = std::max_element(std::begin(d), std::end(d)) - std::begin(d);
        switch (x) {
            case 0:
                ++i;
                ++j;
                break;
            case 1:
                ++i;
                b.pop_back();
                break;
            case 2:
                a.pop_back();
                ++j;
                break;
            case 3:
                a.pop_back();
                b.pop_back();
                break;
        }

        s += d[x];
    }

    answer(s);
}

void test_case()
{
    size_t n, m;
    std::cin >> n >> m;

    std::vector<unsigned> a(n), b(m);
    std::cin >> a >> b;

    solve(a, b);
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
