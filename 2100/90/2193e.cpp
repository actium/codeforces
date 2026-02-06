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

void answer(const std::vector<int>& v)
{
    const char* separator = "";
    for (const int x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void solve(std::vector<unsigned>& a)
{
    const size_t n = a.size();

    std::sort(a.begin(), a.end());
    a.erase(std::unique(a.begin(), a.end()), a.end());

    std::vector<int> c(n, -1);
    for (const unsigned x : a)
        c[x-1] = 1;

    for (unsigned i = 2; i <= n; ++i) {
        if (c[i-1] == -1)
            continue;

        for (const unsigned x : a) {
            const auto v = 1ull * i * x;
            if (v > n)
                break;

            if (c[v-1] == -1 || c[i-1] + 1 < c[v-1])
                c[v-1] = c[i-1] + 1;
        }
    }

    answer(c);
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
