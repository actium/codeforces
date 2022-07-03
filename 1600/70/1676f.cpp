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

void answer(unsigned x, unsigned y)
{
    std::cout << x << ' ' << y << '\n';
}

void no_answer()
{
    std::cout << -1 << '\n';
}

void solve(std::vector<unsigned>& a, size_t k)
{
    const size_t n = a.size();

    std::sort(a.begin(), a.end());

    std::vector<unsigned> b;
    for (size_t i = 0, j = 0; i < n; i = j) {
        while (j < n && a[j] == a[i])
            ++j;

        if (j - i >= k)
            b.push_back(a[i]);
    }

    if (b.empty())
        return no_answer();

    std::vector<std::pair<unsigned, unsigned>> c;
    for (size_t i = 0, j = 1; i < b.size(); i = j++) {
        while (j < b.size() && b[j] == b[j-1] + 1)
            ++j;

        c.emplace_back(j - i, b[i]);
    }

    const auto it = std::max_element(c.cbegin(), c.cend());
    answer(it->second, it->second + it->first - 1);
}

void test_case()
{
    size_t n, k;
    std::cin >> n >> k;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a, k);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
