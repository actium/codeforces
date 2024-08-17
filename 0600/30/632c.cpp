#include <algorithm>
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

void solve(std::vector<std::string>& a)
{
    std::sort(a.begin(), a.end(), [](const std::string& lhs, const std::string& rhs) {
        return lhs + rhs < rhs + lhs;
    });

    std::string t;
    for (const std::string& s : a)
        t.append(s);

    answer(t);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    std::vector<std::string> a(n);
    std::cin >> a;

    solve(a);

    return 0;
}
