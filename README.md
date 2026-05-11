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
- comportamento de **aplicação**: telas, botões, menus soft, modos visíveis e funções de uso comum (ALG/RPN, cálculos básicos, STO/RCL simples), guiado pelo manual como **referência de interface e fluxo**, sem reproduzir o firmware nem um motor de objetos/CAS/RPL da calculadora real.

## Fora de escopo (deliberado)

- **E-KERNEL** / pilha de objetos HP completos (tipos internos, CAS, RPL, diretórios, flags de sistema).
- Paridade profunda com todos os capítulos avançados do manual (matrizes simbólicas, EDO, estatística completa, etc.).
- O objetivo é **Qt + experiência de uso** sem substituir uma HP50g física.

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

1. **Análise OO:** domínio, requisitos, casos de uso e diagrama de domínio (foco em UI e fluxos de aplicação).
2. **Projeto OO:** diagrama de classes e sequência (componentes visuais + controlador + modelo “leve”).
3. **Implementação Qt/C++:** interface fiel, teclas, menus e cálculo demonstrável.
4. **Testes:** cenários de uso visível (menus, modos, expressões típicas).

## Fora de escopo

Motor de objetos HP (E-KERNEL), CAS/RPL completos e paridade com firmware — ver [code/docs/BACKLOG_IMPLEMENTACAO.md](code/docs/BACKLOG_IMPLEMENTACAO.md).

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