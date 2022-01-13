#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using integer = unsigned long long;

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(const std::vector<integer>& v)
{
    const char* separator = "";
    for (const integer x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

bool search(std::multiset<integer>& a, integer x, std::vector<integer>& b)
{
    const auto it = a.find(x);
    if (it == a.end())
        return false;

    a.erase(it);
    b.push_back(x);

    if (a.empty())
        return true;

    if (x % 2 == 0 && search(a, x / 2, b))
        return true;

    if (search(a, x * 3, b))
        return true;

    b.pop_back();
    a.insert(x);

    return false;
}

void solve(const std::vector<integer>& a)
{
    std::vector<integer> b;

    std::multiset<integer> s(a.cbegin(), a.cend());
    for (size_t i = 0; !search(s, a[i], b); ++i);

    std::reverse(b.begin(), b.end());
    answer(b);
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<integer> a(n);
    std::cin >> a;

    solve(a);

    return 0;
}
