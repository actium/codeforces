#include <iostream>
#include <map>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(const std::vector<size_t>& v)
{
    std::cout << v.size() << '\n';

    const char* separator = "";
    for (const size_t x : v) {
        std::cout << separator << 1+x;
        separator = " ";
    }
    std::cout << '\n';
}

struct Stone {
    unsigned a;
    unsigned b;
    unsigned c;
};

std::istream& operator >>(std::istream& input, Stone& s)
{
    return input >> s.a >> s.b >> s.c;
}

void solve(const std::vector<Stone>& s)
{
    const size_t n = s.size();

    std::pair<std::vector<size_t>, unsigned> v = { {}, 0 };

    std::map<std::pair<unsigned, unsigned>, std::pair<size_t, unsigned>> p;

    const auto check = [&](size_t x, unsigned a, unsigned b, unsigned c) {
        if (a > b)
            std::swap(a, b);

        if (std::min(a, c) > v.second) {
            v.first = { x };
            v.second = std::min(a, c);
        }

        auto& u = p.emplace(std::make_pair(a, b), std::make_pair(x, c)).first->second;
        if (u.first == x)
            return;

        if (std::min(a, c + u.second) > v.second) {
            v.first = { x, u.first };
            v.second = std::min(a, c + u.second);
        }

        if (c > u.second)
            u = { x, c };
    };

    for (size_t i = 0; i < n; ++i) {
        check(i, s[i].a, s[i].b, s[i].c);
        check(i, s[i].b, s[i].c, s[i].a);
        check(i, s[i].c, s[i].a, s[i].b);
    }

    answer(v.first);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    std::vector<Stone> s(n);
    std::cin >> s;

    solve(s);

    return 0;
}
