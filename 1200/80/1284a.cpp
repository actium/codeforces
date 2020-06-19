#include <iostream>
#include <string>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(const std::string& v)
{
    std::cout << v << '\n';
}

void solve(const std::vector<std::string>& s, const std::vector<std::string>& t, size_t y)
{
    answer(s[y % s.size()] + t[y % t.size()]);
}

int main()
{
    size_t n, m;
    std::cin >> n >> m;

    std::vector<std::string> s(n);
    std::cin >> s;

    std::vector<std::string> t(m);
    std::cin >> t;

    unsigned q;
    std::cin >> q;

    for (unsigned i = 0; i < q; ++i) {
        unsigned y;
        std::cin >> y;

        solve(s, t, y-1);
    }

    return 0;
}

