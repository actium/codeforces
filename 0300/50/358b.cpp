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
    constexpr const char* s[2] = { "no", "yes" };
    std::cout << s[v] << '\n';
}

void solve(const std::vector<std::string>& w, const std::string& s)
{
    std::string t;
    for (const std::string& x : w) {
        t.append("<3");
        t.append(x);
    }
    t.append("<3 ");

    size_t x = 0;
    for (const char c : s)
        x += (c == t[x]);

    answer(x + 1 == t.length());
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    std::vector<std::string> w(n);
    std::cin >> w;

    std::string s;
    std::cin >> s;

    solve(w, s);

    return 0;
}
