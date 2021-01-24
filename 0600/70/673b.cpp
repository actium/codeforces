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

void solve(size_t n, const std::vector<std::pair<unsigned, unsigned>>& s)
{
    unsigned e1 = 1, b2 = n;
    for (auto [u, v] : s) {
        if (u > v)
            std::swap(u, v);

        e1 = std::max(e1, u);
        b2 = std::min(b2, v);
    }

    answer(e1 < b2 ? b2 - e1 : 0);
}

int main()
{
    size_t n, m;
    std::cin >> n >> m;

    std::vector<std::pair<unsigned, unsigned>> s(m);
    std::cin >> s;

    solve(n, s);

    return 0;
}

