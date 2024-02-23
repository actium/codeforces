#include <iostream>
#include <map>
#include <vector>

constexpr unsigned oo = ~0u;

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

void solve(const std::vector<std::pair<unsigned, unsigned>>& c)
{
    const unsigned x = (c.size() + 1) / 2;

    std::map<unsigned, unsigned> f, g;
    for (const std::pair<unsigned, unsigned>& q : c) {
        if (++f[q.first] == x)
            return answer(0);

        if (q.second != q.first)
            ++g[q.second];
    }

    unsigned k = oo;
    for (const auto& e : g) {
        if (e.second + f[e.first] >= x)
            k = std::min(k, x - f[e.first]);
    }

    k != oo ? answer(k) : no_answer();
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    std::vector<std::pair<unsigned, unsigned>> c(n);
    std::cin >> c;

    solve(c);

    return 0;
}
