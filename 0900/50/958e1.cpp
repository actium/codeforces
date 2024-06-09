#include <iostream>
#include <vector>

using point_t = std::pair<int, int>;

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

void answer(bool v)
{
    constexpr const char* s[2] = { "No", "Yes" };
    std::cout << s[v] << '\n';
}

void solve(const std::vector<point_t>& s, const std::vector<point_t>& t)
{
    answer(s.size() == t.size());
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t r, b;
    std::cin >> r >> b;

    std::vector<point_t> p(r), q(b);
    std::cin >> p >> q;

    solve(p, q);

    return 0;
}
