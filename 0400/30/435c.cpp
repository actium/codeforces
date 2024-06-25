#include <iostream>
#include <map>
#include <string>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(const std::map<int, std::string>& x)
{
    for (auto it = x.rbegin(); it != x.rend(); ++it)
        std::cout << it->second << '\n';
}

void solve(const std::vector<unsigned>& a)
{
    const size_t n = a.size();

    std::map<int, std::string> s;
    {
        int x = 0, y = 0;
        for (size_t i = 0; i < n; ++i) {
            for (unsigned d = 0; d < a[i]; ++d) {
                if (i % 2 == 0) {
                    s[y].resize(x, ' ');
                    s[y].push_back('/');
                    ++y;
                } else {
                    --y;
                    s[y].resize(x, ' ');
                    s[y].push_back('\\');
                }

                ++x;
            }
        }
        for (auto& e : s)
            e.second.resize(x, ' ');
    }

    answer(s);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a);

    return 0;
}
