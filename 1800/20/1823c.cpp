#include <iostream>
#include <map>
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

void solve(const std::vector<unsigned>& a)
{
    std::map<unsigned, unsigned> f;
    for (unsigned x : a) {
        for (unsigned i = 2; i * i <= x; ++i) {
            while (x % i == 0) {
                ++f[i];
                x /= i;
            }
        }
        if (x != 1)
            ++f[x];
    }

    unsigned k = 0, q = 0;
    for (const auto& e : f) {
        k += e.second / 2;
        q += e.second % 2;
    }

    answer(k + q / 3);
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
