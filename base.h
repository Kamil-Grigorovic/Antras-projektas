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

    string getVard() const { return vard; }
    string getPav() const { return pav; }

    void setVard(const string& v) { vard = v; }
    void setPav(const string& p) { pav = p; }

    virtual void info() const = 0;
};
