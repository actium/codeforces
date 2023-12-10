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

void solve(const std::vector<unsigned>& a, const std::vector<unsigned>& b)
{
    const size_t n = a.size();

    const auto search_l = [&](size_t x) {
        size_t i = x;
        while (i > 0 && a[i] < b[x])
            --i;

        if (a[i] != b[x])
            return false;

        for (size_t j = i + 1; j < x; ++j) {
            if (a[i] > b[j])
                return false;
        }

        return true;
    };

    const auto search_r = [&](size_t x) {
        size_t i = x + 1;
        while (i < n && a[i] < b[x])
            ++i;

        if (i == n || a[i] != b[x])
            return false;

        for (size_t j = x + 1; j < i; ++j) {
            if (a[i] > b[j])
                return false;
        }

        return true;
    };

    for (size_t i = 0; i < n; ++i) {
        if (a[i] == b[i])
            continue;

        if (a[i] > b[i] || !search_l(i) && !search_r(i))
            return answer(false);
    }

    answer(true);
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
