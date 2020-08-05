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

void answer(int v)
{
    std::cout << v << '\n';
}

void solve(const std::vector<std::pair<unsigned, unsigned>>& c, unsigned x)
{
    const size_t n = c.size();

    unsigned l = std::min(c[0].first, c[0].second);
    unsigned r = std::max(c[0].first, c[0].second);
    for (size_t i = 1; i < n; ++i) {
        l = std::max(l, std::min(c[i].first, c[i].second));
        r = std::min(r, std::max(c[i].first, c[i].second));
    }

    if (l > r)
        return answer(-1);

    if (l <= x && x <= r)
        return answer(0);

    answer(x < l ? l - x : x - r);
}

int main()
{
    size_t n;
    std::cin >> n;

    unsigned x;
    std::cin >> x;

    std::vector<std::pair<unsigned, unsigned>> d(n);
    std::cin >> d;

    solve(d, x);

    return 0;
}

