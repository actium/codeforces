#include <iostream>
#include <vector>

using distance_t = std::pair<int, int>;

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

void answer(int x, int y)
{
    std::cout << x << ' ' << y << '\n';
}

void solve(const std::vector<distance_t>& p, const std::vector<distance_t>& d)
{
    const size_t n = p.size();

    long long sx = 0, sy = 0;
    for (size_t i = 0; i < n; ++i) {
        sx+= p[i].first + d[i].first;
        sy += p[i].second + d[i].second;
    }

    answer(sx / n, sy / n);
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<distance_t> p(n);
    std::cin >> p;

    std::vector<distance_t> d(n);
    std::cin >> d;

    solve(p, d);

    return 0;
}

