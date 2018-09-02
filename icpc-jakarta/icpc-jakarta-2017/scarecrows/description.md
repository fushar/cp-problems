# Sacred Scarecrows

Nira owns a rectangular paddy field consisting of R rows and C columns. There are R &times; C squares in the paddy field. Each square is either empty or contains rice.

Nira wants to place zero or more scarecrows on her paddy field. Each scarecrow must be placed on an empty square. Furthermore, the configuration of the scarecrows must be _sacred_. A configuration is said to be sacred if all the following conditions are satisfied:

- Each row contains at least one scarecrow.
- Each consecutive two columns contain at least one scarecrow.

Now Nira wonders, how many different sacred configurations are there? Two configurations are different if there is a square that contains a scarecrow in one configuration but not in the other configuration. Help Nira compute this number, modulo 1,000,000,007.

### Input Format
```
R C
<RxC characters>
```

- empty square is denoted by `.`
- square containing rice is denoted by `v` (lowercase v)

### Output Format

A single line containing the number of sacred configurations.

### Sample 1

```
2 2
v.
..
```


```
3
```

All possible configurations are:

```
vS  vS  vS
S.  .S  SS
```
### Sample 2

```
1 3
...
```


```
5
```

All possible configurations are:

```
SS.  S.S   SS.  .S.  SSS
```
### Sample 3

```
2 3
vvv
...
```

```
0
```
### Sample 4

```
3 3
...
.v.
...
```

```
145
```

### Constraints

- 1 &le; R &le; 16
- 1 &le; C &le; 1,000
