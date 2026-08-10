#include <iostream>
#include <set>
#include <string>

using integer = unsigned long long;

void answer(integer x)
{
    std::cout << x << '\n';
}

void no_answer()
{
    std::cout << -1 << '\n';
}

void solve(std::string& a, const std::string& b)
{
    const size_t n = a.size();

    integer k = 0;
    for (size_t d = 0; d < 2; ++d) {
        std::set<size_t> p[2];
        for (size_t i = d; i < n; i += 2)
            p[a[i]-'0'].insert(i);
        
        for (size_t i = d; i < n; i += 2) {
            const size_t s = a[i] - '0', t = s ^ 1;
            if (a[i] != b[i]) {
                if (p[t].empty())
                    return no_answer();

                const auto it = p[t].begin();
                std::swap(a[i], a[*it]);
                k += (*it - i) / 2;

                p[s].insert(*it);
                p[t].erase(it);
            }

            p[s].erase(i);
        }
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
