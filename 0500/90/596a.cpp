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

void solve(const std::vector<std::pair<int, int>>& v)
{
    const size_t n = v.size();

    int dx = 0, dy = 0;
    for (size_t i = 1; i < n; ++i) {
        for (size_t j = 0; j < i; ++j) {
            dx = std::max(dx, abs(v[i].first - v[j].first));
            dy = std::max(dy, abs(v[i].second - v[j].second));
        }
    }

    answer(dx == 0 || dy == 0 ? -1 : dx * dy);
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<std::pair<int, int>> v(n);
    std::cin >> v;

    solve(v);

    return 0;
}

