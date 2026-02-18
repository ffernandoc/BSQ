# BSQ Final Version

Final BSQ project from 42, developed by Hugo Fonseca and Fernando Cruz.

The program finds the largest possible square without obstacles in a map and marks it with the `full` character.

## Current structure

- `BSQ Final/`: version with separated layout (`src/` and `include/`).
- `BSQ Final 2/`: same logic, but all C/H files are in a single folder.
- `maps/`: test maps (valid and intentionally invalid).
- `CHANGELOG.md`: short change history.
- `README.md`: Brazilian Portuguese documentation.

## Requirements

- `cc` (C compiler supporting `-Wall -Wextra -Werror`)
- `make`

## Build

Version 1:

```bash
make -C "BSQ Final"
```

Version 2:

```bash
make -C "BSQ Final 2"
```

## Run

Version 1:

```bash
./"BSQ Final"/bsq maps/HugoFernando.map
```

Version 2:

```bash
./"BSQ Final 2"/bsq maps/HugoFernando.map
```

Read from `stdin`:

```bash
cat maps/42.map | ./"BSQ Final"/bsq
cat maps/42.map | ./"BSQ Final 2"/bsq
```

## Map format

1. Header: `<rows><empty><obstacle><full>`
2. Grid lines must have fixed width.
3. The grid must contain only `empty` and `obstacle` characters.

Example:

```txt
6.ox
......
..o...
......
...o..
......
......
```

## Clean

Version 1:

```bash
make -C "BSQ Final" fclean
```

Version 2:

```bash
make -C "BSQ Final 2" fclean
```
