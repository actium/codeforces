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

void answer(bool v)
{
    constexpr const char* s[2] = { "No", "Yes" };
    std::cout << s[v] << '\n';
}

std::string n(const std::string& s)
{
    std::string t;
    for (char c : s) {
        c = std::tolower(c);

        if (c == 'o')
            c = '0';

        if (c == 'i' || c == 'l')
            c = '1';

        t.push_back(c);
    }
    return t;
}

void solve(const std::vector<std::string>& r, const std::string& x)
{
    for (const std::string& q : r) {
        if (n(q) == n(x))
            return answer(false);
    }

    answer(true);
}

int main()
{
    std::string x;
    std::cin >> x;

    size_t n;
    std::cin >> n;

    std::vector<std::string> r(n);
    std::cin >> r;

    solve(r, x);

    return 0;
}

