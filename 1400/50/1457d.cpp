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

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void no_answer()
{
    std::cout << -1 << '\n';
}

void solve(const std::vector<unsigned>& a, const std::vector<unsigned>& b, unsigned m)
{
    const size_t n = a.size();

    std::vector<unsigned> c[2];
    for (size_t i = 0; i < n; ++i)
        c[b[i]-1].push_back(a[i]);
    
    for (std::vector<unsigned>& v : c)
        std::sort(v.begin(), v.end(), std::greater<unsigned>());

    std::pair<unsigned, unsigned long long> p[2] = {};
    while (p[0].first < c[0].size() && p[0].second < m)
        p[0].second += c[0][p[0].first++];

    unsigned v = (p[0].second >= m ? p[0].first : ~0u);
    while (p[1].first < c[1].size()) {
        p[1].second += c[1][p[1].first++];

        while (p[0].second + p[1].second >= m) {
            v = std::min(v, p[0].first + p[1].first * 2);
            if (p[0].first == 0)
                break;

            p[0].second -= c[0][--p[0].first];
        }
    }

    if (v != ~0u)
        return answer(v);

    no_answer();
}

void test_case()
{
    size_t n;
    std::cin >> n;

    unsigned m;
    std::cin >> m;

    std::vector<unsigned> a(n), b(n);
    std::cin >> a >> b;

    solve(a, b, m);
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
