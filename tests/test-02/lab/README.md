# Prova 02

1. **(1.5)** Nesta questão, você deve implementar uma função **recursiva** que encontra o elemento máximo armazenado em uma lista ligada `L` e que devolve um ponteiro para algum nó que armazena esse máximo. Se `L` for uma lista vazia, sua função deve devolver `NULL`. Sua função deve ter o seguinte cabeçalho:

   ```c
   p_no maximo(p_no L);
   ```

   Você deve implementar somente o corpo dessa função no arquivo `lista01.c` que se encontra no diretório `LAB/QUESTAO_01`. Você não deve mexer em nenhuma outra parte do código, em nenhum dos arquivos nesse diretório.

1. **(2.5)** Nesta questão você deve definir uma função que percorre uma lista ligada `L`, excluindo todos os nós cujos itens sejam **menores** que um dado valor `k`, e que retorna um ponjteiro para o primeiro nó da lista que restou. Se `L` for uma lista vazia, sua função deve devolver `NULL`. Sua função deve ter o seguinte cabeçalho:

   ```c
   p_no remove_menores(p_no L, long k);
   ```

   Você deve implementar somente o corpo dessa função no arquivo `lista02.c` que se encontra no diretório `LAB/QUESTAO_02`. Você não deve mexer em nenhuma outra parte do código, em nenhum dos arquivos nesse diretório.

   Excluir um nó `x` da lista significa retirá-lo da lista e chamar `exclui(x)`, uma função declarada em `lista.h` e definida no arquivo `lista02.c`.