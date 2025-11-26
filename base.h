#include <string>

using namespace std;

class Zmogus {
private:
    string vard;
    string pav;
public:
    Zmogus() : vard(""), pav("") {}
    Zmogus(const string& v, const string& p) : vard(v), pav(p) {}

    virtual ~Zmogus() = default;
    
    virtual void info() const = 0;
}


