## Macau engine

This project contains a Macau card game engine implemented in C++. It could be used to test and compare different game strategies and algorithms.

###### Sample output

```bash
bpogodzinski@ubuntu $ ./makao_sim
MACAU SIMULATOR by Bartłomiej Pogodziński 2020

Select algorithms:
adv-placeholder
placeholder

Type the names separated by space: adv-placeholder adv-placeholder placeholder adv-placeholder
How many games shall be played: 10000

Starting simulation
Progress: ▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓

Results:
adv-placeholder:	36.31%
    placeholder:	0.00%
adv-placeholder:	32.60%
adv-placeholder:	31.08%
```

#### Usage

Currently adding other algorithms needs importing it in `Game.h`, `MainInterface.h` and also adding it to the list in `Game.cpp` and `MainInterface.cpp`.

I know. I am working on it.

#### Contribution

If you have a suggestion or want to participate feel free to make pull requests, add issues or email me directly.
