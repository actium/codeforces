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

void answer(const std::string& v)
{
    std::cout << v << '\n';
}

void solve(const std::string& p, const std::vector<std::string>& s)
{
    std::string t;
    for (const std::string& q : s) {
        if (q.substr(0, p.length()) != p)
            continue;

        if (t.empty() || q < t)
            t = q;
    }

    answer(t.empty() ? p : t);
}

int main()
{
    std::string p;
    std::cin >> p;

    size_t n;
    std::cin >> n;

    std::vector<std::string> s(n);
    std::cin >> s;

    solve(p, s);

    return 0;
}

