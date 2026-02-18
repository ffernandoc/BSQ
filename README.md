# BSQ v1.09

Projeto final BSQ da 42, desenvolvido por Hugo Fonseca e Fernando Cruz.

O programa encontra o maior quadrado possível sem obstáculos em um mapa e marca esse quadrado com o caractere `full`.

## Estrutura do projeto

- `src/`: código-fonte em C.
- `include/`: cabeçalhos do projeto.
- `maps/`: mapas para execução manual (válidos e inválidos intencionais).
- `Makefile`: build do binário `bsq`.
- `CHANGELOG.md`: histórico resumido das mudanças relevantes.

## Requisitos

- `cc` (ou compilador compatível com `-Wall -Wextra -Werror`)
- `make`

## Compilação

```bash
make
```

Comandos úteis:

```bash
make re      # recompila do zero
make clean   # remove objetos (obj/)
make fclean  # remove objetos e binário
```

## Execução

Executar com mapa sugerido:

```bash
./bsq maps/HugoFernando.map
```

Executar lendo de `stdin`:

```bash
cat maps/42.map | ./bsq
```

Executar com múltiplos arquivos:

```bash
./bsq maps/HugoFernando.map maps/42.map
```

Executar todos os mapas da pasta `maps/`:

```bash
for f in maps/*.map; do ./bsq "$f"; echo; done
```

## Formato esperado do mapa

1. Primeira linha (header): `<linhas><empty><obstacle><full>`
2. Linhas seguintes: grade com largura fixa.
3. Caracteres válidos na grade: apenas `empty` e `obstacle`.

Exemplo simples:

```txt
6.ox
......
..o...
......
...o..
......
......
```

## Validação manual

Use os mapas da pasta `maps/` para validar cenários válidos e inválidos:

```bash
for f in maps/*.map; do
	echo "[MAPA] $f"
	./bsq "$f"
	echo
done
```
