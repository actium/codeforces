#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

struct Record {
    std::string friend_name;
    std::vector<std::string> phone_numbers;
};

std::istream& operator >>(std::istream& input, Record& v)
{
    input >> v.friend_name;

    size_t n;
    std::cin >> n;

    v.phone_numbers.resize(n);
    input >> v.phone_numbers;

    return input;
}

void answer(const std::unordered_map<std::string, std::vector<std::string>>& x)
{
    std::cout << x.size() << '\n';

    for (const auto& e : x) {
        std::cout << e.first << ' ' << e.second.size();

        for (const std::string x : e.second)
            std::cout << ' ' << x;

        std::cout << '\n';
    }
}

void solve(const std::vector<Record>& r)
{
    std::unordered_map<std::string, std::vector<std::string>> x;
    for (const Record& q : r) {
        std::vector<std::string>& p = x[q.friend_name];
        p.insert(p.end(), q.phone_numbers.cbegin(), q.phone_numbers.cend());
    }

    for (auto& e : x) {
        std::vector<std::string>& p = e.second;

        std::sort(p.begin(), p.end(), [](const std::string& a, const std::string& b) {
            return a.length() > b.length();
        });

        for (size_t i = 0; i < p.size(); ++i) {
            for (size_t j = i + 1; j < p.size(); ++j) {
                const size_t m = p[j].length();

                if (p[i].compare(p[i].length() - m, m, p[j]) == 0)
                    p.erase(p.begin() + j--);
            }
        }
    }

    answer(x);
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<Record> r(n);
    std::cin >> r;

    solve(r);

    return 0;
}
