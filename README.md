
# Calculadora em C++

## Guia de Instalação e Configuração

### Pré-requisitos

Para compilar e executar o código, você precisará de:

- Um compilador C++ (como g++ ou clang++)
- Sistema operacional compatível (Windows, macOS, Linux)

### Instruções de Instalação

1. **Clone o repositório** (se aplicável):
   ```bash
   git clone https://github.com/vbarbosadev/calculadora.git
   cd calculadora
   ```

2. **Compilar o código**:
   Use o seguinte comando para compilar o arquivo `main.cpp`:
   ```bash
   g++ -o calculadora main.cpp
   ```

3. **Executar a aplicação**:
   Após a compilação, execute a aplicação com:
   ```bash
   ./calculadora
   ```

## Guia de Uso

### Principais Funcionalidades

A calculadora possui várias operações matemáticas, incluindo:

1. **Soma**
2. **Subtração**
3. **Multiplicação**
4. **Divisão**
5. **Potenciação**
6. **Radiciação**
7. **Porcentagem**
8. **Logaritmo na base 10**
9. **Seno, Cosseno e Tangente de um ângulo**

### Exemplos de Execução

1. **Soma**:
   - Escolha a opção `1` no menu.
   - Digite `5` e `3`.
   - Resultado: `8`

2. **Divisão**:
   - Escolha a opção `4` no menu.
   - Digite `10` e `2`.
   - Resultado: `5`

3. **Raiz Quadrada**:
   - Escolha a opção `6`.
   - Digite `16`.
   - Resultado: `4`

4. **Histórico de Operações**:
   - Escolha a opção `12` no menu para ver as últimas 5 operações realizadas.

### Observações

- O programa não permite divisão por zero e exibirá uma mensagem de erro nesse caso.
- As funções de seno, cosseno e tangente aceitam ângulos em graus.
