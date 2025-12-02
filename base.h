#include <string>

using namespace std;

/**
 * @class Zmogus
 * @brief Bazinė abstrakti klasė, aprašanti žmogų su vardu ir pavarde.
 *
 * Ši klasė naudojama kaip pagrindas studentams ar kitiems asmenims.
 * Turi grynai virtualią funkciją info(), todėl negali būti sukurta tiesiogiai.
 */
class Zmogus {
private:
    string vard; ///< Studento vardas
    string pav; ///< Studento pavardė
public:

    /**
     * @brief Numatytaisiais parametrais inicializuojantis konstruktorius.
     *
     * Sukuria objektą su tuščiu vardu ir pavarde.
     */
    Zmogus() : vard(""), pav("") {}
    /**
     * @brief Konstruktorius su vardu ir pavarde.
     * @param v Vardas
     * @param p Pavardė
     */
    Zmogus(const string& v, const string& p) : vard(v), pav(p) {}

    /**
     * @brief Virtualus destruktorius.
     *
     * Leidžia saugiai naikinti objektus per bazinės klasės rodykles.
     */
    virtual ~Zmogus() = default;

    string getVard() const { return vard; }
    string getPav() const { return pav; }

    void setVard(const string& v) { vard = v; }
    void setPav(const string& p) { pav = p; }

    virtual void info() const = 0;
};

