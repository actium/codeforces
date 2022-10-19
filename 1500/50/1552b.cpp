#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(size_t x)
{
    std::cout << 1 + x << '\n';
}

void no_answer()
{
    std::cout << -1 << '\n';
}

void solve(const std::vector<std::vector<unsigned>>& r)
{
    const size_t n = r.size();

    const auto check = [&r](size_t i, size_t x) {
        unsigned q = 0;
        for (size_t j = 0; j < 5; ++j) {
            if (r[i][j] < r[x][j] && ++q == 3)
                return true;
        }
        return false;
    };

    size_t x = 0;
    for (size_t i = 1; i < n; ++i) {
        if (check(i, x))
            x = i;
    }

    for (size_t i = 0; i < n; ++i) {
        if (i != x && check(i, x))
            return no_answer();
    }

    answer(x);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<std::vector<unsigned>> r(n, std::vector<unsigned>(5));
    std::cin >> r;

    solve(r);
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
