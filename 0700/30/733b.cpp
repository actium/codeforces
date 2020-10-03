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

void solve(const std::vector<std::pair<unsigned, unsigned>>& a)
{
    const size_t n = a.size();

    unsigned s[2] = {};
    for (const auto& e : a) {
        s[0] += e.first;
        s[1] += e.second;
    }

    std::pair<unsigned, size_t> x = { abs(s[0] - s[1]), n };
    for (size_t i = 0; i < n; ++i) {
        const auto& e = a[i];

        const unsigned d = abs((s[0] - e.first + e.second) - (s[1] + e.first - e.second));
        if (d > x.first) {
            x.first = d;
            x.second = i;
        }
    }

    answer(x.second < n ? 1 + x.second : 0);
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<std::pair<unsigned, unsigned>> a(n);
    std::cin >> a;

    solve(a);

    return 0;
}

