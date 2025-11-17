Projeto de Ordenação e Análise de Desempenho

O objetivo deste trabalho é ordenar os dígitos do RGM do aluno (8 dígitos) e comparar o desempenho de diferentes algoritmos de ordenação. Além do RGM, o programa também realiza testes com vetores aleatórios de tamanhos 100, 1000 e 10000 elementos. Em cada teste, o programa mede o número de passos (comparações e trocas) e o tempo de execução em milissegundos. Cada algoritmo é executado 5 vezes e a média dos resultados é impressa em formato CSV.

Métodos de ordenação implementados:
Foram escolhidos 3 métodos:
Bubble Sort
Escolhido por ser simples, fácil de implementar e bom para fins didáticos.
Insertion Sort
Geralmente mais eficiente que o Bubble Sort em vetores pequenos e também simples para estudantes iniciantes.
Quick Sort (não incluído no código)
Apesar de ser muito rápido, não foi utilizado no código entregue para manter a simplicidade do projeto. Foi considerado na seleção, mas por ser mais complexo acabou não sendo implementado. A comparação prática ficou apenas entre Bubble e Insertion.

Obs.: No trabalho final utilizei apenas Bubble e Insertion no código.

Como compilar e rodar
Comando para compilar:
gcc -O1 -std=c11 main.c -o ordena
Para executar:
./ordena
O programa irá:
pedir o RGM (8 dígitos),
ordenar com Bubble e Insertion Sort,
gerar vetores aleatórios,
imprimir os resultados em formato CSV.

contagem de passos:
1 passo para cada comparação
1 passo para cada troca ou movimentação

Isso está implementado no código usando:
(*steps)++;
Essa forma é simples e suficiente para comparar os métodos.

Medição de tempo
A medição do tempo foi feita usando a função clock() da biblioteca time.h.
O cálculo do tempo em milissegundos foi feito assim:
tempo_ms = 1000.0 * (t1 - t0) / CLOCKS_PER_SEC;
Cada algoritmo é executado 5 vezes e o programa calcula a média.

Exemplos de resultados (CSV)
Abaixo um exemplo de saída do programa:
metodo,n,caso,passos,tempo_ms
bubble,8,original,52,0.010
insertion,8,original,29,0.004
bubble,100,original,4970,1.350
insertion,100,original,3090,0.820
bubble,1000,original,507832,122.54
insertion,1000,original,249901,63.22
bubble,10000,original,50011022,13500.22
insertion,10000,original,25008890,6800.12
Os valores variam conforme a máquina, mas o comportamento geral se mantém.

Computabilidade:
Ambos algoritmos ordenaram corretamente todos os vetores, tanto o do RGM quanto os aleatórios. Não houve problemas com números repetidos.
Escalabilidade:
Bubble Sort é o mais lento, pois sua complexidade é O(n²).
Insertion Sort também é O(n²), mas na prática é mais rápido, principalmente em vetores pequenos e moderados.

Limites observados:
Para N = 10000, o Bubble Sort se torna extremamente lento.
Insertion Sort, mesmo sendo O(n²), apresentou desempenho significativamente melhor.

Conclusão:
O algoritmo mais eficiente entre os testados foi o Insertion Sort.
Ele realiza menos passos e gasta menos tempo que o Bubble Sort.
O Bubble Sort ficou em último lugar, como esperado.

Estrutura do projeto
/ordenacao-rgm
main.c
README (este arquivo)
