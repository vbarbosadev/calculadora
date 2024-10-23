#include <iostream> // Inclui a biblioteca de entrada e saída
#include <cmath> // Inclui funções matemáticas básicas como sqrt
#include <deque> // Inclui a biblioteca para usar o deque
#include <cstdlib> // Inclui a biblioteca para usar a função system()

/**
 * Classe Calculadora
 * Responsável por realizar operações matemáticas básicas e avançadas.
 * É manipulada pela calsse Interface
 */
class Calculadora {
public:
    /**
     * Realiza a operação de soma entre dois números.
     * @param a O primeiro número.
     * @param b O segundo número.
     * @return O resultado da soma de a e b.
     */
    double somar(double a, double b) {
        return a + b;
    }

    /**
     * Realiza a operação de subtração entre dois números.
     * @param a O primeiro número.
     * @param b O segundo número.
     * @return O resultado da subtração de a por b.
     */
    double subtrair(double a, double b) {
        return a - b;
    }

    /**
     * Realiza a operação de multiplicação entre dois números.
     * @param a O primeiro número.
     * @param b O segundo número.
     * @return O resultado da multiplicação de a por b.
     */
    double multiplicar(double a, double b) {
        return a * b;
    }

    /**
     * Realiza a operação de divisão entre dois números.
     * @param a O primeiro número.
     * @param b O segundo número. Não deve ser zero.
     * @return O resultado da divisão de a por b ou 0 se b for zero.
     */
    double dividir(double a, double b) {
        if (b != 0) {
            return a / b;
        } else {
            std::cerr << "Erro: Divisão por zero!" << std::endl;
            return 0;
        }
    }

    /**
     * Realiza a operação de potenciação de dois números inteiros.
     * @param base O valor da base.
     * @param expoente O valor do expoente.
     * @return O resultado da base elevada ao expoente.
     */
    int potencia(double base, double expoente) {
        int pot = 1;
        base = int(base); // Converte a base para int
        expoente = int(expoente); // Converte o expoente para int

        for (int i = 0; i < expoente; i++) {
            pot *= base; // Multiplica a base pelo resultado da potenciação
        }
        return pot;
    }

    /**
     * Realiza a operação de radiciação (raiz quadrada).
     * @param a O número do qual se quer calcular a raiz quadrada. Deve ser não negativo.
     * @return A raiz quadrada de a ou 0 se a for negativo.
     */
    double raizQuadrada(double a) {
        if (a >= 0) {
            return sqrt(a); // Utiliza a função sqrt da biblioteca cmath
        } else {
            std::cerr << "Erro: Não é possível calcular a raiz de um número negativo!" << std::endl;
            return 0;
        }
    }

    /**
     * Calcula a porcentagem de um valor.
     * @param total O valor total.
     * @param porcentagem A porcentagem a ser aplicada sobre o total.
     * @return O valor que corresponde à porcentagem do total.
     */
    double porcentagem(double total, double porcentagem) {
        return (total * porcentagem) / 100.0;
    }

    /**
     * Calcula o logaritmo na base 10 de um número.
     * @param a O número do qual se deseja calcular o logaritmo.
     * @return O valor do logaritmo de a na base 10.
     */
    double logaritmoBase10(double a) {
        if (a > 0) {
            return log10(a); // Utiliza a função log10 da biblioteca cmath
        } else {
            std::cerr << "Erro: Logaritmo de número não positivo!" << std::endl;
            return 0;
        }
    }

    /**
     * Calcula o seno de um ângulo em graus.
     * @param angulo O valor do ângulo em graus.
     * @return O valor do seno do ângulo.
     */
    double seno(double angulo) {
        return sin(angulo * M_PI / 180.0); // Converte o ângulo para radianos antes de calcular o seno
    }

    /**
     * Calcula o cosseno de um ângulo em graus.
     * @param angulo O valor do ângulo em graus.
     * @return O valor do cosseno do ângulo.
     */
    double cosseno(double angulo) {
        return cos(angulo * M_PI / 180.0); // Converte o ângulo para radianos antes de calcular o cosseno
    }

