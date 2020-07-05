#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(const std::vector<size_t>& v)
{
    std::cout << v.size();

    const char* separator = "\n";
    for (const size_t x : v) {
        std::cout << separator << 1 + x;
        separator = " ";
    }
    std::cout << '\n';
}

void solve(std::vector<unsigned>& a)
{
    const size_t n = a.size();

    std::vector<size_t> f(n+1);
    for (const unsigned x : a)
        ++f[x];

    unsigned mex = 0;
    while (mex < n && f[mex] != 0)
        ++mex;

    std::vector<size_t> k;
    for (size_t i = 0; i < n; ) {
        if (a[i] != i) {
            const unsigned j = (mex == n ? i : mex);
            k.push_back(j);

            const unsigned x = a[j];
            a[j] = mex, --f[x], ++f[mex];

            if (f[x] == 0 && x < mex)
                mex = x;
            else
                for (; mex < n && f[mex] != 0; ++mex);
        } else {
            ++i;
        }
    }

    answer(k);
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

