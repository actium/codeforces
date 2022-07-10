#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(const std::vector<std::vector<size_t>>& v)
{
    std::cout << v.size() << '\n';

    for (const std::vector<size_t>& u : v) {
        std::cout << u.size();

        const char* separator = "\n";
        for (const size_t x : u) {
            std::cout << separator << 1 + x;
            separator = " ";
        }
        std::cout << '\n';
    }
}

void make_path(const std::vector<unsigned>& p, size_t i, std::vector<size_t>& s, std::vector<bool>& v)
{
    const size_t j = p[i] - 1;
    if (!v[j] && j != i)
        make_path(p, j, s, v);

    s.push_back(i);
    v[i] = true;
}

void solve(const std::vector<unsigned>& p)
{
    const size_t n = p.size();

    std::vector<bool> z(n, true), v(n);
    for (const unsigned x : p)
        z[x-1] = false;

    if (n == 1)
        z[0] = true;

    std::vector<std::vector<size_t>> s;
    for (size_t i = 0; i < n; ++i) {
        if (!z[i])
            continue;

        std::vector<size_t> r;
        make_path(p, i, r, v);
        s.push_back(std::move(r));
    }

    answer(s);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> p(n);
    std::cin >> p;

    solve(p);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