    /**
     * Calcula a tangente de um ângulo em graus.
     * @param angulo O valor do ângulo em graus.
     * @return O valor da tangente do ângulo.
     */
    double tangente(double angulo) {
        return tan(angulo * M_PI / 180.0); // Converte o ângulo para radianos antes de calcular a tangente
    }

    /**
     * Converte um valor de graus para radianos.
     * @param graus O valor em graus.
     * @return O valor convertido em radianos.
     */
    double grausParaRadianos(double graus) {
        return graus * M_PI / 180.0;
    }

    /**
     * Converte um valor de radianos para graus.
     * @param radianos O valor em radianos.
     * @return O valor convertido em graus.
     */
    double radianosParaGraus(double radianos) {
        return radianos * 180.0 / M_PI;
    }
};

/**
 * Classe Interface
 * Responsável por gerenciar a interação do usuário com a Calculadora.
 */
class Interface {
private:
    Calculadora calc; // Objeto da classe Calculadora para realizar as operações
    std::deque<std::string> historicoOp; // Deque para armazenar as últimas 5 operações

public:
    /**
     * Adiciona uma operação ao histórico.
     * @param operacao O nome da operação realizada.
     * @param entrada1 O primeiro valor de entrada.
     * @param entrada2 O segundo valor de entrada, se aplicável.
     * @param resultado O resultado da operação.
     */
    void adicionarAoHistorico(const std::string& operacao, double entrada1, double entrada2, double resultado) {
        // Cria uma string formatada com os dados da operação
        std::string registro = operacao + " (" + std::to_string(entrada1) + ", " + std::to_string(entrada2) + ") = " + std::to_string(resultado);
        
        // Adiciona o registro ao deque
        historicoOp.push_front(registro);
        
        // Mantém apenas as últimas 5 operações
        if (historicoOp.size() > 5) {
            historicoOp.pop_back(); // Remove a operação mais antiga
        }
    }
    
    /**
     * Limpa a tela do console usando sequências de escape ANSI.
     * Esta função utiliza códigos ANSI para limpar a tela e reposicionar o cursor
     * no canto superior esquerdo. É uma abordagem multiplataforma que funciona
     * em terminais que suportam ANSI.
     */
    void limparTela() {
        // Sequência ANSI para limpar a tela e reposicionar o cursor
        std::cout << "\033[2J\033[1;1H"; 
        // \033[2J: limpa a tela
        // \033[1;1H: reposiciona o cursor na linha 1, coluna 1
    }

    /**
     * Exibe o histórico das últimas 5 operações realizadas.
     */
    void historico() {
        std::cout << "\n--- Histórico das últimas 5 operações ---\n";
        if (historicoOp.empty()) {
            std::cout << "Nenhuma operação realizada ainda.\n";
        } else {
            for (const auto& op : historicoOp) {
                std::cout << op << std::endl; // Exibe cada operação do deque
            }
        }
    }

