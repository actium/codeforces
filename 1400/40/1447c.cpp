#include <algorithm>
#include <iostream>
#include <vector>

using integer = unsigned long long;

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void no_answer()
{
    std::cout << -1 << '\n';
}

void answer(const std::vector<size_t>& v)
{
    std::cout << v.size() << '\n';

    const char* separator = "";
    for (const size_t x : v) {
        std::cout << separator << 1+x;
        separator = " ";
    }
    std::cout << '\n';
}

void solve(const std::vector<unsigned>& w, integer s)
{
    const size_t n = w.size();

    std::vector<size_t> x(n);
    for (size_t i = 0; i < n; ++i)
        x[i] = i;

    std::sort(x.begin(), x.end(), [&w](size_t a, size_t b) { return w[a] > w[b]; });

    std::vector<size_t> j;
    integer c = 0;
    for (size_t i : x) {
        if (c + w[i] <= s) {
            j.push_back(i);
            c += w[i];
        }
    }

    if (j.empty() || c < (s+1)/2)
        return no_answer();

    answer(j);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    integer s;
    std::cin >> s;

    std::vector<unsigned> w(n);
    std::cin >> w;

    solve(w, s);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

