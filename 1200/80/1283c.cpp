#include <iostream>
#include <vector>

#include <cassert>

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

void solve(std::vector<unsigned>& f)
{
    const size_t n = f.size();

    std::vector<unsigned> r(n);
    for (size_t i = 0; i < n; ++i) {
        if (f[i] != 0)
            r[f[i]-1] = 1 + i;
    }

    std::vector<size_t> s, t, z;
    for (size_t i = 0; i < n; ++i) {
        if (f[i] == 0 && r[i] == 0)
            z.push_back(i);

        if (f[i] == 0 && r[i] != 0)
            s.push_back(i);

        if (f[i] != 0 && r[i] == 0)
            t.push_back(i);
    }

    const auto link = [&f](std::vector<size_t>& a, std::vector<size_t>& b) {
        const size_t x = a.back();
        a.pop_back();

        const size_t y = b.back();
        b.pop_back();

        f[x] = 1 + y;

        return std::make_pair(x, y);
    };

    if (s.empty() && !z.empty()) {
        const auto p = link(z, z);
        t.push_back(p.first);
        s.push_back(p.second);
    }

    while (!z.empty()) {
        const auto p = link(s, z);
        s.push_back(p.second);
    }

    while (!s.empty())
        link(s, t);

    answer(f);
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> f(n);
    std::cin >> f;

    solve(f);

    return 0;
}
