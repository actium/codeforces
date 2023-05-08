#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(size_t x, size_t y)
{
    std::cout << 1+x << ' ' << 1+y << '\n';
}

void solve(const std::vector<unsigned>& a, const std::vector<unsigned>& b)
{
    const size_t n = a.size();

    std::vector<std::pair<size_t, size_t>> p;
    for (size_t i = 0, j = 0; j < n; ++j) {
        if (j == n - 1 || b[j] > b[j+1]) {
            p.emplace_back(i, j);
            i = j + 1;
        }
    }

    const auto check = [&](const std::pair<size_t, size_t>& x) {
        for (size_t i = x.first; i <= x.second; ++i) {
            if (a[i] != b[i])
                return true;
        }
        return false;
    };

    std::pair<size_t, size_t> x = {0, 0};
    for (const std::pair<size_t, size_t>& q : p) {
        if (check(q) && q.second - q.first >= x.second - x.first)
            x = q;
    }

    answer(x.first, x.second);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> a(n), b(n);
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
