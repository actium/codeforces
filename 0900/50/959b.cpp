#include <iostream>
#include <map>
#include <string>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(unsigned long long v)
{
    std::cout << v << '\n';
}

void solve(const std::map<std::string, unsigned>& c, const std::vector<std::string>& t)
{
    unsigned long long s = 0;
    for (const std::string& x : t)
        s += c.find(x)->second;

    answer(s);
}

int main()
{
    size_t n, k, m;
    std::cin >> n >> k >> m;

    std::vector<std::string> w(n);
    std::cin >> w;

    std::vector<unsigned> a(n);
    std::cin >> a;

    std::map<std::string, unsigned> c;
    for (size_t i = 0; i < k; ++i) {
        size_t x;
        std::cin >> x;

        std::vector<unsigned> g(x);
        std::cin >> g;

        unsigned b = ~0u;
        for (const unsigned i : g)
            b = std::min(b, a[i-1]);

        for (const unsigned i : g)
            c.emplace(w[i-1], b);
    }

    std::vector<std::string> t(m);
    std::cin >> t;

    solve(c, t);

    return 0;
}

