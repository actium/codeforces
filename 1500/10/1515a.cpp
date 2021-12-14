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

void answer(const std::vector<unsigned>& v)
{
    std::cout << "YES" << '\n';

    const char* separator = "";
    for (const unsigned x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void no_answer()
{
    std::cout << "NO" << '\n';
}

void solve(std::vector<unsigned>& w, unsigned x)
{
    const size_t n = w.size();

    std::sort(w.begin(), w.end());

    unsigned s = 0;
    for (size_t i = 0; i < n && s < x; s += w[i++]) {
        if (s + w[i] == x)
            std::swap(w[i], w.back());
    }

    s != x ? answer(w) : no_answer();
}

void test_case()
{
    size_t n;
    std::cin >> n;

    unsigned x;
    std::cin >> x;

    std::vector<unsigned> w(n);
    std::cin >> w;

    solve(w, x);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
