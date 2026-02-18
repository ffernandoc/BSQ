# Changelog

## v1.09 — 2026-02-18

### Entrega final e organização
- Estrutura consolidada em `src/`, `include/` e `maps/`.
- Build padronizado com `Makefile` usando `cc -Wall -Wextra -Werror`.
- Documentação revisada e simplificada (`README.md` e `CHANGELOG.md`).
- Remoção de itens legados que não fazem parte da entrega final.

### Mapas e validação
- Mapas manuais atualizados em `maps/`, incluindo `maps/HugoFernando.map` e `maps/42.map`.
- Mapas inválidos mantidos para validação manual de erro.
- Validação focada em execução manual com os mapas da pasta `maps/`.

### Conformidade técnica
- Projeto compilando sem erros e sem relink indevido.
- Leitura por arquivo e por `stdin` funcionando conforme o enunciado.
- Tratamento de erro padronizado com `map error\n` em `stdout`.
- Uso restrito às funções externas permitidas no enunciado.
