#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void no_answer()
{
    std::cout << "NO" << '\n';
}

void answer(const std::vector<size_t>& v)
{
    std::cout << "YES" << '\n';

    const char* separator = "";
    for (const size_t x : v) {
        std::cout << separator << 1+x;
        separator = " ";
    }
    std::cout << '\n';
}

void solve(const std::vector<unsigned>& a, size_t k)
{
    const size_t n = a.size();

    std::vector<size_t> r;
    for (size_t i = 0; i < n; ++i) {
        if (a[i] % 2 == 1)
            r.push_back(i);
    }

    if (r.size() >= k && r.size() % 2 == k % 2) {
        r.resize(k);
        r.back() = n-1;
        return answer(r);
    }

    no_answer();
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
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

