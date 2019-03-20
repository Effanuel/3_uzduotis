# 2 oji uzduotis (Duomenų apdorojimas)
## Programos veikimo principas:

1. **(nuo v0.1)** **Įvesti** mokinio informaciją per konsolę ir **išvesti** į lentelę (apskaičiuoja galutinį balą)
2. **(nuo v0.2)** **Nuskaito** failą su mokiniais ir namų darbų balai, ir išveda į konsolę (apskaičiuoja galutinį balą)
3. **(nuo v0.4)** **Sugeneruoja** 2 failus iš 10,000 studentų, išskirstant į kietus ir lėvus (gal. balas >= 0.5)
4. **(nuo v0.5)** Pateikti **greičius skaičiavimų** naudojant skirtingus STL container'ius (iš 100,000 studentų)
---
## Installation
1. [Atsisiūskite naujausią versiją.](https://github.com/Effanuel/Duomenu-apdorojimas/archive/v1.0.zip)
2. Extract failus.
3. Per command-line:
```
make all
./DuomenuApdorojimas
```
---
### Įvedimas(nuo v0.1): 
1. Nuskaito vieno studento duomenis: **vardą** ir **pavardę**;
2. **n** atliktų namų darbų rezultatus (10-balėje sistemoje), o taip pat egzamino rezultatą;
3. Tuomet iš šių duomenų, suskaičiuoja galutinius balus<br/>pagal **vidurkį**:<br/> 
    ```galutinis_vid = 0.4 * vidurkis + 0.6 * egzaminas```<br/>ir **medianą**:<br/>
    ```galutinis_med = 0.4 * mediana + 0.6 * egzaminas```
4. Taip pat galima pasirinkti, jog namų darbų rezultatai bei egzamino balas būtų sugeneruojami
    atsitiktinai (penki balai kaip *default*);<br/>

### Rezultatas:
```
Pavardė    Vardas       Galutinis (Vid.)  Galutinis (Med.)
---------------------------------------------------------
Juozas     Rimantas      8.60            9.20
```
---
### Nuskaitymas(nuo v0.2):
1. Nuskaito failą pagal tokį formatą:
```
Pavardė     Vardas      ND1  ND2   ND3  ND4  ND5  Galutinis_balas(Med.)
Vardas2     Pavardė2    7    10    8    5    4    6
Vardas1     Pavardė1    8    9     10   6    10   9
...
```
   ir išveda tokią lentelę į konsolę *(abėcėlės tvarka)*:
```
Pavardė    Vardas       Galutinis (Vid.)  Galutinis (Med.)
---------------------------------------------------------
Vardas1     Pavardė1      8.60            9.20
Vardas2     Pavardė2      7.20            9.10
...
```
---
### Generavimas(nuo v0.4):
1. Generuoja failus su skirtingais Studentų kiekiais.
2. **(v0.5)** Generuoja failus su skirtingais STL container'iais.<br/>
3. **(v0.5)** Matuoja programos veikimo greitį.<br/>
---
### Final(nuo v1.0):
1. Galima pasirinkti sugeneruoti failus
2. Galima pasirinkti STL testavimą

![pasirinkimai](https://github.com/Effanuel/Duomenu-apdorojimas/blob/master/pasirinkimai.png)

---
## CHANGE LOGS:

## [v1.0](https://github.com/Effanuel/Duomenu-apdorojimas/releases/tag/v1.0)

### Strategija #1 *(std::partition_copy)*
#### Failo generavimo greičių laikai su STL container'iais 
*(Generavimo laikai apskaičiuoti pagal 20 matavimų vidurkį)*

| Studentų skaičius:     | 10        | 100       | 1,000     | 10,000    | 100,000   | 1,000,000 |
| :--------------------- | --------- | --------- | --------- | --------- | --------- | --------- |
| **vector** laikas in s | 0.0028888 | 0.0032600 | 0.0191334 | 0.1021460 | 0.8694390 | 8.57822   |
| **list** laikas in s   | 0.0022954 | 0.0029898 | 0.0193620 | 0.1022130 | 0.8663810 | 8.60992   |
| **deque** laikas in s  | 0.0022213 | 0.0030219 | 0.0191258 | 0.1030060 | 0.8664620 | 8.71775   |



### Strategija #2 *(std::copy + .pop_back())*
#### Failo generavimo greičių laikai su STL container'iais 
*(Generavimo laikai apskaičiuoti pagal 20 matavimų vidurkį)*

| Studentų skaičius:     | 10        | 100       | 1,000     | 10,000    | 100,000   | 1,000,000 |
| :--------------------- | --------- | --------- | --------- | --------- | --------- | --------- |
| **vector** laikas in s | 0.0029979 | 0.0036705 | 0.0190777 | 0.0969618 | 0.8539030 | 8.71786   |
| **list** laikas in s   | 0.0024956 | 0.0032619 | 0.0194873 | 0.0976417 | 0.8610510 | 8.71506   |
| **deque** laikas in s  | 0.0024618 | 0.0031395 | 0.0198548 | 0.1030060 | 0.8611970 | 8.82010   |



### Strategija #3 *(no algorithms >> iteration su .erase())*
#### Failo generavimo greičių laikai su STL container'iais 

| Studentų skaičius:     | 10        | 100       | 1,000     | 10,000    | 100,000   | 200,000   |
| :--------------------- | --------- | --------- | --------- | --------- | --------- | --------- |
| **vector** laikas in s | 0.0029283 | 0.0038262 | 0.0218089 | 0.3169540 | 23.391100 | 108.940   |
| **list** laikas in s   | 0.0025509 | 0.0038227 | 0.0196076 | 0.1059670 | 0.8817400 | 1.71349   |
| **deque** laikas in s  | 0.0026012 | 0.0034225 | 0.0205462 | 0.1923390 | 10.620500 | 66.2998   |

---

## [v0.5](https://github.com/Effanuel/Duomenu-apdorojimas/releases/tag/v0.5)

### (OUTDATED) Strategija #1 *(std::partition_copy) (no file reading included)* 
#### Failo generavimo greičių laikai su STL container'iais 
*(Generavimo laikai apskaičiuoti pagal 20 matavimų vidurkį)*

| Studentų skaičius:     | 10        | 100       | 1,000     | 10,000    | 100,000   | 1,000,000 |
| :--------------------- | --------- | --------- | --------- | --------- | --------- | --------- |
| **vector** laikas in s | 0.0081274 | 0.0089709 | 0.0163225 | 0.0679107 | 0.5669360 | 5.59581   |
| **list** laikas in s   | 0.0081211 | 0.0085473 | 0.0156446 | 0.0702477 | 0.6124770 | 6.49375   |
| **deque** laikas in s  | 0.0075034 | 0.0095593 | 0.0158286 | 0.0708954 | 0.5846350 | 5.89265   |
---

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
//OUTPUT_KIETI.txt
//Pavardė     Vardas      ND1  ND2   ND3  ND4  ND5  Galutinis_balas(Med.)
Vardas2     Pavardė2    7    10    8    5    4    6
Vardas1     Pavardė1    8    9     10   6    10   9
...
```
```
//OUTPUT_SILPNI.txt
//Pavardė     Vardas      ND1  ND2   ND3  ND4  ND5  Galutinis_balas(Med.)
Vardas2     Pavardė2    1    2    1    4    1     2
Vardas1     Pavardė1    3    5     1    2    3    4

...
```
---

## [v0.3](https://github.com/Effanuel/Duomenu-apdorojimas/releases/tag/v0.3)
---
## [v0.2](https://github.com/Effanuel/Duomenu-apdorojimas/releases/tag/v0.2)
### Failo formatas turi būti toks:
```
Vardas1     Pavardė1    8    9     10   6    10   9
Vardas2     Pavardė2    7    10    8    5    4    6
...
```
---
## [v0.11](https://github.com/Effanuel/Duomenu-apdorojimas/releases/tag/v0.11)

