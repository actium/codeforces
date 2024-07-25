#include <iostream>
#include <string>
#include <vector>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void no_answer()
{
    std::cout << -1 << '\n';
}

void solve(const std::string& a, const std::string& b)
{
    const size_t n = a.size();

    std::vector<size_t> x(20, 20), p[20];
    for (size_t i = 0; i < n; ++i) {
        if (a[i] == b[i])
            continue;

        if (a[i] > b[i])
            return no_answer();

        x[a[i]-'a'] = std::min<size_t>(x[a[i]-'a'], b[i]-'a');
        p[a[i]-'a'].push_back(i);
    }

    unsigned k = 0;
    for (size_t i = 0; i < 19; ++i) {
        if (p[i].empty())
            continue;

        for (const size_t j : p[i]) {
            if (b[j] - 'a' == x[i])
                continue;

            x[x[i]] = std::min<size_t>(x[x[i]], b[j]-'a');
            p[x[i]].push_back(j);
        }

        ++k;
    }

    answer(k);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::string a, b;
    std::cin >> a >> b;

    solve(a, b);
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
