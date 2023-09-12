#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(const std::vector<std::pair<size_t, size_t>>& v)
{
    std::cout << v.size() << '\n';

    for (const std::pair<size_t, size_t>& x : v)
        std::cout << 1 + x.first << ' ' << 1 + x.second << '\n';
}

void solve(std::vector<int>& a)
{
    const size_t n = a.size();

    size_t x = 0;
    for (size_t i = 1; i < n; ++i) {
        if (a[i] == 0)
            continue;

        if (a[i] > a[x] || a[x] == 0)
            x = i;
    }

    std::vector<std::pair<size_t, size_t>> c;
    if (a[x] != 0) {
        c.emplace_back(x, x);
        a[x] += a[x];
    }

    if (a[x] > 0) {
        while (a[n-1] < a[x]) {
            c.emplace_back(n-1, x);
            a[n-1] += a[x];
        }

        for (size_t i = 1; i < n; ++i) {
            if (a[i] >= a[i-1])
                continue;

            while (a[i] + a[n-1] < a[i-1]) {
                c.emplace_back(n-1, n-1);
                a[n-1] += a[n-1];
            }

            size_t x = 0;
            for (size_t j = 1; j < n; ++j) {
                if (a[i] + a[j] >= a[i-1] && (a[j] < a[x] || a[i] + a[x] < a[i-1]))
                    x = j;
            }

            c.emplace_back(i, x);
            a[i] += a[x];
        }
    } else {
        while (a[0] > a[x]) {
            c.emplace_back(0, x);
            a[0] += a[x];
        }

        for (size_t i = n - 1; i > 0; --i) {
            if (a[i-1] <= a[i])
                continue;

            while (a[i-1] + a[0] > a[i]) {
                c.emplace_back(0, 0);
                a[0] += a[0];
            }

            size_t x = 0;
            for (size_t j = 1; j < n; ++j) {
                if (a[i-1] + a[j] <= a[i] && (a[j] > a[x] || a[i-1] + a[x] > a[i]))
                    x = j;
            }

            c.emplace_back(i-1, x);
            a[i-1] += a[x];
        }
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
