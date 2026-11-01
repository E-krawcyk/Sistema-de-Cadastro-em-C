#include <stdio.h> //Biblioteca padrão de entrada e saída.

void main() // Programa principal.

{
    char resposta[30];   // Cria um vetor para armazenar a resposta S/s ou N/n.
    char nome[30];       // Cria um vetor para armazenar o primeiro nome.
    char sobrenome[30];  // Cria um vetor para armazenar o sobrenome.
    char telefone[30];   // Cria um vetor para armazenar o telefone.
    char nascimento[30]; // Cria um vetor para armazenar a data de nascimento.

    int i;      // Variável auxiliar utilizada nos laços de repetição e na contagem de caracteres.
    int valido; // Variável utilizada para indicar se os dados informados são válidos.

    FILE *cadastro; // Declara a variável que será utilizada para trabalhar com o arquivo.

    // Tenta abrir o arquivo em modo de leitura para verificar se ele já existe.
    cadastro = fopen("C:\\Users\\Erik\\Documents\\Cadastro\\cadastro.txt", "r");

    // Caso o arquivo não exista, ele será criado.
    if (cadastro == NULL)
    {
        cadastro = fopen("C:\\Users\\Erik\\Documents\\Cadastro\\cadastro.txt", "w");

        // Verifica se ocorreu algum erro durante a criação do arquivo.
        if (cadastro == NULL)
        {
            // Caso o arquivo não possa ser aberto, exibe uma mensagem de erro e encerra o programa.
            printf("Erro ao abrir o arquivo!");
            return;
        }

        // Escreve o cabeçalho da tabela quando o arquivo é criado pela primeira vez.
        fprintf(cadastro, "========================================================\n");
        fprintf(cadastro, "                    CADASTRO\n");
        fprintf(cadastro, "========================================================\n");
        fprintf(cadastro, "%-15s%-15s%-14s%-12s\n",
                "NOME", "SOBRENOME", "TELEFONE", "NASCIMENTO");
        fprintf(cadastro, "--------------------------------------------------------\n");
        fclose(cadastro); // Fecha o arquivo após a criação do cabeçalho.
    }

    else
    {
        // Se o arquivo já existia, ele é fechado após a verificação.
        fclose(cadastro);
    }
    // Abre o arquivo no modo "a" para adicionar novos dados sem apagar os cadastros anteriores.
    cadastro = fopen("C:\\Users\\Erik\\Documents\\Cadastro\\cadastro.txt", "a");

    // Verifica se ocorreu algum erro ao abrir o arquivo.
    if (cadastro == NULL)
    {
        // Caso o arquivo não possa ser aberto, exibe uma mensagem de erro e encerra o programa.
        printf("Erro ao abrir o arquivo!");
        return;
    }

    // Pergunta ao usuário se deseja iniciar um cadastro.
    printf("Deseja realizar um cadastro? (S/s ou N/n): "); // Exibe a pergunta para o usuário.
    scanf(" %29s", resposta);                              //  Guarda a informação no vetor resposta.

    // Repete a pergunta enquanto a resposta não for exatamente S, s, N ou n.
    while (!(resposta[0] == 'S' && resposta[1] == '\0') &&
           !(resposta[0] == 's' && resposta[1] == '\0') &&
           !(resposta[0] == 'N' && resposta[1] == '\0') &&
           !(resposta[0] == 'n' && resposta[1] == '\0'))

    {
        printf("Resposta inválida! Digite novamente: "); // Solicita uma nova resposta ao usuário.
        scanf(" %29s", resposta);                        // Guarda a nova resposta no vetor resposta.
    }

    // Enquanto a resposta for exatamente S ou s, o programa fará novos cadastros.
    while ((resposta[0] == 'S' && resposta[1] == '\0') ||
           (resposta[0] == 's' && resposta[1] == '\0'))

    {
        printf("Digite seu primeiro nome: "); // Solicita o primeiro nome do usuário.
        scanf("%29s", nome);                  // Guarda a informação no vetor nome.

        printf("Digite seu sobrenome: "); // Solicita o sobrenome do usuário.
        scanf("%29s", sobrenome);         // Guarda a informação no vetor sobrenome.

        printf("Digite seu telefone para contato: "); // Solicita o telefone para contato do usuário.
        scanf("%29s", telefone);                      // Guarda a informação no vetor telefone.

        valido = 1; // Define inicialmente o dado informado como válido.

        // Verifica se o telefone possui apenas números.
        for (i = 0; telefone[i] != '\0'; i++)
        {
            if (telefone[i] < '0' || telefone[i] > '9')
            {
                valido = 0;
            }
        }

        // Aceita apenas telefones com 10 ou 11 dígitos.
        if (i < 10 || i > 11)
        {
            valido = 0;
        }

        // Solicita novamente o telefone enquanto ele for inválido.
        while (valido == 0)
        {
            printf("Número de contato inválido!\n");
            printf("Digite um telefone válido: ");
            scanf("%29s", telefone);

            valido = 1;

            // Verifica novamente se o telefone possui apenas números.
            for (i = 0; telefone[i] != '\0'; i++)
            {
                if (telefone[i] < '0' || telefone[i] > '9')
                {
                    valido = 0;
                }
            }

            // Verifica novamente se possui 10 ou 11 dígitos.
            if (i < 10 || i > 11)
            {
                valido = 0;
            }
        }

        // Solicita a data de nascimento no formato indicado.
        printf("Digite sua data de nascimento (DD/MM/AAAA): ");
        scanf("%29s", nascimento);

        valido = 1; // Considera inicialmente a nova informação como válida.

        // Conta a quantidade de caracteres da data informada.
        for (i = 0; nascimento[i] != '\0'; i++)
        {
        }
        // A data deve possuir exatamente 10 caracteres.
        if (i != 10)
        {
            valido = 0;
        }

        // Se o tamanho estiver correto, verifica o formato DD/MM/AAAA.
        if (i == 10)
        {
            // As barras devem estar nas posições 2 e 5.
            if (nascimento[2] != '/' || nascimento[5] != '/')
            {
                valido = 0;
            }

            // Verifica se todas as outras posições possuem números.
            for (i = 0; nascimento[i] != '\0'; i++)
            {
                if (i != 2 && i != 5)
                {
                    if (nascimento[i] < '0' || nascimento[i] > '9')
                    {
                        valido = 0;
                    }
                }
            }
        }
        // Solicita novamente a data enquanto o formato estiver inválido.
        while (valido == 0)
        {
            printf("Data de nascimento inválida!\n");
            printf("Digite uma data válida (DD/MM/AAAA): ");
            scanf("%29s", nascimento);

            valido = 1; // Considera inicialmente a nova informação como válida.

            // Conta novamente a quantidade de caracteres.
            for (i = 0; nascimento[i] != '\0'; i++)
            {
            }

            if (i != 10)
            {
                valido = 0;
            }

            if (i == 10)
            {
                // Verifica novamente as barras.
                if (nascimento[2] != '/' || nascimento[5] != '/')
                {
                    valido = 0;
                }

                // Verifica novamente se as demais posições possuem apenas números.
                for (i = 0; nascimento[i] != '\0'; i++)
                {
                    if (i != 2 && i != 5)
                    {
                        if (nascimento[i] < '0' || nascimento[i] > '9')
                        {
                            valido = 0;
                        }
                    }
                }
            }
        }
        // Grava os dados do usuário no arquivo mantendo o formato da tabela.
        fprintf(cadastro, "%-15s%-15s%-14s%-12s\n", nome, sobrenome, telefone, nascimento);

        printf("Deseja realizar um novo cadastro? (S/s ou N/n): "); // Pergunta se o usuário deseja realizar um novo cadastro.
        scanf(" %29s", resposta);                                   // Guarda a nova resposta no vetor resposta.

        // Valida novamente a resposta antes de continuar ou encerrar os cadastros.
        while (!(resposta[0] == 'S' && resposta[1] == '\0') &&
               !(resposta[0] == 's' && resposta[1] == '\0') &&
               !(resposta[0] == 'N' && resposta[1] == '\0') &&
               !(resposta[0] == 'n' && resposta[1] == '\0'))
        {
            // Informa o erro e solicita uma nova resposta para ser verificada.
            printf("Resposta inválida! Digite novamente: ");
            scanf(" %29s", resposta);
        }
    }

    // Fecha o arquivo depois que o usuário encerra os cadastros.
    fclose(cadastro);
}
