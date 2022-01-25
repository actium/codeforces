#include <iostream>
#include <set>
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
    std::cout << v.size() << '\n';

    const char* separator = "";
    for (const unsigned x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void solve(const std::vector<unsigned>& a)
{
    const size_t n = a.size();

    std::vector<unsigned> f(1+n), mex(n+1);
    for (size_t i = n; i-- > 0; ) {
        ++f[a[i]];

        for (mex[i] = mex[i+1]; f[mex[i]] != 0; ++mex[i]);
    }

    std::vector<unsigned> b;
    for (size_t i = 0; i < n; ) {
        const unsigned x = mex[i];
        b.push_back(mex[i]);

        std::set<unsigned> s;
        do {
            if (a[i] < x)
                s.insert(a[i]);
        } while (++i < n && s.size() != x);
    }

    answer(b);
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
