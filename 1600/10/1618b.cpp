#include <iostream>
#include <string>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(const std::string& x)
{
    std::cout << x << '\n';
}

void solve(const std::vector<std::string>& b)
{
    const size_t n = b.size();

    std::string s = b[0];
    for (size_t i = 1; i < n; ++i) {
        if (b[i].front() != s.back())
            s.push_back(b[i--].front());
        else
            s.push_back(b[i].back());
    }

    if (s.length() < n + 2)
        s.push_back(s.back());

    answer(s);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<std::string> b(n-2);
    std::cin >> b;

    solve(b);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
