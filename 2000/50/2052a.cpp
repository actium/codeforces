#include <iostream>
#include <set>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(const std::vector<std::pair<unsigned, unsigned>>& v)
{
    std::cout << v.size() << '\n';

    for (const std::pair<unsigned, unsigned>& x : v)
        std::cout << x.first << ' ' << x.second << '\n';
}

void solve(std::vector<unsigned>& c)
{
    std::vector<std::pair<unsigned, unsigned>> p;
    {
        std::set<unsigned> s(c.begin(), c.end());
        while (c.size() > 1) {
            const auto it = s.find(c.back());

            for (auto jt = it; jt-- != s.begin(); )
                p.emplace_back(c.back(), *jt);

            for (auto jt = s.begin(); jt != s.end(); ++jt) {
                if (*jt != c.back())
                    p.emplace_back(*jt, c.back());
            }

            s.erase(it);
            c.pop_back();
        }
    }
    answer(p);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    std::vector<unsigned> c(n);
    std::cin >> c;

    solve(c);

    return 0;
}
