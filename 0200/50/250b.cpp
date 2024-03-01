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

std::vector<std::string> split(const std::string& s)
{
    std::vector<std::string> p(1);
    for (const char c : s) {
        if (c != ':')
            p.back().push_back(c);
        else
            p.emplace_back();
    }

    size_t k = 1;
    for (size_t i = 1; i < p.size(); ++i) {
        if (!p[i].empty() || !p[k-1].empty())
            p[k++] = p[i];
    }
    p.resize(k);

    return p;
}

void answer(const std::string& x)
{
    std::cout << x << '\n';
}

void solve(const std::vector<std::string>& a)
{
    for (const std::string& q : a) {
        const std::vector<std::string> p = split(q);

        std::string t;
        for (const std::string& x : p) {
            if (!x.empty()) {
                t.append(4 - x.length(), '0');
                t.append(x);
                t.push_back(':');
            } else {
                for (size_t i = 0; i < 9 - p.size(); ++i)
                    t.append("0000:");
            }
        }
        t.pop_back();

        answer(t);
    }
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    std::vector<std::string> a(n);
    std::cin >> a;

    solve(a);

    return 0;
}
