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

void solve(const std::vector<unsigned>& p)
{
    size_t n = p.size();

    std::vector<unsigned> u = { 0 };
    for (size_t i = 0, x = 0; i < n; ++i) {
        if (p[i] > p[x]) {
            u.push_back(i);
            x = i;
        }
    }

    std::vector<unsigned> v;
    for (v.reserve(n); !u.empty(); u.pop_back()) {
        v.insert(v.end(), p.cbegin() + u.back(), p.cbegin() + n);
        n = u.back();
    }

    answer(v);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> p(n);
    std::cin >> p;

    solve(p);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
