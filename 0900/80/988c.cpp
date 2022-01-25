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

void answer(const std::pair<size_t, size_t>& x, const std::pair<size_t, size_t>& y)
{
    std::cout << "YES" << '\n';
    std::cout << 1+x.first << ' ' << 1+x.second << '\n';
    std::cout << 1+y.first << ' ' << 1+y.second << '\n';
}

void no_answer()
{
    std::cout << "NO" << '\n';
}

void solve(const std::vector<std::vector<int>>& a)
{
    const size_t k = a.size();

    std::vector<std::pair<size_t, size_t>> v;

    std::vector<int> s(k);
    for (size_t i = 0; i < k; ++i) {
        for (size_t j = 0; j < a[i].size(); ++j) {
            s[i] += a[i][j];

            v.emplace_back(i, j);
        }
    }

    const auto c = [&](const std::pair<size_t, size_t>& x, const std::pair<size_t, size_t>& y) {
        return s[x.first] - a[x.first][x.second] < s[y.first] - a[y.first][y.second];
    };

    std::sort(v.begin(), v.end(), c);

    for (size_t i = 1; i < v.size(); ++i) {
        if (v[i].first == v[i-1].first)
            continue;

        const int s1 = s[v[i].first] - a[v[i].first][v[i].second], s2 = s[v[i-1].first] - a[v[i-1].first][v[i-1].second];
        if (s1 == s2)
            return answer(v[i], v[i-1]);
    }

    no_answer();
}

int main()
{
    size_t k;
    std::cin >> k;

    std::vector<std::vector<int>> a(k);
    for (std::vector<int>& v : a) {
        size_t n;
        std::cin >> n;

        v.resize(n);
        std::cin >> v;
    }

    solve(a);

    return 0;
}
