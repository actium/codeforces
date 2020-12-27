#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(const std::vector<unsigned>& a)
{
    constexpr unsigned oo = ~0u;

    unsigned s = 0, q = oo;
    for (const unsigned x : a) {
        s += x;

        if (x % 2 == 1)
            q = std::min(q, x);
    }

    if (s % 2 == 1)
        return answer(s);

    answer(q == oo ? 0 : s - q);
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

