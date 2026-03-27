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

void solve(const std::vector<int>& a)
{
    const size_t n = a.size();

    std::vector<unsigned> c(n);
    for (size_t i = 0; i < n; ++i) {
        unsigned f[2] = {};
        for (size_t j = i + 1; j < n; ++j) {
            f[0] += (a[j] < a[i]);
            f[1] += (a[j] > a[i]);
        }

        c[i] = std::max(f[0], f[1]);
    }

    answer(c);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<int> a(n);
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
