#include <iostream>
#include <string>
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

void answer(unsigned x)
{
    std::cout << x << '\n';
}

unsigned search(const std::vector<std::pair<unsigned, unsigned>>& c, const std::string& s, size_t u)
{
    if (c[u].first == 0 && c[u].second == 0)
        return 0;

    if (c[u].first == 0)
        return search(c, s, c[u].second - 1) + (s[u] != 'R');

    if (c[u].second == 0)
        return search(c, s, c[u].first - 1) + (s[u] != 'L');

    return std::min(search(c, s, c[u].second - 1) + (s[u] != 'R'), search(c, s, c[u].first - 1) + (s[u] != 'L'));
}

void solve(const std::vector<std::pair<unsigned, unsigned>>& c, const std::string& s)
{
    answer(search(c, s, 0));
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::string s;
    std::cin >> s;

    std::vector<std::pair<unsigned, unsigned>> c(n);
    std::cin >> c;

    solve(c, s);
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
