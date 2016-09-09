#include <string>
std::string change1(char* st) {
    std::string tmp = "";
    for (int i = 0; st[i] != '\0'; i++)
        tmp += st[i];
    return tmp;
}
 
void change2(std::string st1, char* st2) {
    for (int i = 0; i < st1.length(); i++)
        st2[i] = st1[i];
}
