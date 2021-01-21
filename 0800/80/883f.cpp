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

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(const std::vector<std::string>& w)
{
    std::set<std::string> u;
    for (const std::string& s : w) {
        std::string t;
        for (const char c : s) {
            if (c == 'h') {
                while (!t.empty() && t.back() == 'k')
                    t.pop_back();
            }
            if (c == 'u') {
                t.push_back('o');
                t.push_back('o');
            } else {
                t.push_back(c);
            }
        }
        u.insert(t);
    }

    answer(u.size());
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<std::string> w(n);
    std::cin >> w;

    solve(w);

    return 0;
}

