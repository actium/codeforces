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

void answer(const std::vector<unsigned>& v)
{
    std::cout << "YES" << '\n';

    const char* separator = "";
    for (const unsigned x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void solve(std::vector<unsigned>& a)
{
    const size_t n = a.size();

    std::sort(a.begin(), a.end());

    std::vector<unsigned> b(n);
    {
        std::vector<bool> v(1000001);

        const auto fix = [&](unsigned x) {
            for (size_t i = 0; i < n; ++i) {
                for (size_t j = 0; j < n && a[j] < a[i] + x; ++j)
                    v[a[i] + x - a[j]] = true;
            }
            return x;
        };

        for (size_t i = 0, x = 1; i < n; ++i) {
            while (x <= 1000000 && v[x])
                ++x;

            b[i] = fix(x);
        }
    }

    answer(b);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a);
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
