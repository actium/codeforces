#include <iostream>
#include <string>
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

void solve(const std::string& t, const std::string& p, const std::vector<unsigned>& a)
{
    const size_t n = t.length(), m = p.length();

    const auto check = [&](size_t k) {
        std::vector<bool> d(n);
        for (size_t i = 0; i < k; ++i)
            d[a[i]-1] = true;

        for (size_t i = 0, j = 0; i < n; ++i) {
            if (!d[i] && p[j] == t[i] && ++j == m)
                return true;
        }
        return false;
    };

    size_t lb = 0, ub = n;
    while (lb + 1 < ub) {
        const size_t mid = (lb + ub) / 2;
        (check(mid) ? lb : ub) = mid;
    }

    answer(lb);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    std::string t, p;
    std::cin >> t >> p;

    std::vector<unsigned> a(t.length());
    std::cin >> a;

    solve(t, p, a);

    return 0;
}
