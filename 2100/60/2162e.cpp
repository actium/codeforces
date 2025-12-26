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
    const char* separator = "";
    for (const unsigned x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void solve(const std::vector<unsigned>& a, size_t k)
{
    const size_t n = a.size();

    std::vector<bool> v(1+n);
    for (const unsigned x : a)
        v[x] = true;

    unsigned x = 1;
    while (x <= n && v[x])
        ++x;

    std::vector<unsigned> p;
    if (x <= n) {
        unsigned y = 1;
        while (y == x || y == a.back())
            ++y;

        p.push_back(x);
        p.push_back(y);
        p.push_back(a.back());
    } else {
        p.push_back(a[0]);
        p.push_back(a[1]);
        p.push_back(a[2]);
    }

    while (p.size() < k) {
        const std::vector<unsigned> t(p.begin(), p.end());
        p.insert(p.end(), t.begin(), t.end());
    }
    p.resize(k);

    answer(p);
}

void test_case()
{
    size_t n, k;
    std::cin >> n >> k;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a, k);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
