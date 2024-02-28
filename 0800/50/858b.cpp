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

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void no_answer()
{
    std::cout << -1 << '\n';
}

unsigned floor(unsigned x, unsigned k)
{
    return (x + k - 1) / k;
}

void solve(const std::vector<std::pair<unsigned, unsigned>>& a, unsigned x)
{
    const auto check = [&](unsigned k) {
        for (const std::pair<unsigned, unsigned>& q : a) {
            if (q.first + k <= q.second * k || q.first > q.second * k)
                return false;
        }
        return true;
    };

    std::vector<unsigned> c;
    for (unsigned k = 1; k <= 100; ++k) {
        if (check(k))
            c.push_back(k);
    }

    if (c.empty() || floor(x, c.front()) != floor(x, c.back()))
        return no_answer();

    answer(floor(x, c[0]));
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    unsigned n;
    std::cin >> n;

    size_t m;
    std::cin >> m;

    std::vector<std::pair<unsigned, unsigned>> a(m);
    std::cin >> a;

    solve(a, n);

    return 0;
}
