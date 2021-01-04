#include <algorithm>
#include <iostream>
#include <vector>

template <typename T, typename U>
std::istream& operator >>(std::istream& input, std::pair<T, U>& v)
{
    return input >> v.first >> v.second;
}

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(const std::vector<std::pair<unsigned, unsigned>>& v)
{
    std::cout << v.size() << '\n';

    for (const auto& x : v)
        std::cout << 1+x.first << ' ' << 1+x.second << '\n';
}

void solve(size_t n, const std::vector<std::pair<unsigned, unsigned>>& r)
{
    std::vector<bool> x(n);
    for (const auto& q : r) {
        x[q.first - 1] = true;
        x[q.second - 1] = true;
    }

    const size_t i = std::find(x.cbegin(), x.cend(), false) - x.cbegin();

    std::vector<std::pair<unsigned, unsigned>> v;
    for (size_t j = 0; j < n; ++j) {
        if (j != i)
            v.emplace_back(i, j);
    }

    answer(v);
}

int main()
{
    size_t n, m;
    std::cin >> n >> m;

    std::vector<std::pair<unsigned, unsigned>> r(m);
    std::cin >> r;

    solve(n, r);

    return 0;
}

