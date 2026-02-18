# BSQ Versao Final

Projeto final BSQ da 42, desenvolvido por Hugo Fonseca e Fernando Cruz.

O programa encontra o maior quadrado possivel sem obstaculos em um mapa e marca esse quadrado com o caractere `full`.

## Estrutura atual

- `BSQ Final/`: versao com estrutura separada (`src/` e `include/`).
- `BSQ Final 2/`: mesma logica, com todos os arquivos C/H em uma unica pasta.
- `maps/`: mapas de teste (validos e invalidos).
- `CHANGELOG.md`: historico resumido.
- `README_EN.md`: documentacao em ingles.

## Requisitos

- `cc` (compilador C com suporte a `-Wall -Wextra -Werror`)
- `make`

## Como compilar

Versao 1:

```bash
make -C "BSQ Final"
```

Versao 2:

```bash
make -C "BSQ Final 2"
```

## Como executar

Versao 1:

```bash
./"BSQ Final"/bsq maps/HugoFernando.map
```

Versao 2:

```bash
./"BSQ Final 2"/bsq maps/HugoFernando.map
```

Leitura por `stdin`:

```bash
cat maps/42.map | ./"BSQ Final"/bsq
cat maps/42.map | ./"BSQ Final 2"/bsq
```

## Formato do mapa

1. Header: `<linhas><empty><obstacle><full>`
2. As linhas da grade devem ter largura fixa.
3. A grade deve conter apenas os caracteres `empty` e `obstacle`.

Exemplo:

```txt
6.ox
......
..o...
......
...o..
......
......
```

## Limpeza

Versao 1:

```bash
make -C "BSQ Final" fclean
```

Versao 2:

```bash
make -C "BSQ Final 2" fclean
```
