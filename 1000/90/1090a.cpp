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

using integer = unsigned long long;

void answer(integer v)
{
    std::cout << v << '\n';
}

void solve(const std::vector<std::vector<unsigned>>& s)
{
    const size_t n = s.size();

    std::vector<std::pair<unsigned, size_t>> p(n);
    for (size_t i = 0; i < n; ++i) {
        p[i].first = *std::max_element(s[i].cbegin(), s[i].cend());
        p[i].second = s[i].size();
    }

    std::sort(p.begin(), p.end(), std::greater<std::pair<unsigned, size_t>>());

    integer d = 0;
    for (size_t i = 1; i < n; ++i)
        d += p[i].second * integer(p[0].first - p[i].first);

    answer(d);
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<std::vector<unsigned>> s(n);
    for (size_t i = 0; i < n; ++i) {
        size_t m;
        std::cin >> m;

        s[i].resize(m);
        std::cin >> s[i];
    }

    solve(s);

    return 0;
}

