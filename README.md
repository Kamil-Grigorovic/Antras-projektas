## Studentų valdymo sistema ##
| Failas | Tipas | Aprašymas |
|---------|-------|-----------|
| `main.h` | Header | Klasės `Studentas` deklaracija ir get/set metodai |
| `functions.cpp` | Source | Funkcijos, kurios įveda, skaito, generuoja ir rūšiuoja studentus |
| `projektas.cpp` | Source | `main()` funkcija – programos valdymo meniu |

## Trumpas aprašymas: ##
Programa skirta studentų duomenų tvarkymui: 
 -  `įvedimui rankiniu būdu,` 
 -  `generavimui,` 
 -  `nuskaitymui iš failų.` 
 -  `galimybė pasirinkti, kokį konteinerio tipą naudoti.`

Kodas skaičiuoja kiekvieno studento **vidurkį** ir **medianą**, rūšiuoja studentus pagal vartotojo pasirinktą kriterijų (**vardą, pavardę arba vidurkį**), padalija juos į dvi grupes (Galima pasirinkti vieną iš trijų rūšiavimo strategijų) – **vargsiukus** ir **galvočius** – ir išsaugo rezultatus į atskirus failus.

## Funkcijos: ##
 - **_ivesk()_** – įveda studentą rankiniu būdu.
 - **_generuokStudenta()_** – sugeneruoja atsitiktinį studentą.
 - **_iveskIsFailo()_** – perskaito vieną studentą iš failo.
 - **_skaitytiIsFailo()_** – perskaito visą failą su studentais.
 - **_skaiciuotiMediana()_** – skaičiuoja studento medianą.
 - **_SkaiciaiSuKableliu()_** – formatuoja skaičius su dviem dešimtainėmis.
 - **_rikiuotiIrSukurtGrupe()_** – rūšiuoja studentus pagal vartotojo pasirinktą kriterijų ir padalija į grupes (vargsiukai / galvociai).
 - **_spausdintiIFaila()_** – įrašo rezultatus į failą.
 - **_formatuoti()_** – pagalbinė funkcija lentelės spausdinimui.

## Testavimai: ##
### Konteinerio tipas – _vector_ ###
|Įrašų kiekis | Failo nuskaitymas (s) | Rūšiavimas 1 strategija | Rūšiavimas 2 strategija | Rūšiavimas 3 strategija | Įrašymas į failus (s) | Bendra trukmė (s) |
|-------------|-----------------------|-------------------------|-------------------------|-------------------------|-----------------------|-------------------|
|       1 000	|                     - |                       - |                       - |                       - |                     - |             ≈0.03 |
|      10 000 |                     - |                       - |                       - |                       - |                     - |             ≈0.06 |
|     100 000 |                  0.26 |                    0.18 |                      96 |                    0.18 |                  0.08 |             ≈96.7 |
|   1 000 000 |                   2.4 |                    2.16 |                      –- |                     .96 |                   0.7 |              ≈7.2 |
|  10 000 000 |                  26.4 |                    28.7 |                      –- |                    24.9 |	                  7.9 |             ≈88.0 |

> **Pastaba:**  
> - `-` žymi labai mažą reikšmę  
> - `--` žymi labai didelę reikšmę

### Konteinerio tipas – _list_ ###
|Įrašų kiekis | Failo nuskaitymas (s) | Rūšiavimas 1 strategija | Rūšiavimas 2 strategija | Rūšiavimas 3 strategija | Įrašymas į failus (s) | Bendra trukmė (s) |
| ----------- | --------------------- | ----------------------- | ----------------------- | ----------------------- | --------------------- | ----------------- |
|       1 000 |                     - |                       - |                       - |                       - |  - | ≈0.03  |
|      10 000 |                     - |                       - |                       - |                       - |                     - |             ≈0.07 |
|     100 000 |                  0.34 |                    0.20 |                    0.08 |                    0.08 |                  0.07 |             ≈0.77 |
|   1 000 000 |                  3.33 |                    2.23 |                    0.85 |                    0.85 |                   0.7 |             ≈7.96 |
|  10 000 000 |                  34.8 |                     161 |                    38.2 |                    38.2 |                  12.5 |            ≈284.7 |

> **Pastaba:**  
> - `-` žymi labai mažą reikšmę  
> - `--` žymi labai didelę reikšmę

### Išvados ###
Naudojant `vector` konteinerį, optimaliausia taikyti rūšiavimui `3 strategiją`. Tuo tarpu `list` konteinerio atveju efektyviausios yra `2` ir `3 strategijos`.
    
## Sistemos parametrai: ##

- `CPU:`  Intel Core i5-1135G7 - 4 branduoliai / 8 gijų, 2.4 GHz
- `RAM:`  8 GB
- `SSD:`  500 GB
