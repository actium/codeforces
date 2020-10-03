#include <iostream>
#include <map>
#include <string>
#include <vector>

template <typename T, typename U>
std::istream& operator >>(std::istream& input, std::pair<T, U>& v)
{
    return input >> v.first >> v.second;
}

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(const std::map<std::string, std::string>& v)
{
    std::cout << v.size() << '\n';

    for (const std::pair<std::string, std::string>& x : v)
        std::cout << x.first << ' ' << x.second << '\n';
}

void solve(const std::vector<std::pair<std::string, std::string>>& e)
{
    std::map<std::string, std::string> d, i;
    for (const auto& c : e) {
        const auto it = i.find(c.first);
        if (it == i.end()) {
            d.emplace(c.first, c.second);
            i.emplace(c.second, c.first);
        } else {
            d[it->second] = c.second;
            i.emplace(c.second, it->second);
            i.erase(it);
        }
    }

    answer(d);
}

int main()
{
    size_t q;
    std::cin >> q;

    std::vector<std::pair<std::string, std::string>> e(q);
    std::cin >> e;

    solve(e);

    return 0;
}

