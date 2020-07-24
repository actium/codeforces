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

void solve(const std::vector<std::pair<unsigned, unsigned>>& d, unsigned x)
{
    unsigned t = 1, k = 0;
    for (const auto [l, r] : d) {
        t += (l - t) / x * x;
        k += r - t + 1;
        t = r + 1;
    }

    answer(k);
}

int main()
{
    size_t n;
    std::cin >> n;

    unsigned x;
    std::cin >> x;

    std::vector<std::pair<unsigned, unsigned>> d(n);
    std::cin >> d;

    solve(d, x);

    return 0;
}

