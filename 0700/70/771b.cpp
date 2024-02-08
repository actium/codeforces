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

void answer(const std::vector<std::string>& v)
{
    const char* separator = "";
    for (const std::string& x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void solve(const std::vector<std::string>& s, size_t k)
{
    const size_t n = s.size() + k - 1;

    std::vector<std::string> t(n);
    for (size_t i = 0; i < n; ++i) {
        if (i + 1 < k || s[i-k+1] == "YES") {
            t[i].push_back('A' + i % 26);
            t[i].push_back('a' + i / 26);
        } else {
            t[i] = t[i-k+1];
        }
    }

    answer(t);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n, k;
    std::cin >> n >> k;

    std::vector<std::string> s(n - k + 1);
    std::cin >> s;

    solve(s, k);

    return 0;
}
