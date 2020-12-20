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

void answer(const std::vector<unsigned>& v)
{
    const char* separator = "";
    for (const unsigned x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void solve(const std::vector<std::pair<unsigned, unsigned>>& e)
{
    const size_t n = e.size();

    std::vector<size_t> x(n);
    for (size_t i = 0; i < n; ++i)
        x[i] = i;

    const auto compare = [&e](size_t a, size_t b) {
        if (e[a].first != e[b].first)
            return e[a].first < e[b].first;

        return a < b;
    };
    std::sort(x.begin(), x.end(), compare);

    std::vector<unsigned> t(n);
    unsigned p = 0;
    for (const size_t i : x) {
        if (p < e[i].second) {
            t[i] = std::max(e[i].first, p + 1);
            p = t[i];
        }
    }

    answer(t);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<std::pair<unsigned, unsigned>> e(n);
    std::cin >> e;

    solve(e);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

