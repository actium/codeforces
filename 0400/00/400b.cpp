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

void no_answer()
{
    std::cout << -1 << '\n';
}

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(const std::vector<std::string>& g)
{
    std::set<unsigned> d;
    for (const std::string& s : g) {
        for (size_t p = 0, q; p = s.find('G', p), p != std::string::npos; p = q + 1) {
            q = s.find('S', p + 1);
            if (q == std::string::npos)
                return no_answer();

            d.insert(q - p);
        }
    }

    answer(d.size());
}

int main()
{
    size_t n, m;
    std::cin >> n >> m;

    std::vector<std::string> g(n);
    std::cin >> g;

    solve(g);

    return 0;
}

