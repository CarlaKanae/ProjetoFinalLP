//Definição do tipo para ponteiro (ponteiro de conta)
typedef struct Conta *p_conta;

void inicializar(p_conta pConta[], int tamanho);

//Função para inserir os dados da Struct Conta
void inserirConta(p_conta pConta[], int posicao);

//Função para alterar o nome do usuário
void alterarConta(p_conta pConta[], int tamanho);

//Função para Procurar Uma conta
void procurarConta(p_conta pConta[], int tamanho);

//Função que mostra todas as contas inseridas
void listarConta(p_conta pConta[], int tamanho);

//Função para depositar um valor na conta
void depositar(p_conta pConta[], int tamanho);

//Função para sacar um valor da conta
void sacar(p_conta pConta[], int tamanho);

//Função que detalha uma conta escolhida
void imprimirUmaConta(p_conta pConta);

//Função que soma os saldos de todas as contas existentes
void saldoGeral(p_conta pConta[], int tamanho);

//Função que verifica se existe uma conta ou não
int encontrarConta();

