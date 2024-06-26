#include <iostream>
#include <set>
#include <string>
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
    for (unsigned i = 24; i != 0; i -= 8)
        std::cout << (x >> i & 0xFF) << '.';

    std::cout << (x & 0xFF) << '\n';
}

void no_answer()
{
    std::cout << -1 << '\n';
}

void solve(const std::vector<std::string>& a, size_t k)
{
    const size_t n = a.size();

    std::vector<unsigned> b(n);
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0, x = 0; j < 4; ++j) {
            size_t p = a[i].find('.', x);
            if (p == std::string::npos)
                p = a[i].length();

            b[i] <<= 8;
            b[i] += std::stoi(a[i].substr(x, p - x));
            x = p + 1;
        }
    }

    for (unsigned c = 31; c > 0; --c) {
        const unsigned m = ~0u << c;

        std::set<unsigned> s;
        for (size_t i = 0; i < n; ++i)
            s.insert(b[i] & m);

        if (s.size() == k)
            return answer(m);
    }

    no_answer();
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n, k;
    std::cin >> n >> k;

    std::vector<std::string> a(n);
    std::cin >> a;

    solve(a, k);

    return 0;
}
