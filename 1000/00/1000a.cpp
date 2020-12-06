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

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(const std::vector<std::string>& a, const std::vector<std::string>& b)
{
    std::multiset<std::string> u(a.cbegin(), a.cend());
    for (const std::string& x : b) {
        const auto it = u.find(x);
        if (it != u.end())
            u.erase(it);
    }

    answer(u.size());
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<std::string> a(n);
    std::cin >> a;

    std::vector<std::string> b(n);
    std::cin >> b;

    solve(a, b);

    return 0;
}

