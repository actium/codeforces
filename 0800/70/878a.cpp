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

void answer(const std::vector<std::pair<char, unsigned>>& v)
{
    std::cout << v.size() << '\n';

    for (const std::pair<char, unsigned>& x : v)
        std::cout << x.first << ' ' << x.second << '\n';
}

void solve(const std::vector<std::pair<char, unsigned>>& q)
{
    std::vector<unsigned> b(10, 3);
    for (const std::pair<char, unsigned>& c : q) {
        for (unsigned i = 0; i < 10; ++i) {
            if (c.first == '&' && (c.second & 1 << i) == 0)
                b[i] = 0;
            if (c.first == '|' && (c.second & 1 << i) != 0)
                b[i] = 1;
            if (c.first == '^' && (c.second & 1 << i) != 0)
                b[i] ^= 1;
        }
    }

    std::vector<std::pair<char, unsigned>> p = {
        std::make_pair('&', 1023),
        std::make_pair('|', 0),
        std::make_pair('^', 0),
    };
    for (unsigned i = 0; i < 10; ++i) {
        for (unsigned j = 0; j < 3; ++j) {
            if (b[i] == j)
                p[j].second ^= 1 << i;
        }
    }

    answer(p);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    std::vector<std::pair<char, unsigned>> q(n);
    std::cin >> q;

    solve(q);

    return 0;
}
