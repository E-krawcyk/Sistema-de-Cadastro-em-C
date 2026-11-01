#include <stdio.h> //Biblioteca padrão de entrada e saída.
#include <locale.h>

void main() // Programa principal.

{
    setlocale (LC_ALL, "Portuguese");
    FILE *cadastro; // Declara a variável utilizada para trabalhar com o arquivo.

    char numpesquisa[30]; // Cria um vetor para armazenar o telefone informado pelo usuário.
    char numlido[12];     // Cria um vetor para armazenar o telefone lido do arquivo.
    char resposta[30];    // Cria um vetor para armazenar a resposta S/s ou N/n.
    char nome[30];        // Cria um vetor para armazenar o nome.
    char sobrenome[30];   // Cria um vetor para armazenar o sobrenome.
    char nascimento[30];  // Cria um vetor para armazenar a data de nascimento.

    int i;              // Variável auxiliar utilizada nos laços e comparações.
    int valido = 1;     // Indica se o telefone informado é válido.
    int linhas = 0;     // Conta as linhas do cabeçalho que serão ignoradas.
    int caractere;      // Armazena cada caractere lido pelo fgetc.
    int encontrado = 0; // Indica se o telefone pesquisado foi encontrado.
    int iguais = 1;     // Indica se o telefone pesquisado é igual ao telefone lido.

    // Define inicialmente a resposta como S para permitir a primeira execução da pesquisa.
    resposta[0] = 'S';
    resposta[1] = '\0';

    // Mantém o programa em execução enquanto o usuário desejar realizar pesquisas.
    while ((resposta[0] == 'S' && resposta[1] == '\0') ||
           (resposta[0] == 's' && resposta[1] == '\0'))
    {
        // Reinicia as variáveis utilizadas em cada nova pesquisa.
        valido = 1;
        linhas = 0;
        encontrado = 0;

        // Abre o arquivo de cadastro no modo de leitura.
        cadastro = fopen("C:\\Users\\Erik\\Documents\\Cadastro\\cadastro.txt", "r");

        // Verifica se ocorreu algum erro ao abrir o arquivo.
        if (cadastro == NULL)

        {
            printf("Erro ao abrir cadastro!");
            return;
        }
        // Solicita o telefone que será utilizado na pesquisa.
        printf("Digite o telefone do usuário que deseja pesquisar: ");
        scanf("%29s", numpesquisa);

        // Verifica se o telefone informado possui apenas números.
        for (i = 0; numpesquisa[i] != '\0'; i++)

        {
            if (numpesquisa[i] < '0' || numpesquisa[i] > '9')
            {
                valido = 0;
            }
        }
        // Verifica se o telefone possui 10 ou 11 dígitos.
        if (i < 10 || i > 11)
        {
            valido = 0;
        }

        // Caso o telefone seja inválido, permite que o usuário informe um novo número.
        while (valido == 0)
        {
            printf("Número de contato inválido!\n");

            printf("Deseja corrigir o número informado? (S/s ou N/n): ");
            scanf("%29s", resposta);

            // Valida a resposta, aceitando somente S, s, N ou n.
            while (!(resposta[0] == 'S' && resposta[1] == '\0') &&
                   !(resposta[0] == 's' && resposta[1] == '\0') &&
                   !(resposta[0] == 'N' && resposta[1] == '\0') &&
                   !(resposta[0] == 'n' && resposta[1] == '\0'))
            {
                printf("Resposta inválida! Digite novamente: ");
                scanf("%29s", resposta);
            }

            // Caso o usuário não queira corrigir o contato, fecha o arquivo e encerra o programa.
            if ((resposta[0] == 'N' && resposta[1] == '\0') ||
                (resposta[0] == 'n' && resposta[1] == '\0'))
            {
                fclose(cadastro);
                return;
            }

            // Caso o usuário queira corrigir, solicita um novo contato.
            if ((resposta[0] == 'S' && resposta[1] == '\0') ||
                (resposta[0] == 's' && resposta[1] == '\0'))

            {
                printf("Digite um novo número de contato: ");
                scanf("%29s", numpesquisa);

                valido = 1; // Considera inicialmente o novo telefone como válido.

                // Verifica novamente se o telefone possui apenas números.
                for (i = 0; numpesquisa[i] != '\0'; i++)
                {
                    if (numpesquisa[i] < '0' || numpesquisa[i] > '9')
                    {
                        valido = 0;
                    }
                }

                // Verifica novamente se o telefone possui 10 ou 11 dígitos.
                if (i < 10 || i > 11)
                {
                    valido = 0;
                }
            }
        }
        // Percorre as cinco primeiras linhas para ignorar o cabeçalho do arquivo.
        while (linhas < 5)
        {
            caractere = fgetc(cadastro);

            // Verifica se o fim do arquivo foi encontrado antes de concluir a leitura do cabeçalho.
            if (caractere == EOF)
            {
                printf("Erro ao ler o arquivo!");
                fclose(cadastro);
                return;
            }

            // Conta cada quebra de linha encontrada.
            if (caractere == '\n')
            {
                linhas++;
            }
        }

        // Lê os cadastros armazenados no arquivo, quatro informações por vez.
        while (fscanf(cadastro, "%29s %29s %11s %29s",
                      nome, sobrenome, numlido, nascimento) == 4)
        {
            // Considera inicialmente que os dois telefones são iguais.
            iguais = 1;

            // Compara caractere por caractere o telefone pesquisado com o telefone lido.
            for (i = 0; numpesquisa[i] != '\0' || numlido[i] != '\0'; i++)
            {
                if (numpesquisa[i] != numlido[i])
                {
                    iguais = 0;
                }
            }
            // Caso os telefones sejam iguais, exibe os dados encontrados.
            if (iguais == 1)
            {
                encontrado = 1;
                printf("\nDados encontrados:\n");
                printf("Nome: %s\n", nome);
                printf("Sobrenome: %s\n", sobrenome);
                printf("Telefone: %s\n", numlido);
                printf("Nascimento: %s\n", nascimento);
            }
        }
        // Informa ao usuário caso nenhum cadastro possua o telefone pesquisado.
        if (encontrado == 0)
        {
            printf("Dados não encontrados.\n");
        }
        // Pergunta ao usuário se deseja realizar outra pesquisa.
        printf("\nDeseja realizar uma nova pesquisa? (S/s ou N/n): ");
        scanf("%29s", resposta);

        // Valida a resposta, aceitando somente S, s, N ou n.
        while (!(resposta[0] == 'S' && resposta[1] == '\0') &&
               !(resposta[0] == 's' && resposta[1] == '\0') &&
               !(resposta[0] == 'N' && resposta[1] == '\0') &&
               !(resposta[0] == 'n' && resposta[1] == '\0'))
        {
            printf("Resposta inválida! Digite novamente: ");
            scanf("%29s", resposta);
        }
        // Caso o usuário não queira realizar outra pesquisa, fecha o arquivo e encerra o programa.
        if ((resposta[0] == 'N' && resposta[1] == '\0') ||
            (resposta[0] == 'n' && resposta[1] == '\0'))
        {
            fclose(cadastro);
            return;
        }
        // Fecha o arquivo antes de iniciar uma nova pesquisa.
        fclose(cadastro);
    }
} // Fechamento do programa.
