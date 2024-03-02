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

void solve(std::vector<std::string>& s)
{
    for (size_t i = 0; i < s.size(); ++i) {
        for (size_t j = 0; j < s.size(); ++j) {
            if (j == i)
                continue;

            const size_t x = s[i].find(s[j][0]);
            if (x == std::string::npos)
                continue;

            if (x + s[j].length() > s[i].length())
                s[i] += s[j].substr(s[i].length() - x);

            s[j] = s.back();
            s.pop_back();

            i = -1;
            break;
        }
    }

    std::string t;
    for (const std::string& p : s)
        t += p;

    answer(t);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    std::vector<std::string> s(n);
    std::cin >> s;

    solve(s);

    return 0;
}
