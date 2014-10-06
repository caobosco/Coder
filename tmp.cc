#include <iostream>

class Outer {
    public:
        static int m_out;
        class Inner {
            public:
                static int m_in;
                void Display();
        };
};

int Outer::m_out = 10;
int Outer::Inner::m_in = 25;

void Outer::Inner::Display() {
    std::cout << m_out << std::endl;
}

namespace bocao{
    static int i = 0;
    long a;
}

int main() {
    Outer obj_out;
    Outer::Inner obj_in;

    obj_in.Display();
    std::cout << bocao::a << std::endl;
}

