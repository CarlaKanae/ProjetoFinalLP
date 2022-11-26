//Definição do tipo para ponteiro (ponteiro de conta)
typedef struct Conta *p_conta;

void inicializar(p_conta pConta[], int tamanho);

void inserirConta(p_conta pConta[], int posicao);

void alterarConta(p_conta pConta[], int tamanho);

void procurarConta(p_conta pConta[], int tamanho);

void listarConta(p_conta pConta[], int tamanho);

void depositar(p_conta pConta[], int tamanho);

void sacar(p_conta pConta[], int tamanho);

void imprimirUmaConta(p_conta pConta);

void saldoGeral(p_conta pConta[], int tamanho);

int getConta();

