#include <iostream>
#include <map>
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

void answer(const std::vector<unsigned>& v)
{
    const char* separator = "";
    for (const unsigned x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void solve(const std::vector<std::pair<unsigned, unsigned>>& s)
{
    const size_t n = s.size();

    std::map<unsigned, std::vector<unsigned>> g;
    for (const std::pair<unsigned, unsigned>& e : s) {
        g[e.first].push_back(e.second);
        g[e.second].push_back(e.first);
    }

    auto x = g.begin();
    while (x->second.size() != 1)
        ++x;

    std::vector<unsigned> p;
    while (p.size() <= n) {
        const unsigned u = x->first;

        if (x->second.size() == 1)
            x = g.find(x->second[0]);
        else
            x = g.find(x->second[0] ^ x->second.back() ^ p.back());

        p.push_back(u);
    }

    answer(p);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    std::vector<std::pair<unsigned, unsigned>> s(n);
    std::cin >> s;

    solve(s);

    return 0;
}
