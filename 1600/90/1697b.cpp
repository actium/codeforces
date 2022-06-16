#include <algorithm>
#include <iostream>
#include <vector>

using integer = unsigned long long;

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

void answer(integer x)
{
    std::cout << x << '\n';
}

void solve(std::vector<unsigned>& p, const std::vector<std::pair<unsigned, unsigned>>& r)
{
    const size_t n = p.size();

    std::sort(p.begin(), p.end(), std::greater<unsigned>());

    std::vector<integer> ps(1 + n);
    for (size_t i = 0; i < n; ++i)
        ps[1+i] = ps[i] + p[i];

    for (const std::pair<unsigned, unsigned>& q : r) {
        const unsigned x = q.first, y = q.second;
        answer(ps[x] - ps[x-y]);
    }
}

int main()
{
    size_t n, q;
    std::cin >> n >> q;

    std::vector<unsigned> p(n);
    std::cin >> p;

    std::vector<std::pair<unsigned, unsigned>> r(q);
    std::cin >> r;

    solve(p, r);

    return 0;
}
