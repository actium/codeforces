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

void solve(const std::vector<unsigned>& c, unsigned k, unsigned x)
{
    const size_t n = c.size();

    std::vector<std::pair<unsigned, unsigned>> p;
    for (const unsigned q : c) {
        if (p.empty() || q != p.back().first)
            p.emplace_back(q, 1);
        else
            ++p.back().second;
    }

    const size_t m = p.size();

    const auto count = [m, &p](size_t x) {
        unsigned q = p[x].second;
        for (size_t i = x, j = x; i-- > 0 && ++j < m && p[i].first == p[j].first; ) {
            const unsigned k = p[i].second + p[j].second;
            if (k < 3)
                break;

            q += k;
        }
        return q;
    };

    unsigned q = 0;
    for (size_t i = 0; i < m; ++i) {
        if (p[i].first == x && p[i].second == 2)
            q = std::max(q, count(i));
    }

    answer(q);
}

int main()
{
    size_t n;
    std::cin >> n;

    unsigned k, x;
    std::cin >> k >> x;

    std::vector<unsigned> c(n);
    std::cin >> c;

    solve(c, k, x);

    return 0;
}
