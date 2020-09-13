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

void no_answer()
{
    std::cout << "NO" << '\n';
}

void answer(const std::vector<std::string>& v)
{
    std::cout << "YES" << '\n';
    for (const std::string& x : v)
        std::cout << x << '\n';
}

void solve(std::vector<std::string>& s)
{
    const size_t n = s.size();

    std::sort(s.begin(), s.end(), [](const std::string& a, const std::string& b) { return a.size() < b.size(); });

    for (size_t i = 1; i < n; ++i) {
        if (s[i].find(s[i-1]) == std::string::npos)
            return no_answer();
    }

    answer(s);
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<std::string> s(n);
    std::cin >> s;

    solve(s);

    return 0;
}

