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

void answer(const std::vector<std::string>& v)
{
    for (const std::string& x : v)
        std::cout << x << '\n';
}

void solve(const std::vector<std::string>& s)
{
    std::vector<std::string> v;

    std::map<std::string, unsigned> x;
    for (const std::string& n : s) {
        const auto it = x.find(n);
        if (it == x.end()) {
            v.push_back("OK");
            x.emplace(n, 1);
        } else {
            v.push_back(n + std::to_string(it->second));
            ++it->second;
        }
    }

    answer(v);
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

