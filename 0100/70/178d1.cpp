#include <algorithm>
#include <iostream>
#include <vector>

constexpr int oo = ~0u >> 1;

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(int x, const std::vector<std::vector<int>>& y)
{
    std::cout << x << '\n';

    for (const std::vector<int>& v : y) {
        const char* separator = "";
        for (const int x : v) {
            std::cout << separator << x;
            separator = " ";
        }
        std::cout << '\n';
    }
}

void solve(size_t n, std::vector<int>& a)
{
    std::sort(a.begin(), a.end());

    const auto check = [&] {
        int s[8] = {};
        for (size_t i = 0; i < n; ++i) {
            for (size_t j = 0; j < n; ++j) {
                s[i] += a[i * n + j];
                s[n + j] += a[i * n + j];
            }
            s[2 * n] += a[i * n + i];
            s[2 * n + 1] += a[i * n + n - 1 - i];
        }

        for (size_t i = 1; i < 2 * n + 2; ++i) {
            if (s[i] != s[0])
                return oo;
        }
        return s[0];
    };

    int t = check();
    while (t == oo) {
        std::next_permutation(a.begin(), a.end());
        t = check();
    }

    std::vector<std::vector<int>> s(n);
    for (size_t i = 0; i < n; ++i)
        s[i].insert(s[i].end(), a.begin() + i * n, a.begin() + i * n + n);

    answer(t, s);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    std::vector<int> a(n * n);
    std::cin >> a;

    solve(n, a);

    return 0;
}
