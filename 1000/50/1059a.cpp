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

void solve(const std::vector<std::pair<unsigned, unsigned>>& c, unsigned l, unsigned a)
{
    unsigned t = 0, k = 0;
    for (const auto& x : c) {
        k += (x.first - t) / a;
        t = x.first + x.second;
    }

    k += (l - t) / a;

    answer(k);
}

int main()
{
    size_t n;
    std::cin >> n;

    unsigned l, a;
    std::cin >> l >> a;

    std::vector<std::pair<unsigned, unsigned>> c(n);
    std::cin >> c;

    solve(c, l, a);

    return 0;
}

