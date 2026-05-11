# Implementação

>[!NOTE] 
 Relatar o processo de implementação do problemas, incluindo as
 ferramentas e bibliotecas utilizadas
>

## Tecnologias adotadas

- **Linguagem:** C++17
- **Framework gráfico:** Qt 6 (Widgets)
- **Build system:** CMake
- **Paradigma:** Programação orientada a objetos

## Estratégia de implementação

A implementação foi organizada para refletir componentes de hardware da HP 50g e separar interface de lógica:

- **Camada visual:** janela principal, display e botões;
- **Camada de controle:** captura e roteamento das teclas pressionadas;
- **Camada de domínio:** regras ALG e RPN, avaliação e manipulação da pilha.

## Componentes OO implementados

- `DisplayLCD`: renderiza linhas do visor, modo ativo, formato numérico e mensagens.
- `KeyButton`: encapsula identidade da tecla e rótulos primário/secundário.
- `KeyboardMatrix`: monta e organiza todas as teclas da interface com hotspots normalizados sobre imagem de referência.
- `CalculatorModel`: mantém estado global da calculadora, histórico de undo, variáveis e fluxos de menu.
- `InputController`: traduz evento de tecla em comando de domínio, gerenciando estados de shift (laranja/branco) e alpha.
- `ExpressionEngine`: avalia expressão matemática em modo ALG, incluindo substituição de variável `X` para resolução numérica.
- `StackEngine`: executa operações da pilha em modo RPN, incluindo funções unárias e binárias.
- `ModeManager`: controla alternância ALG/RPN, modo de ângulo (DEG/RAD/GRAD) e formato numérico (STD/FIX/SCI/ENG).

## Implementação incremental por versão

### V1 — Interface base e cálculo essencial

- Interface com overlay visual da HP 50g (hotspots calibrados sobre imagem de referência).
- Operações básicas em ALG (`+ - * /`, parênteses, `^`, notação científica EEX) e RPN (pilha, `ENTER`, `DROP`, operadores, `y^x`, `x√y`).
- Funções científicas: `sin`, `cos`, `tan`, `asin`, `acos`, `atan`, `sinh`, `cosh`, `tanh`, `log`, `ln`, `exp`, `10^x`, `sqrt`, `x²`, `1/x`, `abs`, `+/-`, constante `pi`.
- Edição de entrada com cursor (`←`/`→`) e `BACKSPACE`.
- `ON` cancela progressivamente (linha → menu → pilha); `Orange+ON` cancela tudo.
- STO / RCL de variáveis com nome digitado.
- HIST (último resultado).
- Soft keys F1–F6 com rótulos dinâmicos, submenus APPS, TOOL, VAR, SYMB.
- Modos visíveis no cabeçalho LCD: ALG/RPN, ângulo, complexo.
- Shifts laranja e branco com mapeamento completo de funções secundárias.

### V2 — Funcionalidades ampliadas (entregues no mesmo repositório)

- **UNDO** (`Orange+←`): desfaz até 20 operações destrutivas (pilha, variáveis, modo menu).
- **Formato numérico**: menu FORMAT acessível por `Orange+MODE` — STD, FIX N, SCI N, ENG N com incremento de casas decimais (F5); exibido no cabeçalho LCD.
- **Menu MTH** (`Orange+SYMB`):
  - `MTH > REAL`: FLOOR, CEIL, ROUND, SIGN, MOD (binário).
  - `MTH > PROB`: FACT (0..170), COMB(n,k), PERM(n,k), RAND, MAX.
- **SOLVE numérico** (`SYMB > SOLVE`): resolve `f(X) = 0` pelo método de Newton-Raphson (até 100 iterações, tolerância 1e-10); palpite inicial pela pilha ou 1.0.
- **FACTOR** (`SYMB > FACTOR`): fatoração inteira demonstrativa para n ≤ 1 000 000.
- Funções FLOOR, CEIL, ROUND, SIGN, FACT disponíveis diretamente via shift em teclas físicas.
- `ExpressionEngine::evaluateWithX`: substitui `X` por valor numérico para uso no solver.

## Decisões de design

- Priorizar separação clara entre UI e regra de negócio para facilitar testes.
- `CalculatorModel` concentra o estado e adota snapshot para UNDO sem dependência de frameworks externos.
- Funções fora do escopo aparecem como menus com mensagem clara ("demo / não implementado") em vez de serem silenciadas.
- Formato numérico gerenciado em `ModeManager` e aplicado centralmente em `formatDouble()`, garantindo consistência em todos os pontos de exibição.

## Rastreabilidade com o manual

- **Cap. 1:** teclado, display, modos, shifts e convenções de interação (V1).
- **Cap. 2:** edição, cursor, STO/RCL, UNDO (V1/V2).
- **Cap. 3:** operações reais, funções científicas, formato numérico (V1/V2).
- **Cap. 5:** SOLVE numérico, FACTOR, menu ALG/SYMB (V2).
- **Cap. 17:** COMB, PERM, FACT, RAND via MTH > PROB (V2).

<div align="center">

[Retroceder](projeto.md) | [Avançar](testes.md)

</div>