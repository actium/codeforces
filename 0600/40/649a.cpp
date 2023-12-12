#include <iostream>
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

void solve(const std::vector<unsigned>& a)
{
    unsigned r = 1, k = a.size();
    for (unsigned i = 1; i <= 30; ++i) {
        unsigned p = 1 << i, q = 0;
        for (const unsigned x : a)
            q += (x % p == 0);

        if (q != 0) {
            r = p;
            k = q;
        }
    }

    answer(r, k);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a);

    return 0;
}
