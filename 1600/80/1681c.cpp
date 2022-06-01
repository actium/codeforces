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

void answer(const std::vector<std::pair<size_t, size_t>>& v)
{
    std::cout << v.size() << '\n';
    for (const std::pair<size_t, size_t>& x : v)
        std::cout << 1+x.first << ' ' << 1+x.second << '\n';
}

void no_answer()
{
    std::cout << -1 << '\n';
}

void solve(std::vector<unsigned>& a, std::vector<unsigned>& b)
{
    const size_t n = a.size();

    std::vector<std::pair<size_t, size_t>> s;

    const auto sort = [&](const std::vector<unsigned>& v) {
        for (size_t i = 1; i < n; ++i) {
            for (size_t j = i; j > 0 && v[j] < v[j-1]; --j) {
                s.emplace_back(j-1, j);

                std::swap(a[j-1], a[j]);
                std::swap(b[j-1], b[j]);
            }
        }
    };

    sort(a);
    sort(b);

    if (!std::is_sorted(a.cbegin(), a.cend()))
        return no_answer();

    answer(s);
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
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
