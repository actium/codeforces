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

bool check(int x1, int y1, int x2, int y2, int x3, int y3)
{
    const int dx12 = x2 - x1;
    const int dy12 = y2 - y1;
    const int dx13 = x3 - x1;
    const int dy13 = y3 - y1;
    return dx12 * dy13 - dx13 * dy12 <= 0;
}

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(unsigned n, unsigned d, std::vector<std::pair<int, int>>& g)
{
    for (const auto& p : g) {
        answer(check(0, d, n-d, n, p.first, p.second)
            && check(n-d, n, n, n-d, p.first, p.second)
            && check(n, n-d, d, 0, p.first, p.second)
            && check(d, 0, 0, d, p.first, p.second));
    }
}

int main()
{
    unsigned n, d;
    std::cin >> n >> d;

    size_t m;
    std::cin >> m;

    std::vector<std::pair<int, int>> g(m);
    std::cin >> g;

    solve(n, d, g);

    return 0;
}

