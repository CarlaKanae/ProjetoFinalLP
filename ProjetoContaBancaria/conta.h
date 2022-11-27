//Defini��o do tipo para ponteiro (ponteiro de conta)
typedef struct Conta *p_conta;

void inicializar(p_conta pConta[], int tamanho);

//Fun��o para inserir os dados da Struct Conta
void inserirConta(p_conta pConta[], int posicao);

//Fun��o para alterar o nome do usu�rio
void alterarConta(p_conta pConta[], int tamanho);

//Fun��o para Procurar Uma conta
void procurarConta(p_conta pConta[], int tamanho);

//Fun��o que mostra todas as contas inseridas
void listarConta(p_conta pConta[], int tamanho);

//Fun��o para depositar um valor na conta
void depositar(p_conta pConta[], int tamanho);

//Fun��o para sacar um valor da conta
void sacar(p_conta pConta[], int tamanho);

//Fun��o que detalha uma conta escolhida
void imprimirUmaConta(p_conta pConta);

//Fun��o que soma os saldos de todas as contas existentes
void saldoGeral(p_conta pConta[], int tamanho);

//Fun��o que verifica se existe uma conta ou n�o
int encontrarConta();

