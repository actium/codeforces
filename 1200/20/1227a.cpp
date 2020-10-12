#include <iostream>
#include <vector>

using segment_t = std::pair<unsigned, unsigned>;

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

void solve(std::vector<segment_t>& s)
{
    const size_t n = s.size();

    segment_t t = { s[0].second, s[0].first };
    for (size_t i = 1; i < n; ++i) {
        t.first = std::min(t.first, s[i].second);
        t.second = std::max(t.second, s[i].first);
    }

    answer(t.first < t.second ? t.second - t.first : 0);
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

