<img src="img/ifsc-logo.png"
     width="30%"
     style="padding: 10px">

# Clone HP 50g em Qt (C++/POO)

## Simulador visual e funcional de calculadora HP 50g

> Repositório destinado para o desenvolvimento do projeto final da discipliana PRG22107 - Programação orienta a objeto. 
> 
> Aluno: Mateus Salgado 
> Professor: Hugo Marcondes

## Objetivo do projeto

Construir um clone didático da calculadora HP 50g usando C++ com Qt, com foco em:

- modelagem orientada a objetos de componentes de hardware (LCD, teclado, teclas e controlador);
- interface visual inspirada na HP 50g (visão superior, ordem de teclas e cores semelhantes);
- comportamento funcional inicial compatível com o manual da HP 50g, incluindo modo ALG e modo RPN.

## Escopo da primeira entrega (V1)

- Interface principal com display e matriz de teclas da HP 50g.
- Núcleo de cálculo híbrido:
  - **ALG**: expressões com `+ - * /` e parênteses;
  - **RPN**: pilha com `ENTER`, `DROP` e operações básicas.
- Edição de entrada: `BACKSPACE` e `CLEAR`.
- Estrutura OO separando visual, entrada e lógica matemática.

## Base de referência no manual

O comportamento do sistema será guiado pelo `manual.pdf`, principalmente:

- **Capítulo 1 (Introdução):** teclado, display, menus e modos de operação;
- **Capítulo 2 (Apresentando a calculadora):** objetos e edição de expressões;
- **Capítulo 3 (Cálculos com números reais):** operações aritméticas e uso de parênteses.

## Roadmap de desenvolvimento

1. **Análise OO:** domínio, requisitos, casos de uso e diagrama de domínio.
2. **Projeto OO:** diagrama de classes e diagrama de sequência.
3. **Implementação Qt/C++:** interface, componentes OO e motor de cálculo inicial.
4. **Testes:** validação de cenários ALG, RPN, transição de modo e edição.

## Estrutura do repositório

- [Análise orientada a objeto](./analise.md)
- [Projeto orientado a objeto](./projeto.md)
- [Implementação (C++)](./implementacao.md)
- [Testes](./testes.md)
- [Instruções de build e execução do código](./code/README.md)

<p align=center><strong>SUMÁRIO</strong></p>

[**1. ANÁLISE ORIENTADA A OBJETO**](./analise.md)<br>
[**2. PROJETO ORIENTADO A OBJETO**](./projeto.md)<br>
[**3. IMPLEMENTAÇÃO (C++)**](./implementacao.md)<br>
[**4. TESTES**](./testes.md)<br>