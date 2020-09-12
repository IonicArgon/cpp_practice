#include <iostream>
#include <string_view>

// friend functions and classes are functions and classes that can access 
// the private members of a class. for example:
class Foo
{
private:
    int bar{};

public:
    Foo(int val1) : bar{val1}
    {}

    void set(int bar)
    {
        this->bar = bar;
    }

    friend int get(Foo &foo);

    // for friend classes later
    friend class Bar;
};

// here is da friend function
int get(Foo &foo)
{
    return foo.bar;
}


// here is an example of friend classes
class Bar
{
private:
    int foo{};

public:
    Bar(int val1) : foo{val1}
    {}

    void set(int foo)
    {
        this->foo = foo;
    }

    int add(Foo &foo)
    {
        return foo.bar + this->foo;
    }
};


// here is an example of a friend function in a non-friend class

class Weather;      // forward declaration so that we can reference it in "Display"

class Display
{
private:
    std::string_view message{};

public:
    Display(std::string_view mes = "The weather outside is ") 
    : message{mes}
    {}

    void Display_Message(Weather &weather);
};

class Weather
{
private:
    double temperature{};
    double humidity{};

public:
    Weather(double temp, double humid) : temperature{temp}, humidity{humid}
    {}

    friend void Display::Display_Message(Weather &weather);     // make it a friend here
};

void Display::Display_Message(Weather &weather)     // implement the function here
{
    std::cout << message << weather.temperature << " degrees C and humidity of " << weather.humidity << '\n';
}


int main()
{
    Foo foo{10};
    Bar bar{15};
    Weather weather{20.5, 30.0};
    Display display{};

    std::cout << get(foo) << '\n';
    std::cout << bar.add(foo) << '\n';
    display.Display_Message(weather);
    return 0;
}