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

void answer(const std::string& x)
{
    std::cout << x << '\n';
}

void solve(const std::vector<std::pair<unsigned, unsigned>>& b)
{
    const size_t n = b.size();

    std::vector<unsigned> f(2 * n + 2);
    for (const std::pair<unsigned, unsigned>& s : b) {
        if (s.first == s.second)
            ++f[s.first];
    }

    std::vector<unsigned> t(2 * n + 2);
    for (size_t i = 2 * n + 1; i > 0; --i)
        t[i] = (f[i] == 0 ? i : t[i+1]);

    std::string r(n, '0');
    for (size_t i = 0; i < n; ++i) {
        if (b[i].first == b[i].second && f[b[i].first] == 1 || b[i].first != b[i].second && t[b[i].first] <= b[i].second)
            ++r[i];
    }

    answer(r);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<std::pair<unsigned, unsigned>> b(n);
    std::cin >> b;

    solve(b);
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
