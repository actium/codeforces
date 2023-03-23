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
    const char* separator = "";
    for (const unsigned x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void solve(std::vector<std::vector<unsigned>>& a)
{
    const size_t n = a.size();

    const auto select = [&] {
        std::vector<unsigned> f(n);
        for (size_t i = 0; i < n; ++i)
            ++f[a[i][0] - 1];

        size_t x = 0;
        for (size_t i = 1; i < n; ++i) {
            if (f[i] > f[x])
                x = i;
        }

        return x + 1;
    };

    const auto reduce = [&](unsigned x) {
        for (size_t i = 0; i < n; ++i) {
            if (a[i][0] == x)
                a[i].erase(a[i].begin());
        }
    };

    std::vector<unsigned> p(n);
    for (size_t i = 0; i < n; ++i) {
        p[i] = select();
        reduce(p[i]);
    }

    answer(p);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<std::vector<unsigned>> a(n, std::vector<unsigned>(n - 1));
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
