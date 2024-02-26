#include <algorithm>
#include <iostream>
#include <vector>

using integer = unsigned long long;

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(integer x)
{
    std::cout << x << '\n';
}

unsigned explore(const std::vector<unsigned>& p, size_t u, std::vector<bool>& v)
{
    if (v[u])
        return 0;

    v[u] = true;
    return 1 + explore(p, p[u] - 1, v);
}

void solve(const std::vector<unsigned>& p)
{
    const size_t n = p.size();

    std::vector<unsigned> s;
    {
        std::vector<bool> v(n);
        for (size_t i = 0; i < n; ++i) {
            if (!v[i])
                s.push_back(explore(p, i, v));
        }
    }

    if (s.size() > 1) {
        std::nth_element(s.begin(), s.begin() + 2, s.end(), std::greater<unsigned>());
        s[1] += s[0];
        s[0] = 0;
    }

    integer t = 0;
    for (const integer x : s)
        t += x * x;

    answer(t);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    std::vector<unsigned> p(n);
    std::cin >> p;

    solve(p);

    return 0;
}
