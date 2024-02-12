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

void answer(size_t x, size_t y)
{
    std::cout << 1 + x << ' ' << 1 + y << '\n';
}

void no_answer()
{
    std::cout << -1 << ' ' << -1 << '\n';
}

void solve(const std::vector<std::pair<unsigned, unsigned>>& s)
{
    const size_t n = s.size();

    std::vector<size_t> p(n);
    for (size_t i = 0; i < n; ++i)
        p[i] = i;

    std::sort(p.begin(), p.end(), [&](size_t i, size_t j) {
        return s[i].first < s[j].first || s[i].first == s[j].first && s[i].second > s[j].second;
    });

    for (size_t i = 1; i < n; ++i) {
        if (s[p[i]].second <= s[p[i-1]].second)
            return answer(p[i], p[i-1]);
    }

    no_answer();
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    std::vector<std::pair<unsigned, unsigned>> s(n);
    std::cin >> s;

    solve(s);

    return 0;
}
