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

unsigned count(const std::vector<unsigned>& w, unsigned s)
{
    unsigned k = 0;

    std::map<unsigned, unsigned> c;
    for (unsigned x : w) {
        if (x < s) {
            const auto it = c.find(s - x);
            if (it != c.end() && it->second > 0) {
                --it->second;
                ++k;
            } else {
                ++c.emplace(x, 0).first->second;
            }
        }
    }

    return k;
}

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(const std::vector<unsigned>& w)
{
    unsigned k = 0;
    for (unsigned s = 2; s <= 2 * w.size(); ++s)
        k = std::max(k, count(w, s));

    answer(k);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> w(n);
    std::cin >> w;

    solve(w);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

