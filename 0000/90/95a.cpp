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

void solve(const std::vector<std::string>& s, std::string& w, char x)
{
    const size_t n = w.length();

    const auto search = [&](auto begin, const std::string& q) {
        return std::search(begin, w.end(), q.begin(), q.end(), [](char a, char b) {
            return std::tolower(a) == std::tolower(b);
        });
    };

    std::vector<bool> d(n);
    for (const std::string& q : s) {
        for (auto it = search(w.begin(), q); it != w.end(); it = search(std::next(it), q)) {
            for (size_t i = 0; i < q.length(); ++i)
                d[it-w.begin()+i] = true;
        }
    }

    for (size_t i = 0; i < n; ++i) {
        if (!d[i])
            continue;

        if (std::tolower(w[i]) == x)
            w[i] = (std::isupper(w[i]) ? 'A' : 'a') + (x == 'a');
        else
            w[i] = (std::isupper(w[i]) ? std::toupper(x) : x);
    }

    answer(w);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    std::vector<std::string> s(n);
    std::cin >> s;

    std::string w;
    std::cin >> w;

    char x;
    std::cin >> x;

    solve(s, w, x);

    return 0;
}
