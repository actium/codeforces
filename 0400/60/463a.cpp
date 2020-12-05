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

void solve(const std::vector<std::pair<unsigned, unsigned>>& c, unsigned s)
{
    int r = -1;
    for (const auto& x : c) {
        if (x.first * 100 + x.second <= s * 100)
            r = std::max<int>(r, (100 - x.second) % 100);
    }

    answer(r);
}

int main()
{
    size_t n;
    std::cin >> n;

    unsigned s;
    std::cin >> s;

    std::vector<std::pair<unsigned, unsigned>> c(n);
    std::cin >> c;

    solve(c, s);

    return 0;
}

