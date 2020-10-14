#include <algorithm>
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

void answer(unsigned x, unsigned y)
{
    std::cout << x << ' ' << y << '\n';
}

void solve(std::vector<unsigned>& p, const std::vector<std::string>& o)
{
    std::map<std::string, unsigned> f;
    for (const std::string& x : o)
        ++f[x];

    std::vector<unsigned> q;
    for (const auto& e : f)
        q.push_back(e.second);

    std::sort(p.begin(), p.end(), std::greater<unsigned>());
    std::sort(q.begin(), q.end(), std::greater<unsigned>());

    unsigned s1 = 0;
    std::for_each(q.begin(), q.end(), [it = p.rbegin(), &s1](unsigned x) mutable { s1 += *it++ * x; });

    unsigned s2 = 0;
    std::for_each(q.begin(), q.end(), [it = p.begin(), &s2](unsigned x) mutable { s2 += *it++ * x; });

    answer(s1, s2);
}

int main()
{
    size_t n, m;
    std::cin >> n >> m;

    std::vector<unsigned> p(n);
    std::cin >> p;

    std::vector<std::string> o(m);
    std::cin >> o;

    solve(p, o);

    return 0;
}

