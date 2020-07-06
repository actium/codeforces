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

void solve(const std::vector<std::pair<unsigned, unsigned>>& s, unsigned p1, unsigned p2, unsigned p3, unsigned t1, unsigned t2)
{
    const size_t n = s.size();

    unsigned t = s[0].first, w = 0;
    for (size_t i = 0; i < n; ++i) {
        const unsigned dt = s[i].first - t;
        const unsigned d1 = std::min(dt, t1);
        const unsigned d2 = std::min(dt - d1, t2);
        const unsigned d3 = dt - d1 - d2;

        w += (d1 + s[i].second - s[i].first) * p1;
        w += d2 * p2;
        w += d3 * p3;

        t = s[i].second;
    }

    answer(w);
}

int main()
{
    unsigned n, p1, p2, p3, t1, t2;
    std::cin >> n >> p1 >> p2 >> p3 >> t1 >> t2;

    std::vector<std::pair<unsigned, unsigned>> s(n);
    std::cin >> s;

    solve(s, p1, p2, p3, t1, t2);

    return 0;
}

