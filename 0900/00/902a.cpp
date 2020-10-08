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

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(const std::vector<std::pair<unsigned, unsigned>>& d, unsigned m)
{
    unsigned x = 0;
    for (const auto& p : d) {
        if (p.first > x)
            break;

        x = std::max(x, p.second);
    }

    answer(x >= m);
}

int main()
{
    size_t n;
    std::cin >> n;

    unsigned m;
    std::cin >> m;

    std::vector<std::pair<unsigned, unsigned>> d(n);
    std::cin >> d;

    solve(d, m);

    return 0;
}

