#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(const std::vector<std::pair<std::string_view, std::string_view>>& v)
{
    for (const std::pair<std::string_view, std::string_view>& x : v)
        std::cout << x.first << ' ' << x.second << '\n';;
}

void no_answer()
{
    std::cout << "IMPOSSIBLE" << '\n';
}

void solve(const std::vector<std::string>& c, char ts)
{
    const std::string s = "CDHS";

    const auto index = [&](const std::string_view& x) {
        return x[1] == ts ? 4 : s.find(x[1]);
    };

    std::vector<std::string_view> d[5];
    for (const std::string& x : c)
        d[index(x)].push_back(x);

    std::vector<std::pair<std::string_view, std::string_view>> r;
    for (size_t i = 0; i < 5; ++i) {
        const size_t m = d[i].size();
        if (m % 2 == 1 && d[4].empty())
            return no_answer();

        std::sort(d[i].begin(), d[i].end());

        for (size_t j = 1; j < m; j += 2)
            r.emplace_back(d[i][j-1], d[i][j]);

        if (m % 2 == 1) {
            r.emplace_back(d[i].back(), d[4].back());
            d[4].pop_back();
        }
    }

    answer(r);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    char ts;
    std::cin >> ts;

    std::vector<std::string> c(2 * n);
    std::cin >> c;

    solve(c, ts);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
