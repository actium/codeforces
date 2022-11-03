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

void answer(char x)
{
    std::cout << x << '\n';
}

void solve(const std::vector<std::string>& g)
{
    for (const std::string& s : g) {
        if (s == std::string(8, 'R'))
            return answer('R');
    }

    answer('B');
}

void test_case()
{
    std::vector<std::string> g(8);
    std::cin >> g;

    solve(g);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
