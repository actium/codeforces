#include <iostream>
#include <string>

void answer(const std::string& x)
{
    std::cout << x << '\n';
}

void no_answer()
{
    std::cout << "Error occurred" << '\n';
}

bool parse(std::string_view& q, std::string& t)
{
    if (!q.empty() && q[0] == ' ')
        q.remove_prefix(1);

    if (q.empty())
        return false;

    if (q[0] == 'i') {
        q.remove_prefix(3);
        t.append("int");
    } else {
        q.remove_prefix(4);
        t.append("pair<");
        if (!parse(q, t))
            return false;
        t.push_back(',');
        if (!parse(q, t))
            return false;
        t.push_back('>');
    }

    return true;
}

void solve(size_t n, const std::string& s)
{
    std::string t;
    std::string_view q = s;
    parse(q, t) && q.empty() ? answer(t) : no_answer();
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n >> std::ws;

    std::string s;
    std::getline(std::cin, s);

    solve(n, s);

    return 0;
}
