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

void answer(bool v)
{
    constexpr const char* s[2] = { "WA", "ACC" };
    std::cout << s[v] << '\n';
}

void solve(std::vector<std::string>& s, const std::vector<std::string>& t)
{
    const auto normalize = [](const std::string& s) {
        std::string t;
        for (const char c : s) {
            if (isalpha(c))
                t.push_back(tolower(c));
        }
        return t;
    };

    for (std::string& x : s)
        x = normalize(x);

    std::set<std::string> p = {
        s[0] + s[1] + s[2],
        s[0] + s[2] + s[1],
        s[1] + s[0] + s[2],
        s[1] + s[2] + s[0],
        s[2] + s[0] + s[1],
        s[2] + s[1] + s[0],
    };

    for (const std::string& q : t)
        answer(p.count(normalize(q)) == 1);
}

int main()
{
    std::vector<std::string> s(3);
    std::cin >> s;

    size_t n;
    std::cin >> n;

    std::vector<std::string> t(n);
    std::cin >> t;

    solve(s, t);

    return 0;
}

