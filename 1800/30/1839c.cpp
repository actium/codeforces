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

void solve(const std::vector<unsigned>& a)
{
    const size_t n = a.size();

    if (a.back() == 1)
        return no_answer();

    std::vector<std::pair<unsigned, unsigned>> f;
    f.emplace_back(a[0], 1);
    for (size_t i = 1; i < n; ++i) {
        if (a[i] != a[i-1])
            f.emplace_back(a[i], 0);

        ++f.back().second;
    }

    std::vector<unsigned> c;
    for (size_t k = f.size(); k > 1; k -= 2) {
        c.insert(c.end(), f[k-1].second + f[k-2].second - 1, 0);
        c.push_back(f[k-2].second);
    }
    if (f.size() % 2 == 1)
        c.insert(c.end(), f[0].second, 0);

    answer(c);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> a(n);
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
