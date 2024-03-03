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

void answer(const std::vector<unsigned>& v)
{
    std::cout << "YES" << '\n';

    const char* separator = "";
    for (const unsigned x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void no_answer()
{
    std::cout << "NO" << '\n';
}

void solve(const std::vector<unsigned>& l, const std::vector<unsigned>& r)
{
    const size_t n = l.size();

    std::vector<unsigned> c(n);
    for (size_t i = 0; i < n; ++i)
        c[i] = n - l[i] - r[i];

    const auto count = [&](auto begin, auto end, unsigned x) {
        return std::count_if(begin, end, [x](unsigned q) { return q > x; });
    };

    for (size_t i = 0; i < n; ++i) {
        if (count(c.begin(), c.begin() + i, c[i]) != l[i])
            return no_answer();

        if (count(c.begin() + i + 1, c.end(), c[i]) != r[i])
            return no_answer();
    }

    answer(c);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    std::vector<unsigned> l(n), r(n);
    std::cin >> l >> r;

    solve(l, r);

    return 0;
}
