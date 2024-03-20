#include <algorithm>
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

std::vector<unsigned> divisors(unsigned x)
{
    std::vector<unsigned> d = { 1, x };
    for (unsigned i = 2; i * i <= x; ++i) {
        if (x % i != 0)
            continue;

        d.push_back(i);
        if (i * i != x)
            d.push_back(x / i);
    }
    return d;
}

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void no_answer()
{
    std::cout << -1 << '\n';
}

void solve(unsigned a, unsigned b, const std::vector<std::pair<unsigned, unsigned>>& q)
{
    std::vector<unsigned> da = divisors(a), db = divisors(b);

    std::sort(da.begin(), da.end());
    std::sort(db.begin(), db.end());

    std::vector<unsigned> cd;
    for (const unsigned x : da) {
        if (std::binary_search(db.begin(), db.end(), x))
            cd.push_back(x);
    }

    for (const std::pair<unsigned, unsigned>& r : q) {
        auto it = std::upper_bound(cd.begin(), cd.end(), r.second);
        if (it != cd.begin() && *--it >= r.first) {
            answer(*it);
        } else {
            no_answer();
        }
    }
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    unsigned a, b;
    std::cin >> a >> b;

    size_t n;
    std::cin >> n;

    std::vector<std::pair<unsigned, unsigned>> q(n);
    std::cin >> q;

    solve(a, b, q);

    return 0;
}
