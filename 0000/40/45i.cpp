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

void answer(const std::vector<int>& v)
{
    const char* separator = "";
    for (const int x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void solve(const std::vector<int>& c)
{
    std::vector<int> s, n;
    for (const int x : c) {
        if (x > 0)
            s.push_back(x);

        if (x < 0)
            n.push_back(x);
    }

    if (n.size() % 2 == 1) {
        *std::max_element(n.begin(), n.end()) = n.back();
        n.pop_back();
    }
    s.insert(s.end(), n.cbegin(), n.cend());

    if (s.empty())
        s.push_back(*std::max_element(c.cbegin(), c.cend()));

    answer(s);
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<int> c(n);
    std::cin >> c;

    solve(c);

    return 0;
}
