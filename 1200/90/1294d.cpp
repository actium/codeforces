#include <iostream>
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

void solve(const std::vector<unsigned>& r, unsigned x)
{
    std::vector<unsigned> s(x);
    for (unsigned i = 0; i < x; ++i)
        s[i] = i;

    unsigned t = 0;
    for (const unsigned q : r) {
        s[q % x] += x;

        while (t < s[t % x])
            ++t;

        answer(t);
    }
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t q;
    std::cin >> q;

    unsigned x;
    std::cin >> x;

    std::vector<unsigned> r(q);
    std::cin >> r;

    solve(r, x);

    return 0;
}
