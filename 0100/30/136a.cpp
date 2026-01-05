#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

template <typename T>
void answer(const std::vector<T>& v)
{
    const char* separator = "";
    for (const T a : v) {
        std::cout << separator << a;
        separator = " ";
    }
}

void solve(const std::vector<size_t>& p)
{
    const size_t n = p.size();

    std::vector<size_t> s(n);
    for (size_t i = 0; i < n; ++i)
        s[p[i]-1] = i+1;

    answer(s);
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<size_t> p(n);
    std::cin >> p;

    solve(p);

    return 0;
}

