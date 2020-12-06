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

void solve(size_t n, const std::vector<unsigned>& a)
{
    unsigned f[100] = {};
    for (const unsigned x : a)
        ++f[x-1];

    for (unsigned k = a.size() / n; k > 0; --k) {
        unsigned c = 0;
        for (unsigned j = 0; j < 100; ++j)
            c += f[j] / k;

        if (c >= n)
            return answer(k);
    }

    answer(0);
}

int main()
{
    size_t n, m;
    std::cin >> n >> m;

    std::vector<unsigned> a(m);
    std::cin >> a;

    solve(n, a);

    return 0;
}

