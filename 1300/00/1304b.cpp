#include <algorithm>
#include <iostream>
#include <set>
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
    std::cout << v.size() << '\n';
    std::cout << v << '\n';
}

void solve(const std::vector<std::string>& a)
{
    std::string p, q;

    std::set<std::string> v;
    for (const std::string& s : a) {
        std::string t = s;
        std::reverse(t.begin(), t.end());

        if (v.count(t) != 0)
            p += s;
        else
            v.insert(s);

        if (t == s)
            q = s;
    }

    std::string r = p;
    std::reverse(r.begin(), r.end());

    answer(p + q + r);
}

int main()
{
    size_t n, m;
    std::cin >> n >> m;

    std::vector<std::string> a(n);
    std::cin >> a;

    solve(a);

    return 0;
}

