#include <iostream>
#include <set>
#include <string>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void solve(const std::vector<std::string>& a)
{
    std::set<std::string> v;
    for (auto it = a.rbegin(); it != a.rend(); ++it) {
        if (v.insert(*it).second)
            std::cout << *it << '\n';
    }
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<std::string> a(n);
    std::cin >> a;

    solve(a);

    return 0;
}

