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

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(std::vector<unsigned>& a)
{
    const size_t n = a.size();

    std::vector<unsigned> b(a.begin(), a.end());
    std::sort(b.begin(), b.end());
    b.erase(std::unique(b.begin(), b.end()), b.end());

    for (size_t i = 0; i < n; ++i)
        a[i] = std::lower_bound(b.begin(), b.end(), a[i]) - b.begin();

    const auto check = [&](size_t begin, size_t end, std::vector<bool>& v) {
        for (size_t i = begin; i < end; ++i) {
            if (v[a[i]])
                return false;

            v[a[i]] = true;
        }
        return true;
    };

    const auto test = [&](size_t k) {
        std::vector<bool> v(n);
        for (size_t i = 0; i + k <= n; ++i) {
            std::fill(v.begin(), v.end(), false);

            if (!check(0, i, v))
                return false;

            if (check(i + k, n, v))
                return true;
        }
        return false;
    };

    int lb = -1, ub = n;
    while (lb + 1 < ub) {
        const int mid = (lb + ub) / 2;
        (test(mid) ? ub : lb) = mid;
    }

    answer(ub);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a);

    return 0;
}
