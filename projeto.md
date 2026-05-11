# Projeto orientado a objeto

>[!NOTE]
>O **Projeto orientado a objeto** é composto pelas documentação do projeto descrito em UML. Deve incluir um Diagrama de Classes do sistema projetado, e pelo menos um diagrama de interação de um dos casos de uso. Outros diagramas podem ser apresentados, caso julgue necessário.

## Visão arquitetural

O sistema foi projetado com separação em camadas:

- **Apresentação (Qt Widgets):** janela principal, display e botões.
- **Controle de entrada:** mapeamento de tecla para ação.
- **Domínio matemático:** execução de expressões em ALG e manipulação da pilha em RPN.
- **Estado da calculadora:** modo atual, buffer de entrada e valores da pilha.

## Diagrama de classes

```mermaid
classDiagram
    class MainWindow {
        +renderCalculator()
        +onKeyPressed(keyId)
    }

    class DisplayLCD {
        +render(state)
    }

    class KeyButton {
        +id
        +primaryLabel
        +secondaryLabel
        +press()
    }

    class KeyboardMatrix {
        +buildFromLayout()
        +getKeys()
    }

    class InputController {
        +handleKey(keyId)
        +initialState()
        -orangeShiftActive
        -whiteShiftActive
        -alphaActive
        -mapPhysicalKey(keyId)
    }

    class CalculatorModel {
        +processKey(keyId)
        +currentState()
        -inputBuffer
        -cursorPos
        -complexMode
        -variables
        -undoStack
        -menuContext
        -awaitingVarNameForSto
        -awaitingSecondArg
        -beginStoFlow()
        -completeStoWithName()
        -recallVariableIntoInput()
        -applyUnaryFunction(name)
        -applyBinaryFunction(name)
        -applyPower(inverseRoot)
        -solveForX()
        -pushUndo()
        -popUndo()
    }

    class ExpressionEngine {
        +evaluate(expression)
        +evaluateWithX(expression, xValue)
    }

    class StackEngine {
        +push(value)
        +drop()
        +duplicateTop()
        +clear()
        +applyBinary(op)
        +applyUnary(op)
        +applyNthRoot()
        +values()
        +snapshotLines()
    }

    class ModeManager {
        +toggleMode()
        +cycleAngleMode()
        +setNumFormat(fmt, decimals)
        +cycleNumDecimals()
        +formatNumber(v)
        +modeLabel()
        +angleLabel()
        +numFormatLabel()
        +toRadians(v)
        +fromRadians(v)
        -mode : CalcMode
        -angle : AngleMode
        -numFmt : NumFormat
        -numDecimals : int
    }

    class DisplayState {
        +mode
        +angle
        +complexFlag
        +numFormat
        +menuTitle
        +softMenuLabels
        +inputLine
        +cursorPos
        +resultLine
        +stackLines
    }

    class CalcSnapshot {
        +inputBuffer
        +cursorPos
        +stackValues
        +variables
        +resultLine
        +complexMode
        +menuContext
    }

    MainWindow --> KeyboardMatrix
    MainWindow --> DisplayLCD
    MainWindow --> InputController
    InputController --> CalculatorModel
    CalculatorModel --> ModeManager
    CalculatorModel --> ExpressionEngine
    CalculatorModel --> StackEngine
    CalculatorModel --> CalcSnapshot
    CalculatorModel --> DisplayState
    KeyboardMatrix --> KeyButton
    DisplayLCD ..> DisplayState
```

## Diagrama de interação (caso de uso: executar operação)

```mermaid
sequenceDiagram
    participant User as Usuario
    participant Key as KeyButton
    participant UI as MainWindow
    participant Ctrl as InputController
    participant Model as CalculatorModel
    participant Engine as ExpressionEngine
    participant LCD as DisplayLCD

    User->>Key: pressiona tecla
    Key->>UI: sinal de clique(keyId)
    UI->>Ctrl: handleKey(keyId)
    Ctrl->>Model: processKey(keyId)
    alt modo ALG
        Model->>Engine: evaluate(expressao)
        Engine-->>Model: resultado
    else modo RPN
        Model->>Model: atualiza pilha RPN
    end
    Model-->>UI: novo estado de display
    UI->>LCD: renderiza linhas atualizadas
```

## Rastreabilidade com o manual

- **Cap. 1:** motivou a separação `DisplayLCD`, `KeyboardMatrix` e `ModeManager`; formatos de ângulo e cabeçalho LCD.
- **Cap. 2:** motivou `InputController` e fluxo de edição de entrada, STO/RCL e UNDO (`CalcSnapshot`).
- **Cap. 3:** motivou `ExpressionEngine` para operações reais e `ModeManager::NumFormat` para FIX/SCI/ENG.
- **Cap. 5:** motivou `solveForX()` (Newton-Raphson) e `ExpressionEngine::evaluateWithX()`.
- **Cap. 17:** motivou `applyBinaryFunction()` com COMB, PERM e `applyUnaryFunction()` com FACT.

<div align="center">

[Retroceder](analise.md) | [Avançar](implementacao.md)

</div>