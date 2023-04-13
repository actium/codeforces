#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(const std::vector<unsigned>& v)
{
    for (const unsigned x : v)
        std::cout << x << '\n';
}

void solve(const std::vector<unsigned>& a)
{
    unsigned s = 0;
    for (const unsigned x : a)
        s += x;

    std::vector<unsigned> p = { 0 };
    unsigned x = 0;
    for (const unsigned q : a) {
        for (unsigned j = 1; j <= q; ++j) {
            const unsigned c = 100 * j / q;
            if (c == 100 * ++x / s && c > p.back())
                p.push_back(c);
        }
    }

    answer(p);
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a);

    return 0;
}
