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

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(std::vector<std::pair<unsigned, unsigned>>& o)
{
    const size_t m = o.size(), n = 2 * m;

    const auto compare = [](const std::pair<unsigned, unsigned>& a, const std::pair<unsigned, unsigned>& b) {
        return a.second < b.second;
    };
    std::sort(o.begin(), o.end(), compare);

    std::vector<bool> r[2];
    for (size_t i = 0; i < 2; ++i)
        r[i].resize(n);

    unsigned x = 1;
    for (size_t i = 0, j = 0; j < m; ++j) {
        if (o[j].second == x) {
            r[o[j].first - 1][i] = true;
        } else {
            i += 2 - (o[j].second - x) % 2;
            r[o[j].first - 1][i] = true;
            x = o[j].second;
        }
    }

    for (size_t i = 0; i < n; ++i) {
        if (r[0][i] == r[1][i])
            continue;

        const size_t j = r[0][i];
        if (r[j][i+1])
            return answer(false);

        r[j][i+1] = true;
    }

    answer(true);
}

void test_case()
{
    size_t n, m;
    std::cin >> n >> m;

    std::vector<std::pair<unsigned, unsigned>> o(m);
    std::cin >> o;

    o.emplace_back(1, n + 1);
    o.emplace_back(2, n + 1);

    solve(o);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

