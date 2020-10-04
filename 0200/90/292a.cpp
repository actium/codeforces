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

void answer(unsigned x, unsigned y)
{
    std::cout << x << ' ' << y << '\n';
}

void solve(const std::vector<std::pair<unsigned, unsigned>>& e)
{
    unsigned q = 0, t = 0, k = 0;
    for (const auto& x : e) {
        q = (x.first < t ? t - x.first : 0) + x.second;
        t = x.first + q;
        k = std::max(k, q);
    }

    answer(t, k);
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<std::pair<unsigned, unsigned>> e(n);
    std::cin >> e;

    solve(e);

    return 0;
}

