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

void solve(std::vector<std::pair<int, unsigned>>& a)
{
    const size_t n = a.size();

    std::sort(a.begin(), a.end());

    std::pair<unsigned, unsigned> s[2] = {};
    for (size_t i = 0; i < n; ++i) {
        auto& p = s[a[i].first > 0];
        p.first += a[i].second;
        ++p.second;
    }

    if (s[0].second > s[1].second + 1) {
        for (size_t i = 0; i < s[0].second - (s[1].second + 1); ++i)
            s[0].first -= a[i].second;
    }
    if (s[1].second > s[0].second + 1) {
        for (size_t i = 0; i < s[1].second - (s[0].second + 1); ++i)
            s[1].first -= a[n-1 - i].second;
    }

    answer(s[0].first + s[1].first);
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<std::pair<int, unsigned>> a(n);
    std::cin >> a;

    solve(a);

    return 0;
}

