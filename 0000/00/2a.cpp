#include <iostream>
#include <map>
#include <set>
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

void answer(const std::string& x)
{
    std::cout << x << '\n';
}

void solve(const std::vector<std::pair<std::string, int>>& s)
{
    std::map<std::string, int> v;
    for (const std::pair<std::string, int>& e : s)
        v[e.first] += e.second;

    int m = 0;
    for (const std::pair<std::string, int>& e : v)
        m = std::max(m, e.second);

    std::set<std::string> w;
    for (const std::pair<std::string, int>& e : v) {
        if (e.second == m)
            w.insert(e.first);
    }

    if (w.size() == 1)
        return answer(*w.begin());

    v.clear();
    for (const std::pair<std::string, int>& e : s) {
        if (w.count(e.first) == 0)
            continue;

        int& x = v[e.first];
        x += e.second;
        if (x >= m)
            return answer(e.first);
    }
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<std::pair<std::string, int>> s(n);
    std::cin >> s;

    solve(s);

    return 0;
}
