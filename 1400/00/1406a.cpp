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
    unsigned f[102] = {};
    for (const unsigned x : a)
        ++f[x];

    unsigned i = 0;
    while (i < 102 && f[i] > 0) {
        --f[i];
        ++i;
    }

    unsigned j = 0;
    while (j < 102 && f[j] > 0) {
        --f[j];
        ++j;
    }

    answer(i + j);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

