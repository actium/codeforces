#include <algorithm>
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

bool check(const std::vector<unsigned>& a, const std::vector<unsigned>& b, unsigned x)
{
    for (const unsigned u : a) {
        if (std::all_of(b.begin(), b.end(), [u, x](unsigned v) { return ((u & v) | x) != x; }))
            return false;
    }
    return true;
}

void solve(const std::vector<unsigned>& a, const std::vector<unsigned>& b)
{
    for (unsigned x = 0; x < 512; ++x) {
        if (check(a, b, x))
            return answer(x);
    }
}

int main()
{
    size_t n, m;
    std::cin >> n >> m;

    std::vector<unsigned> a(n);
    std::cin >> a;

    std::vector<unsigned> b(m);
    std::cin >> b;

    solve(a, b);

    return 0;
}

