#include <iostream>
#include <map>
#include <set>
#include <vector>

using integer = unsigned long long;

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

void answer(integer x)
{
    std::cout << x << '\n';
}

void solve(const std::vector<std::pair<char, integer>>& r)
{
    std::set<integer> s;
    s.insert(0);

    std::map<integer, integer> x;

    for (const std::pair<char, integer>& q : r) {
        if (q.first == '+') {
            s.insert(q.second);
        } else {
            integer& mex = x[q.second];
            while (s.count(mex) == 1)
                mex += q.second;

            answer(mex);
        }
    }
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t q;
    std::cin >> q;

    std::vector<std::pair<char, integer>> r(q);
    std::cin >> r;

    solve(r);

    return 0;
}
