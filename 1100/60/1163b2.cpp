#include <iostream>
#include <map>
#include <set>
#include <vector>

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

void solve(const std::vector<unsigned>& u)
{
    const size_t n = u.size();

    std::map<unsigned, unsigned> f;
    std::multiset<unsigned> s;

    const auto check = [&] {
        if (f.size() == 1)
            return true;

        if (*s.begin() == 1 && *std::next(s.begin()) == *s.rbegin())
            return true;

        return *s.begin() == *std::next(s.rbegin()) && *s.begin() + 1 == *s.rbegin();
    };

    unsigned k = 0;
    for (size_t i = 0; i < n; ++i) {
        const unsigned q = ++f[u[i]];
        if (q != 1)
            s.erase(s.find(q-1));

        s.insert(q);

        if (check())
            k = i + 1;
    }

    answer(k);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    std::vector<unsigned> u(n);
    std::cin >> u;

    solve(u);

    return 0;
}
