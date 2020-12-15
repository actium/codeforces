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

void answer(unsigned v)
{
    std::cout << v << '\n';
}

using segment_t = std::pair<unsigned, unsigned>;

void solve(const std::vector<segment_t>& s)
{
    const size_t n = s.size();

    std::vector<unsigned> l(n), r(n);
    for (size_t i = 0; i < n; ++i) {
        l[i] = s[i].first;
        r[i] = s[i].second;
    }

    std::sort(l.begin(), l.end());
    std::sort(r.begin(), r.end());

    unsigned k = n;
    for (const auto& x : s) {
        const auto c1 = std::lower_bound(r.begin(), r.end(), x.first) - r.begin();
        const auto c2 = std::upper_bound(l.begin(), l.end(), x.second) - l.begin();
        k = std::min<unsigned>(k, c1 + n - c2);
    }

    answer(k);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<segment_t> s(n);
    std::cin >> s;

    solve(s);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

