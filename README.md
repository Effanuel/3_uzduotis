# 2 oji uzduotis (Duomenų apdorojimas)
### Programos veikimo principas(v0.1)
1. Nuskaito vieno studento duomenis: **vardą** ir **pavardę**;
2. **n** atliktų namų darbų rezultatus (10-balėje sistemoje), o taip pat egzamino rezultatą;
3. Tuomet iš šių duomenų, suskaičiuoja galutinius balus<br/>pagal **vidurkį**:<br/> 
```galutinis_vid = 0.4 * vidurkis + 0.6 * egzaminas```<br/>ir **medianą**:<br/>
```galutinis_med = 0.4 * vidurkis + 0.6 * egzaminas```
4. Taip pat galima pasirinkti, jog namų darbų rezultatai bei egzamino balas būtų sugeneruojami
atsitiktinai (penki balai kaip *default*).

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


## [v0.11](https://github.com/Effanuel/Duomenu-apdorojimas/releases/tag/v0.11)
## [v0.2](https://github.com/Effanuel/Duomenu-apdorojimas/releases/tag/v0.2)
### Failo formatas turi būti toks:
```
Pavardė     Vardas      ND1  ND2   ND3  ND4  ND5  Egzaminas
Vardas1     Pavardė1    8    9     10   6    10   9
Vardas2     Pavardė2    7    10    8    5    4    6
...
```

