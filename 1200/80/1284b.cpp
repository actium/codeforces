#include <algorithm>
#include <iostream>
#include <vector>

using integer = unsigned long long;

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(integer x)
{
    std::cout << x << '\n';
}

void solve(const std::vector<std::vector<unsigned>>& s)
{
    const size_t n = s.size();

    std::vector<std::pair<unsigned, unsigned>> r;
    for (const std::vector<unsigned>& q : s) {
        if (std::is_sorted(q.crbegin(), q.crend()))
            r.emplace_back(q.back(), q.front());
    }

    std::sort(r.begin(), r.end());

    integer k = 0;
    for (const std::pair<unsigned, unsigned>& q : r) {
        const auto it = std::lower_bound(r.cbegin(), r.cend(), std::make_pair(q.second, 0u));
        k += std::distance(it, r.cend());
    }

    answer(1ull * n * n - k);
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<std::vector<unsigned>> s(n);
    for (size_t i = 0; i < n; ++i) {
        size_t l;
        std::cin >> l;

        s[i].resize(l);
        std::cin >> s[i];
    }

    solve(s);

    return 0;
}
