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

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(const std::vector<unsigned>& a)
{
    std::multiset<unsigned> s(a.begin(), a.end());
    std::vector<unsigned> t;

    const auto check = [&](unsigned x) {
        s.insert(t.begin(), t.end());
        t.clear();

        while (x != 0) {
            auto it = s.find(x);
            if (it == s.end()) {
                it = std::prev(s.end());
                if (*it <= 2 * x)
                    return false;
            }
            t.push_back(*it);
            s.erase(it);
            --x;
        }
        return !s.empty();
    };

    unsigned lb = 0, ub = a.size() + 1;
    while (ub - lb > 1) {
        const unsigned mid = (lb + ub) / 2;
        (check(mid) ? lb : ub) = mid;
    }

    answer(ub);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a);
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
