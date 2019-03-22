# 2-osios užduoties papildoma (Duomenų apdorojimas)
---
## CHANGE LOGS:
## [v0.45](https://github.com/Effanuel/Duomenu-apdorojimas/releases/tag/v0.4)
### raskMinkstus_v1

| Studentų skaičius:     | 10,000    | 100,000   |
| :--------------------- | --------- | --------- |
| **vector** laikas in s | 0.303667  | 26.5026   |
| **deque** laikas in s  | 0.171230  | 12.2913   |

### raskMinkstus_v2 (```.resize()``` instead of ```.erase```)

| Studentų skaičius:     | 10,000   | 100,000   |
| :--------------------- | -------- | --------- |
| **vector (.insert())** laikas in s | 0.991101 | 111.354   |
| **deque (.insert())** laikas in s  | 0.058879 | 0.461532  |
| **deque (push_front)** laikas in s  | 0.049127 | 0.393905  |
