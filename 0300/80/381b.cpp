#include <iostream>
#include <map>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(const std::vector<unsigned>& v)
{
    std::cout << v.size() << '\n';

    const char* separator = "";
    for (const unsigned x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void solve(std::vector<unsigned>& b)
{
    std::map<unsigned, unsigned> f;
    for (const unsigned x : b)
        ++f[x];

    std::vector<unsigned> v;
    for (auto it = f.begin(); it != f.end(); ++it)
        v.push_back(it->first);

    for (auto it = ++f.rbegin(); it != f.rend(); ++it) {
        if (it->second > 1)
            v.push_back(it->first);
    }

    answer(v);
}

int main()
{
    size_t m;
    std::cin >> m;

    std::vector<unsigned> b(m);
    std::cin >> b;

    solve(b);

    return 0;
}

