#include <iostream>
#include <set>
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

void solve(const std::vector<unsigned>& a)
{
    unsigned x = a.back();

    std::set<unsigned> v;
    for (auto it = a.rbegin(); it != a.rend(); ++it) {
        if (v.count(*it) == 0) {
            x = *it;
            v.insert(x);
        }
    }

    answer(x);
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a);

    return 0;
}

