#include"13_36.h"

int main(int argc, char const *argv[])
{
    Message m1 ("hello first email");
    Message m2 ("hello second email");
    m1.print_debug();
    m2.print_debug();
    Folder mailBox;
    m1.save(mailBox);
    m2.save(mailBox);
    mailBox.print_debug();

    Message m3 = std::move(m1);
    m2 = std::move(m3);
    return 0;
}
