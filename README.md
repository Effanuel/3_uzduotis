# 2 oji uzduotis (Duomenų apdorojimas)
### Programos veikimo principas(v0.1)
1. Nuskaito vieno studento duomenis: **vardą** ir **pavardę**;
2. **n** atliktų namų darbų rezultatus (10-balėje sistemoje), o taip pat egzamino rezultatą;
3. Tuomet iš šių duomenų, suskaičiuoja galutinius balus<br/>pagal **vidurkį**:<br/> 
    ```galutinis_vid = 0.4 * vidurkis + 0.6 * egzaminas```<br/>ir **medianą**:<br/>
    ```galutinis_med = 0.4 * vidurkis + 0.6 * egzaminas```
4. Taip pat galima pasirinkti, jog namų darbų rezultatai bei egzamino balas būtų sugeneruojami
    atsitiktinai (penki balai kaip *default*);<br/>
5. **(v0.4)** Generuoja failus su skirtingais Studentų kiekiais.<br/>

### Rezultatas:
```
Pavardė    Vardas       Galutinis (Vid.)  Galutinis (Med.)
---------------------------------------------------------
Juozas     Rimantas      8.60            9.20
```
## Paleidimas (Command-line)
```
make all;
./DuomenuApdorojimas;
```
## [v0.5](https://github.com/Effanuel/Duomenu-apdorojimas/releases/tag/v0.5)


#### Failo generavimo greičių laikai su STL container'iais 
*(Generavimo laikai apskaičiuoti pagal 20 matavimų vidurkį)*

| Studentų skaičius:     | 10        | 100       | 1,000     | 10,000    | 100,000   | 1,000,000 |
| :--------------------- | --------- | --------- | --------- | --------- | --------- | --------- |
| **vector** laikas in s | 0.0081274 | 0.0089709 | 0.0163225 | 0.0679107 | 0.5669360 | 5.59581   |
| **list** laikas in s   | 0.0081211 | 0.0085473 | 0.0156446 | 0.0702477 | 0.6124770 | 6.49375   |
| **deque** laikas in s  | 0.0075034 | 0.0095593 | 0.0158286 | 0.0708954 | 0.5846350 | 5.89265   |




## [v0.4](https://github.com/Effanuel/Duomenu-apdorojimas/releases/tag/v0.4)
#### Testavimas (*failų generavimas su skirtingais```vector<struct Items>``` kiekiais*)

```
(n = 10):        0.0304797 s
(n = 100):       0.0401614 s
(n = 1,000):     0.0287955 s
(n = 10,000):    0.105775 s
(n = 100,000):   0.584414 s
(n = 1,000,000): 5.4271 s
```

### Generuoti failo formatai yra tokie:
```
KIETI
Pavardė     Vardas      ND1  ND2   ND3  ND4  ND5  Galutinis_balas(Med.)
Vardas2     Pavardė2    7    10    8    5    4    6
Vardas1     Pavardė1    8    9     10   6    10   9
...
```
```
SILPNI
Pavardė     Vardas      ND1  ND2   ND3  ND4  ND5  Galutinis_balas(Med.)
Vardas2     Pavardė2    1    2    1    4    1     2
Vardas1     Pavardė1    3    5     1    2    3    4

...
```

## [v0.3](https://github.com/Effanuel/Duomenu-apdorojimas/releases/tag/v0.3)

## [v0.2](https://github.com/Effanuel/Duomenu-apdorojimas/releases/tag/v0.2)
### Failo formatas turi būti toks:
```
Pavardė     Vardas      ND1  ND2   ND3  ND4  ND5  Egzaminas
Vardas1     Pavardė1    8    9     10   6    10   9
Vardas2     Pavardė2    7    10    8    5    4    6
...
```

## [v0.11](https://github.com/Effanuel/Duomenu-apdorojimas/releases/tag/v0.11)


