#include <deque>
#include <iostream>
#include <string>

template <typename T>
std::istream& operator >>(std::istream& input, std::deque<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(const std::string& x)
{
    std::cout << x << '\n';
}

void solve(std::deque<unsigned>& p)
{
    std::string s;
    while (!p.empty()) {
        if ((s.length() % 2 == 0) == (p.back() > p.front())) {
            s.push_back('R');
            p.pop_back();
        } else {
            s.push_back('L');
            p.pop_front();
        }
    }

    answer(s);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::deque<unsigned> p(n);
    std::cin >> p;

    solve(p);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
