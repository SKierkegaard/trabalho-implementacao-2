# Trabalho de Implementação - TAD Genérico

**Instituição:** Universidade Federal do Maranhão  
**Disciplina:** Estrutura de Dados 1  
**Autor:** Pedro Vitório Arouche Campos  

## Descrição
Este trabalho consiste na implementação de um **Tipo Abstrato de Dados (TAD) Genérico** utilizando a linguagem C. Através do uso de ponteiros opacos (`void*`) e ponteiros para funções (como funções de comparação, exibição e liberação), a estrutura permite armazenar e manipular qualquer tipo de dado (inteiros, estruturas personalizadas, floats, etc.) de forma reutilizável e encapsulada.

O programa oferece operações fundamentais como criação, inserção, remoção, consulta/busca, listagem dos elementos e destruição da estrutura.

## Ambiente em que este sistema foi desenvolvido
- Sistema operacional: Arch Linux (Omarchy)
- IDE/Editor: Neovim
- Compilador: gcc (GCC) 16.2.1 20260810
- Linguagem: C

Caso o executável não rode no ambiente de correção, recompile com:

```bash
gcc -o ./build/main main.c tad_generico.c
./build/main
```

## Arquivos fonte

- `tad_generico.h`: Contém as assinaturas das funções, definições do TAD e os protótipos de callbacks (funções de comparação, impressão e desalocação).
- `tad_generico.c`: Contém a implementação interna das estruturas genéricas e da lógica do TAD.
- `main.c`: Programa principal contendo um menu interativo e testes para demonstrar o uso da estrutura genérica com diferentes tipos de dados.

## Execução do programa

- Terminal:
```bash
./build/main
```

> *Caso não rode na sua máquina, recompile:*
```bash
gcc -o ./build/main main.c tad_generico.c
```

- VSCode:
1. Abra a pasta do projeto no VSCode (File > Open Folder).
2. Ctrl+Shift+B - roda a task de build (compila `main.c` + `tad_generico.c`).
3. Abra o terminal integrado (Ctrl+`) e rode:
```bash
./build/main
```

*O trabalho está disponível no meu github:* [trabalho-tad-generico](https://github.com/SKierkegaard/trabalho-implementacao-2)
