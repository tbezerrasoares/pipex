# pipex

<p> Pipe é uma chamada de sistema que cria um canal de dados unidirecional que pode ser usado para comunicação entre processos. Os dados gravados em uma extremidade do tubo podem ser lidos da outra extremidade do tubo. Os pipes são frequentemente usados em combinação com para criar um canal de comunicação entre os processos pai e filho.</p>
<p> A Pipex se concentra em três conceitos principais: pipelines, processos filhos e execução de comandos.</p>

<h3>Noções Basicas sobres a Funções utilizadas</h3>
<h4>DUP2</h4>
<p>DUP2  ajuda a 'substituir' descritores de arquivos abertos. Por padrão, FD 0, 1 e 2 estão abertos e são definidos como , e respectivamente. permite que você os substitua por outro FD, que você pode obter com . Isso pode ser útil para redirecionar a saída de um FD para outro, como usar para imprimir em um arquivo em vez do terminal.</p>

<h4>ACCESS</h4>
<p>Verifica se um processo tem permissão para acessar um arquivo ou diretório. São necessários dois argumentos: o caminho para o arquivo ou diretório e um modo que representa o tipo de acesso que está sendo verificado. O modo é especificado usando constantes como , e , que representam permissões de leitura, gravação e execução, respectivamente.R_OK W_OK X_OK</p>

<h4>EXECVE</h4>
<p>É uma chamada do sistema que permite que você execute outro programa de dentro do seu programa. Ele substitui a imagem do processo atual por uma nova imagem de processo, executando efetivamente um novo programa. São necessários três argumentos: o caminho para o programa a ser executado, uma matriz de argumentos de linha de comando e uma matriz de variáveis de ambiente.</p>

<h4>FORK</h4>
<p>É uma chamada do sistema que cria um novo processo duplicando o processo de chamada. O novo processo é conhecido como o processo filho, enquanto o processo original é conhecido como o processo pai. Após a bifurcação, ambos os processos executam o mesmo código, mas cada um tem um espaço de memória separado.</p>
