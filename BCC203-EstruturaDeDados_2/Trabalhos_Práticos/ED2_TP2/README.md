# Instruções de Compilação e Execução

## Passo 1: Configurar o Ambiente de Compilação
Entre no diretório `build` do projeto e configure o modo de compilação desejado:

### Modo Release (Compilação Otimizada)
```console
cmake -DCMAKE_BUILD_TYPE=Release ..
```
### Modo Debug (Compilação para Depuração)
```console
cmake -DCMAKE_BUILD_TYPE=Debug ..
```
## Passo 2: Compilar o Projeto
Após configurar o ambiente, você pode compilar o projeto utilizando um dos comandos abaixo:

### Usando Make
```console
make
```

### Usando CMake
```console
cmake --build .
```
## Passo 3: Executar o Programa
Após a compilação, o executável será gerado no diretório correspondente ao modo de compilação escolhido:

- Modo Release: `bin/Release`
- Modo Debug: `bin/Debug`

Navegue até o diretório apropriado e execute o programa `ordena` com os parâmetros necessários:

```console
./ordena <método> <quantidade> <situação> [-p | -P]
```

### Descrição dos Parâmetros

Ao executar o programa `ordena`, você precisa fornecer os seguintes parâmetros na linha de comando:

1. `<método>`:
  - Especifica o método de ordenação externa a ser utilizado.
  - Valores possíveis:
    - `1`: **Intercalação balanceada** de vários caminhos (**2f fitas**) utilizando, na etapa de geração dos blocos 
ordenados, **qualquer método de ordenação interna** apresentado em "Estrutura de Dados I".
    - `2`: **Intercalação balanceada** de vários caminhos (**2f fitas**) utilizando, na etapa de geração dos blocos 
ordenados, a **técnica de seleção por substituição** apresentada em "Estrutura de Dados II".
    - `3`: **Quicksort externo**.
2. `<quantidade>`:
  - Define a quantidade de alunos (linhas do arquivo texto) a serem ordenados.
  - Deve ser um número inteiro positivo maior que 0.
3. `<situação>`:
  - Indica a situação inicial dos registros a serem ordenados.
  - Valores possíveis:
    - `1`: Dados em ordem **crescente** pelas **notas**.
    - `2`: Dados em ordem **decrescente** pelas **notas**.
    - `3`: Dados em ordem **aleatória** pelas **notas**.
4. `[-p | -P]`:
  - Especifica se o programa deve exibir informações adicionais durante a execução, como:
    - Dados dos alunos a serem ordenados e o resultado da ordenação realizada.