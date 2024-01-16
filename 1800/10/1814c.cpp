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

std::ostream& operator <<(std::ostream& output, const std::vector<unsigned>& v)
{
    output << v.size();
    for (const unsigned x : v)
        output << ' ' << x;

    return output;
}

void answer(const std::vector<unsigned>& x, const std::vector<unsigned>& y)
{
    std::cout << x << '\n';
    std::cout << y << '\n';
}

void solve(const std::vector<unsigned>& r, unsigned s1, unsigned s2)
{
    const size_t n = r.size();

    std::vector<size_t> p(n);
    for (size_t i = 0; i < n; ++i)
        p[i] = i;

    std::sort(p.begin(), p.end(), [&](size_t i, size_t j) {
        return r[i] > r[j];
    });

    std::vector<unsigned> v[2];
    for (const size_t i : p)
        v[s1 * (v[0].size() + 1) > s2 * (v[1].size() + 1)].push_back(i + 1);

    answer(v[0], v[1]);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    unsigned s1, s2;
    std::cin >> s1 >> s2;

    std::vector<unsigned> r(n);
    std::cin >> r;

    solve(r, s1, s2);
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
