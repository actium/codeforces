#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(const std::vector<unsigned>& a)
{
    const size_t n = a.size();

    const auto check = [&](size_t p) {
        if (p < 3 || n % p != 0)
            return false;

        for (size_t i = 0, k = n / p; i < k; ++i) {
            unsigned q = 0;
            for (size_t j = i; j < n && a[j] == 1; j += k)
                ++q;

            if (q == p)
                return true;
        }
        return false;
    };

    for (size_t i = 1; i * i <= n; ++i) {
        if (check(i) || check(n / i))
            return answer(true);
    }

    answer(false);
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
