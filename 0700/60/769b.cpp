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
    std::cout << - 1 << '\n';
}

void solve(std::vector<unsigned>& a)
{
    const size_t n = a.size();

    std::vector<size_t> x(n);
    for (size_t i = 0; i < n; ++i)
        x[i] = i;

    std::sort(x.begin() + 1, x.end(), [&a](size_t i, size_t j) { return a[i] > a[j]; });

    std::vector<std::pair<size_t, size_t>> m;
    for (size_t i = 0, j = 1; j < n; ++j) {
        if (a[x[i]] == 0)
            return no_answer();

        m.emplace_back(x[i], x[j]);

        if (--a[x[i]] == 0)
            ++i;
    }

    answer(m);
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a);

    return 0;
}

