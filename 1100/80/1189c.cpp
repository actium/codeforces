#include <iostream>
#include <vector>

using range_t = std::pair<unsigned, unsigned>;

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

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(const std::vector<unsigned>& s, const std::vector<range_t>& r)
{
    const size_t n = s.size();

    std::vector<unsigned> ps(1 + n);
    for (size_t i = 0; i < n; ++i)
        ps[i+1] = ps[i] + s[i];

    for (const range_t& q : r)
        answer((ps[q.second] - ps[q.first-1]) / 10);
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> s(n);
    std::cin >> s;

    size_t q;
    std::cin >> q;

    std::vector<range_t> r(q);
    std::cin >> r;

    solve(s, r);

    return 0;
}

