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
    const char* separator = "";
    for (const size_t x : v) {
        std::cout << separator << 1+x;
        separator = " ";
    }
    std::cout << '\n';
}

void no_answer()
{
    std::cout << -1 << '\n';
}

void solve(const std::vector<unsigned>& s)
{
    const size_t n = s.size();

    std::vector<size_t> p;
    for (size_t i = 0, j = 1; j < n; ++j) {
        if (s[j] == s[i]) {
            p.push_back(j);
        } else if (j - i > 1) {
            p.push_back(i);
            i = j;
        } else {
            return no_answer();
        }
    }

    answer(p);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> s(n);
    std::cin >> s;

    s.push_back(0);     // sentinel
    solve(s);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
