# 2-osios užduoties papildoma (Duomenų apdorojimas)

## CHANGE LOGS:
## [v0.45](https://github.com/Effanuel/Duomenu-apdorojimas/releases/tag/v0.45)
### raskMinkstus_v1

| Studentų skaičius:     | 10,000    | 100,000   |
| :--------------------- | --------- | --------- |
| **vector** laikas in s | 0.303667  | 26.5026   |
| **deque** laikas in s  | 0.171230  | 12.2913   |

```C++
template <typename T> T raskMinkstus_v1(T& Studentai) {
	T minksti;
	typename T::size_type i = 0;

	while (i != Studentai.size()) {
		if (!find_split_mark(Studentai[i])) {
			minksti.push_back(Studentai[i]);
			Studentai.erase(Studentai.begin() + i);
		}
		else
			++i;
	}
	return minksti;
}
```
### raskMinkstus_v2 (```.resize()``` instead of ```.erase```)

| Studentų skaičius:     | 10,000   | 100,000   |
| :--------------------- | -------- | --------- |
| **vector (.insert())** laikas in s | 0.991101 | 111.354   |
| **deque (.insert())** laikas in s  | 0.058879 | 0.461532  |
| **deque (push_front)** laikas in s  | 0.049127 | 0.393905  |

```C++
template <typename T> T raskMinkstus_v2(T& Studentai) {
	T minksti;
	typename T::size_type it = 0;
	int size_first = Studentai.size();
	while (it != Studentai.size()) {
		if (!find_split_mark(Studentai[it])) {
			minksti.push_back(Studentai[it++]);
		}
		else {
			Studentai.insert(Studentai.begin(), Studentai[it++]);
			//Studentai.push_front(Studentai[it]);
			//it++;

		}
		++it;

	}
	Studentai.resize(Studentai.size() - size_first);
	Studentai.shrink_to_fit();
	return minksti;
}
```
