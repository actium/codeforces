#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(int v)
{
    std::cout << v << '\n';
}

void solve(const std::vector<unsigned>& a, const std::vector<unsigned>& b)
{
    unsigned fa[5] = {};
    for (const unsigned x : a)
        ++fa[x-1];

    unsigned fb[5] = {};
    for (const unsigned x : b)
        ++fb[x-1];

    unsigned k = 0;
    for (size_t i = 0; i < 5; ++i) {
        const unsigned c = fa[i] + fb[i];
        if (c % 2 != 0)
            return answer(-1);

        k += (std::max(fa[i], fb[i]) - std::min(fa[i], fb[i])) / 2;
    }

    answer(k / 2);
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> a(n);
    std::cin >> a;

    std::vector<unsigned> b(n);
    std::cin >> b;

    solve(a, b);

    return 0;
}

