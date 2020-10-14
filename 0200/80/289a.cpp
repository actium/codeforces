#include <iostream>
#include <vector>

using segment_t = std::pair<int, int>;

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

void solve(const std::vector<segment_t>& s, unsigned k)
{
    unsigned d = 0;
    for (const segment_t& p : s)
        d += p.second - p.first + 1;

    const unsigned r = d % k;
    answer(r == 0 ? 0 : k - r);
}

int main()
{
    size_t n;
    std::cin >> n;

    unsigned k;
    std::cin >> k;

    std::vector<segment_t> s(n);
    std::cin >> s;

    solve(s, k);

    return 0;
}

