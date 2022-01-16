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

void solve(std::vector<unsigned>& p)
{
    const size_t n = p.size();

    std::vector<size_t> s;
    for (size_t i = n; i-- > 0; ) {
        if (s.empty() || p[i] < p[s.back()])
            s.push_back(i);
    }

    for (size_t b = 0; !s.empty(); s.pop_back()) {
        for (size_t i = s.back(); i > b && p[i] < p[i-1]; --i)
            std::swap(p[i], p[i-1]);

        b = s.back();
    }

    answer(p);
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
