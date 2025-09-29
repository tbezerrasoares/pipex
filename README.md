# 🚀 pipex

[![Build Status](https://img.shields.io/github/actions/workflow/status/tbezerrasoares/pipex/ci.yml?branch=main&style=flat-square)](https://github.com/tbezerrasoares/pipex/actions)  
[![Coverage](https://img.shields.io/badge/coverage-80%25-green?style=flat-square)](https://github.com/tbezerrasoares/pipex)  
[![License](https://img.shields.io/github/license/tbezerrasoares/pipex?style=flat-square)](./LICENSE)  
[![Last Commit](https://img.shields.io/github/last-commit/tbezerrasoares/pipex?style=flat-square)](https://github.com/tbezerrasoares/pipex/commits/main)  
[![Repo Size](https://img.shields.io/github/repo-size/tbezerrasoares/pipex?style=flat-square)](https://github.com/tbezerrasoares/pipex)

---

O **pipex** é um programa em **C** que simula o funcionamento de *pipelines* em sistemas UNIX.  
Ele conecta dois comandos de forma que a saída de um se torne a entrada do outro, usando um arquivo de entrada (`infile`) e um arquivo de saída (`outfile`).

Exemplo de uso:

```bash
./pipex infile "cmd1" "cmd2" outfile

Estrutura do Repositório

pipex/
│
├── Makefile
├── pipex.h
├── main.c
├── get_path.c
├── utis.c
├── infile
├── outfile
├── codigo/
├── codigo2/
└── README.md
```
Exemplos de Uso

# Exemplo 1:
./pipex infile "grep hello" "wc -l" outfile

# Equivalente a:
< infile grep hello | wc -l > outfile

📜 Conhecimento adquirido

<p> Pipe é uma chamada de sistema que cria um canal de dados unidirecional que pode ser usado para comunicação entre processos. Os dados gravados em uma extremidade do tubo podem ser lidos da outra extremidade do tubo. Os pipes são frequentemente usados em combinação com para criar um canal de comunicação entre os processos pai e filho.</p>
<p> A Pipex se concentra em três conceitos principais: pipelines, processos filhos e execução de comandos.</p>
<p>A ideia geral: lemos do infile, executamos o cmd1 com o infile como entrada, enviamos a saída para o cmd2, que irá gravar no outfile.</p>
<p>./pipex infile cmd1 cmd2 outfile</p>

<h3>Noções Basicas sobres a Funções utilizadas</h3>
<h4>DUP2</h4>
<p>DUP2  ajuda a 'substituir' descritores de arquivos abertos. Por padrão, FD 0, 1 e 2 estão abertos e são definidos como , e respectivamente. permite que você os substitua por outro FD, que você pode obter com . Isso pode ser útil para redirecionar a saída de um FD para outro, como usar para imprimir em um arquivo em vez do terminal.</p>

<h4>EXECVE</h4>
<p>É uma chamada do sistema que permite que você execute outro programa de dentro do seu programa. Ele substitui a imagem do processo atual por uma nova imagem de processo, executando efetivamente um novo programa. São necessários três argumentos: o caminho para o programa a ser executado, uma matriz de argumentos de linha de comando e uma matriz de variáveis de ambiente.</p>

<h4>FORK</h4>
<p>É uma chamada do sistema que cria um novo processo duplicando o processo de chamada. O novo processo é conhecido como o processo filho, enquanto o processo original é conhecido como o processo pai. Após a bifurcação, ambos os processos executam o mesmo código, mas cada um tem um espaço de memória separado.</p>

<h4>PIPE</h4>
<p>A função pipe() em C é usada para criar um pipe, que é um mecanismo de comunicação entre processos. Um pipe é uma estrutura de dados que permite a comunicação unidirecional entre dois processos: um processo pode escrever dados no pipe e o outro pode ler esses dados do pipe. Os pipes são frequentemente usados em sistemas operacionais UNIX e sistemas operacionais semelhantes para a comunicação entre processos.</p>

<h4>WAITPID</h4>
<p>A função waitpid em C é utilizada para esperar pela terminação de um processo filho específico. Ela permite que um processo pai aguarde que um processo filho termine sua execução.</p>

<h3>Importante</h3>
<p>Nos utilizamos variaveis globeis nesse projeto, nesse caso a variavel utilizada errno que é usada para indicar erros durante a execução de funções da biblioteca padrão ou de outras funções que a definem. Esses erros geralmente ocorrem durante operações que não podem ser concluídas com sucesso por algum motivo, como abrir um arquivo que não existe ou realizar uma operação de divisão por zero.</p>
<p>Tambem e utilizado a variavel environ, é uma variável global que contém o ambiente do processo. O ambiente do processo consiste em uma lista de strings de ambiente, onde cada string é da forma "nome=valor", representando uma variável de ambiente e seu valor associado. Essa Variavel e responsalvel por informar os caminhos para os processo que nos utilizaremos para a funcao EXECVE</p>