    /**
     * Inicia o menu interativo da calculadora, permitindo ao usuário escolher operações.
     */
    void menu() {
        int opcao; // Variável para armazenar a escolha do usuário
        double num1, num2; // Variáveis para armazenar os números de entrada

        do {
            std::cout << "\n--- Calculadora ---\n";
            std::cout << "1. Somar\n";
            std::cout << "2. Subtrair\n";
            std::cout << "3. Multiplicar\n";
            std::cout << "4. Dividir\n";
            std::cout << "5. Potenciação\n";
            std::cout << "6. Radiciação\n";
            std::cout << "7. Porcentagem\n";
            std::cout << "8. Logaritmo base 10\n";
            std::cout << "9. Seno de um ângulo\n";
            std::cout << "10. Cosseno de um ângulo\n";
            std::cout << "11. Tangente de um ângulo\n";
            std::cout << "12. Limpar tela\n";
            std::cout << "13. Exibir histórico\n";
            std::cout << "0. Sair\n";
            std::cout << "Escolha uma opção: ";
            std::cin >> opcao; // Lê a escolha do usuário

            switch (opcao) {
                case 1:
                    std::cout << "Digite o primeiro número: ";
                    std::cin >> num1;
                    std::cout << "Digite o segundo número: ";
                    std::cin >> num2;
                    std::cout << "Resultado: " << calc.somar(num1, num2) << std::endl;
                    adicionarAoHistorico("Soma", num1, num2, calc.somar(num1, num2));
                    break;
                case 2:
                    std::cout << "Digite o primeiro número: ";
                    std::cin >> num1;
                    std::cout << "Digite o segundo número: ";
                    std::cin >> num2;
                    std::cout << "Resultado: " << calc.subtrair(num1, num2) << std::endl;
                    adicionarAoHistorico("Subtração", num1, num2, calc.subtrair(num1, num2));
                    break;
                case 3:
                    std::cout << "Digite o primeiro número: ";
                    std::cin >> num1;
                    std::cout << "Digite o segundo número: ";
                    std::cin >> num2;
                    std::cout << "Resultado: " << calc.multiplicar(num1, num2) << std::endl;
                    adicionarAoHistorico("Multiplicação", num1, num2, calc.multiplicar(num1, num2));
                    break;
                case 4:
                    std::cout << "Digite o primeiro número: ";
                    std::cin >> num1;
                    std::cout << "Digite o segundo número: ";
                    std::cin >> num2;
                    std::cout << "Resultado: " << calc.dividir(num1, num2) << std::endl;
                    adicionarAoHistorico("Divisão", num1, num2, calc.dividir(num1, num2));
                    break;
                case 5:
                    std::cout << "Digite a base: ";
                    std::cin >> num1;
                    std::cout << "Digite o expoente: ";
                    std::cin >> num2;
                    std::cout << "Resultado: " << calc.potencia(num1, num2) << std::endl;
                    adicionarAoHistorico("Potenciação", num1, num2, calc.potencia(num1, num2));
                    break;
                case 6:
                    std::cout << "Digite o número: ";
                    std::cin >> num1;
                    std::cout << "Resultado: " << calc.raizQuadrada(num1) << std::endl;
                    adicionarAoHistorico("Radiciação", num1, 0, calc.raizQuadrada(num1));
                    break;
                case 7:
                    std::cout << "Digite o total: ";
                    std::cin >> num1;
                    std::cout << "Digite a porcentagem: ";
                    std::cin >> num2;
                    std::cout << "Resultado: " << calc.porcentagem(num1, num2) << std::endl;
                    adicionarAoHistorico("Porcentagem", num1, num2, calc.porcentagem(num1, num2));
                    break;
                case 8:
                    std::cout << "Digite o número: ";
                    std::cin >> num1;
                    std::cout << "Resultado: " << calc.logaritmoBase10(num1) << std::endl;
                    adicionarAoHistorico("Logaritmo base 10", num1, 0, calc.logaritmoBase10(num1));
                    break;
                case 9:
                    std::cout << "Digite o ângulo em graus: ";
                    std::cin >> num1;
                    std::cout << "Resultado: " << calc.seno(num1) << std::endl;
                    adicionarAoHistorico("Seno", num1, 0, calc.seno(num1));
                    break;
                case 10:
                    std::cout << "Digite o ângulo em graus: ";
                    std::cin >> num1;
                    std::cout << "Resultado: " << calc.cosseno(num1) << std::endl;
                    adicionarAoHistorico("Cosseno", num1, 0, calc.cosseno(num1));
                    break;
                case 11:
                    std::cout << "Digite o ângulo em graus: ";
                    std::cin >> num1;
                    std::cout << "Resultado: " << calc.tangente(num1) << std::endl;
                    adicionarAoHistorico("Tangente", num1, 0, calc.tangente(num1));
                    break;
                case 12:
                    limparTela();
                    break;
                case 13:
                    historico();
                    break;
                case 0:
                    std::cout << "Saindo..." << std::endl;
                    break;
                default:
                    std::cout << "Opção inválida! Tente novamente." << std::endl;
            }
        } while (opcao != 0); // Continua até que o usuário escolha sair
    }
};

/**
 * Função principal do programa.
 * Inicia a interface da calculadora.
 */
int main() {
    Interface app; // Cria um objeto da classe Interface
    app.menu(); // Inicia o menu da calculadora
    return 0; // Retorna 0 ao sistema indicando que o programa terminou com sucesso
}
