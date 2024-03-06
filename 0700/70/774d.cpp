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
    constexpr const char* s[2] = { "LIE", "TRUTH" };
    std::cout << s[v] << '\n';
}

void solve(const std::vector<unsigned>& a, const std::vector<unsigned>& b, size_t l, size_t r)
{
    const auto check = [&](size_t lb, size_t ub) {
        for (size_t i = lb; i < ub; ++i) {
            if (a[i] != b[i])
                return false;
        }
        return true;
    };

    answer(check(0, l - 1) && check(r, a.size()));
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n, l, r;
    std::cin >> n >> l >> r;

    std::vector<unsigned> a(n), b(n);
    std::cin >> a >> b;

    solve(a, b, l, r);

    return 0;
}
