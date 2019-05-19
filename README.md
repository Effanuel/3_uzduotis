# 3_uzduotis
Ši užduotis yra [antro](https://github.com/Effanuel/Duomenu-apdorojimas) darbo tęsinys

## Prerequisites
1. GNU C++ Compiler
2. *Optional: **gtest** for Unit Testing*

## Installation
1. [Atsisiūskite naujausią versiją.](https://github.com/Effanuel/3_uzduotis/releases/tag/v2.0)
2. Extract failus.
3. Per command-line:

```
cd 3_uzduotis
make run
```
---

## Releases
### [v1.10](https://github.com/Effanuel/3_uzduotis/releases/tag/v1.11)

<table>
    <thead>
        <tr>
            <th>Student number</th>
            <th colspan=3>10,000</th>
            <th colspan=3>100,000</th>
        </tr>
    </thead>
    <tbody>
        <tr>
            <th>Optimization</th>
            <td>O1</td>
            <td>O2</td>
            <td>O3</td>
            <td>O1</td>
            <td>O2</td>
            <td>O3</td>
        </tr>
        <tr>
            <th>struct</th>
            <td>0.106002</td>
            <td>0.102461</td>
            <td>0.104170</td>
            <td>0.946415</td>
            <td>0.892254</td>
            <td>0.864305</td>
        </tr>
        <tr>
            <th>class</th>
            <td>0.164561</td>
            <td>0.152082</td>
            <td>0.151922</td>
            <td>1.471150</td>
            <td>1.448763</td>
            <td>1.410840</td>
        </tr>
    </tbody>
</table>

---

### [v1.20](https://github.com/Effanuel/3_uzduotis/releases/tag/v1.20)

### Added overloaded operators:
```C++
friend bool operator==(const Student&, const Student&);
friend bool operator!=(const Student&, const Student&);
friend std::ostream& operator<<(std::ostream&, const Student&);
friend std::istream& operator>>(std::istream&, Student&);
```
---
### [v1.50](https://github.com/Effanuel/3_uzduotis/releases/tag/v1.52)
### Base class Zmogus:
* **protected** members: ```vardas_```, ```pavarde_```;
* Base class ```Zmogus``` yra abstract;


#### Constructors:
```c++
Zmogus(string v = "", string p = "");
Zmogus(const Zmogus& p);
Zmogus(Zmogus&& a);
```


---

### Unit Tests [v2.0](https://github.com/Effanuel/3_uzduotis/releases/tag/v2.0)

![Unit Test](https://github.com/Effanuel/3_uzduotis/blob/master/Unit%20Tests.png)

---
