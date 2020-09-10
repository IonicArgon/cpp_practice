#include <iostream>
#include <string>

// consider the following
class Employee
{
private:
    int m_id{0};
    std::string m_name;

public:
    // technically works, but we've repeat da code
    Employee(int id = 0, std::string name = "") : m_id{id}, m_name{name}
    {
        std::cout << name << " created.\n";
    }

    Employee(std::string name) : m_name{name}
    {
        std::cout << name << " created.\n";
    }

    auto print() -> void
    {
        std::cout << m_name << '\t' << m_id << '\n';
    }
};

// we can do this instead
class BetterEmployee
{
private:
    int m_id;
    std::string m_name;

public:
    BetterEmployee(int id = 0, std::string name = "") : m_id{id}, m_name{name}
    {
        std::cout << name << " created.\n";
    }

    BetterEmployee(std::string name) : BetterEmployee{0, name}
    {}

    auto print() -> void
    {
        std::cout << m_name << '\t' << m_id << '\n';
    }
};

auto main() -> int
{
    Employee bob{"bob"}, bobWithID{2, "bob"};
    BetterEmployee rob{"rob"}, robWithID{2, "rob"};

    bob.print(); bobWithID.print();
    rob.print(); robWithID.print();
    return 0;
}