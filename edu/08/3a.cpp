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

void answer(unsigned x, unsigned y)
{
    std::cout << x << ' ' << y << '\n';
}

void solve(size_t n, const std::vector<std::pair<unsigned, unsigned>>& e)
{
    std::vector<unsigned> s(n), t(n);
    for (const std::pair<unsigned, unsigned>& q : e) {
        ++s[q.first - 1];
        ++t[q.second - 1];
    }

    unsigned f[2] = {};
    for (size_t i = 0; i < n; ++i) {
        f[0] += (t[i] == 0);
        f[1] += (s[i] == 0);
    }

    answer(f[0], f[1]);
}

void test_case()
{
    size_t n, m;
    std::cin >> n >> m;

    std::vector<std::pair<unsigned, unsigned>> e(m);
    std::cin >> e;

    solve(n, e);
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
