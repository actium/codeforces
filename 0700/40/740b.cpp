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

void answer(unsigned v)
{
    std::cout << v << '\n';
}

using segment_t = std::pair<unsigned, unsigned>;

void solve(const std::vector<int>& a, const std::vector<segment_t>& s)
{
    const size_t n = a.size(), m = s.size();

    std::vector<int> p = a;
    for (size_t i = 1; i < n; ++i)
        p[i] += p[i-1];

    unsigned d = 0;
    for (const segment_t& x : s) {
        const int h = p[x.second-1] - (x.first > 1 ? p[x.first-2] : 0);
        if (h > 0)
            d += h;
    }

    answer(d);
}

int main()
{
    size_t n, m;
    std::cin >> n >> m;

    std::vector<int> a(n);
    std::cin >> a;

    std::vector<segment_t> s(m);
    std::cin >> s;

    solve(a, s);

    return 0;
}

