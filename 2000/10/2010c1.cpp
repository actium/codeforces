#include <iostream>
#include <vector>

template <typename T = std::string_view>
std::vector<unsigned> P(T&& s)
{
    const unsigned n = s.size();

    std::vector<unsigned> p(n);
    for (unsigned i = 1, j = 0; i < n; ++i) {
        if (s[i] == s[j]) {
            p[i] = ++j;
            continue;
        }

        if (j > 0) {
            j = p[j-1];
            --i;
        }
    }
    return p;
}

void answer(const std::string& x)
{
    std::cout << "YES" << '\n';
    std::cout << x << '\n';
}

void no_answer()
{
    std::cout << "NO" << '\n';
}

void solve(const std::string& t)
{
    const std::vector<unsigned> p = P(t);

    if (2 * p.back() > p.size())
        answer(t.substr(p.size() - p.back()));
    else
        no_answer();
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    std::string t;
    std::cin >> t;

    solve(t);

    return 0;
}
