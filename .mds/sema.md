<img src="../img/ifsc-logo.png"
     width="30%"
     style="padding: 10px"
     alt="">

# SEMA - Caso de uso
**Gerenciar dados de uma estação de monitoramento remoto de qualidade da água.**

## Atores
* Estação de monitoramento (1..*)
* Operador  
   * Estudante
   * Professor
   * Pesquisador
   * Cliente

## Fluxo Principal
### Pré-condições
1. Uma (ou mais) estação remota está em operação.
1. Ao menos uma estação remota está conectada à internet.
1. O dispositivo do SEMA está conectado à internet.
1. Possuir broker MQTT ou o dispositivo do SEMA estiver conectado à mesma rede wifi que pelo menos uma estação.

### Fluxo
1. Uma `Estação` envia dados para o SEMA.
1. O sistema recebe os dados da `Estação`.
1. O sistema armazena os dados recebidos.
1. O sistema recupera os dados.
1. O Operador visualiza os dados.

## Fluxo Alternativo
### Pré-condições
1. O dispositivo possúi dados armazenados.

### Fluxo
1. O Operador solicita a recuperação dos dados.
1. O sistema recupera os dados recebidos.
1. O Operador visualiza os dados.
1. O operador exporta os dados.

#

<p align=center><strong>SUMÁRIO</strong></p>

[**1. ANÁLISE ORIENTADA A OBJETO**](sema.md)<br>
[**2. PROJETO ORIENTADO A OBJETO**](projeto.md)<br>
[**3. IMPLEMENTAÇÃO (C++)**](implementacao.md)<br>
[**4. TESTES**](testes.md)<br>

#