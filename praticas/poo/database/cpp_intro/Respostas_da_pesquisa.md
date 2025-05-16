# Pesquisa sobre C++

- Quais as vantagens de uma linguagem compilada em relação a uma interpretada?  
 Linguagens compiladas e interpretadas diferem de como o código é traduzido para a máquina executar, impactando desempenho, segurança e portabilidade.
Onde uma linguagem compilada possui uma execução mais rápida e menor uso de memória, enquanto possui verificação de erros em tempo de compilação.  

- Quais os tipos de comentários em C++?  
 Existe dois formas de criar um comentario, sendo // utilizado para comentarios curtos no final de uma linha e /* */ para explicações mais longas ou para comentar blocos de código.

- O include é um comando para o compilador ou para o pré-processador?  
 o include ocorre na etapa de pré-processamento, que é realizada antes da compilação do código em si.

- O que é o pre-processador? Todos os comandos iniciados por # são para o pré-processador?    
 O pré-processador é uma etapa inicial no processo de compilação de C++ (e C) que processa o código antes que ele seja compilado.
  Todas as diretivas iniciadas por # como o #include são comandos para o pré-processador.

- O que é um namespace? Cite outras linguagens que possuem algo similar.  
 Um namespace é um recurso em C++ que organiza o código em "espaços de nomes" para evitar conflitos entre identificadores.
 Ele permite agrupar código relacionado e evitar colisões de nomes em projetos grandes ou ao combinar diferentes bibliotecas.

- Qual o conceito de escopo em uma linguagem de programação?  
 Escopo em uma linguagem de programação define a visibilidade e a duração de variáveis, funções e outros identificadores em um programa.
 Isso permite que grandes programas sejam desenvolvidos com mais clareza e menos riscos de interferência indesejada entre diferentes partes do código.

- Qual a diferença entre uma variável local e uma global?  
 Variáveis globais têm escopo global e variáveis locais têm escopo limitado ao bloco onde foram declaradas.
 Variáveis globais podem ser acessadas e modificadas em qualquer lugar, podendo gerar dependências indesejadas, enquanto variáveis locais ajudam a limitar o escopo e manter o código modular.

- Quando uma variável é alocada na Stack e quando é alocada na Heap?  
Stack: Usada para variáveis locais de escopo limitado, gerida automaticamente, mais rápida, mas com limites de tamanho.
Heap: Usada para alocação dinâmica e variáveis de duração mais longa, exige gerenciamento manual, e é mais lenta.

- Quais as formas de se inicializar uma variável em C++? Qual a mais recomendada?  
A inicialização uniforme é considerada a forma mais segura de inicialização, pois evita conversões implícitas indesejadas e impede o uso acidental de narrowing

- O que é o buffer de entrada e saída padrão? Como manipular esses buffers?  
 Buffer de Entrada: Armazena dados lidos antes de serem processados.
Buffer de Saída: Armazena dados a serem escritos antes de serem enviados para o dispositivo de saída.
Manipulação dos Buffers: Usando manipuladores como std::flush, std::endl, ou funções como std::cin.ignore() para controlar o fluxo de dados.

- O buffer de entrada sempre são sempre teclado e tela ou podem ser redirecionados?  
Buffers de Entrada e Saída podem ser redirecionados para outras fontes e destinos além do teclado e da tela, incluindo arquivos, pipes, e outros dispositivos.

- Quais os tipos primivos de dados em C++?  
Inteiros: int, short, long, long long, com ou sem sinal (signed/unsigned).
Ponto Flutuante: float, double, long double.
Caractere: char, wchar_t, char16_t, char32_t.
Booleano: bool.
Vazio: void (usado principalmente em funções).

- Quais os principais modificadores de tipo em C++?  
signed / unsigned: Define se o tipo armazena apenas números positivos (unsigned) ou valores com sinal (signed).
short / long: Ajustam o tamanho da variável, alterando a faixa de valores.
const: Torna a variável imutável após a inicialização.
volatile: Indica que a variável pode mudar de forma imprevisível, evitando otimizações excessivas.
mutable: Permite que membros sejam modificados mesmo em objetos constantes.
restrict (C++20): Permite otimizações informando ao compilador que o ponteiro é o único acesso ao objeto apontado.

- Como funciona a palavra reservada auto?  
A palavra-chave auto é uma ferramenta que simplifica o código ao permitir que o compilador deduza o tipo de uma variável, facilitando a manutenção do código e a legibilidade.

- Como fazer a conversão entre tipos primivos em C e com é a sintaxe do static_cast? Qual a diferença entre static_cast e reinterpret_cast?  
Em C, a conversão entre tipos primitivos é feita usando *casting*, que pode ser implícito (automático pelo compilador) ou explícito (usando a sintaxe `(tipo) variável`). Em C++, o **`static_cast`** permite conversões seguras entre tipos compatíveis, sendo verificado em tempo de compilação, como em `static_cast<float>(x)`. Já o **`reinterpret_cast`** realiza conversões mais flexíveis, mas arriscadas, forçando a interpretação de um tipo como outro, como de um ponteiro para `int` para um ponteiro para `char`, podendo resultar em comportamento indefinido.

- Qual a diferença entre o ++ antes e depois de uma variável?  
Em C++, a conversão entre tipos primitivos e ponteiros pode ser feita de várias formas, incluindo a sintaxe C-style casting e o uso de casts específicos como static_cast e reinterpret_cast. A static_cast é usado para conversões seguras e bem definidas, como entre tipos primitivos (ex. int para double) ou entre ponteiros em hierarquias de classes. Ele verifica compatibilidade entre os tipos, evitando conversões inseguras
 Já reinterpret_cast reinterpreta diretamente os bits de uma variável em outro tipo, sendo menos seguro. Ele permite conversões entre ponteiros não relacionados, mas deve ser usado com cuidado, pois pode levar a comportamentos indefinidos.

- Reescreva o seguinte código sem sem usar os operadores unários ++ e -- [LINK](#corrija)

```cpp
int a = 5;
int b = a;
a = a + 1 ;
int c;
a = a + 1;
b = b - 1;
c = a + b;
std::cout << a << " " << b << " " << c << '\n';
```

- Na sintaxe de if, else, existe algum padrão que defina quando usar chaves ou não? Não apenas sobre a sintaxe, mas sobre a legibilidade e boas práticas de programação?  
Usar chaves `{ }` em blocos `if` e `else` é recomendado, mesmo para uma única linha, para melhorar a **legibilidade** e **evitar erros** de manutenção. Sem as chaves, adicionar linhas ao bloco pode causar bugs, pois apenas a primeira linha será considerada parte do `if` ou `else`. Usar chaves sempre também cria um estilo de código **consistente** e mais fácil de ler, especialmente em projetos maiores.

- C++ aceita inicialização de variáveis dentro de um if? No modelo `if (int x = 5; x < value) { ... }`?  
 Sim,C++ aceita a inicialização de variáveis diretamente dentro de uma condição if, esse formato permite declarar e inicializar uma variável local dentro do if, o que limita seu escopo ao próprio bloco condicional.

- Como funciona um operador ternário? Quando vale a pena substituir um if else por um operador ternário?  
O operador ternário em C++ é uma forma compacta de expressar uma condição if-else simples. O operador ternário avalia a expressão condicao. Se condicao for verdadeira, ele retorna valor_se_verdadeiro; se for falsa, retorna valor_se_falso.

- Em c++ função são elementos de primeira classe? O que isso significa?  
Em C++, as funções comuns não são estritamente elementos de primeira classe, mas ponteiros de função e lambdas permitem tratá-las quase como tal, suportando flexibilidade ao manipular funções como variáveis, parâmetros e retornos.

- Qual seria a sintaxe para uma função lambda que recebe dois inteiros e retorna a soma deles?  
auto soma = [](int a, int b) { return a + b; };

- Para que serve um return em função função que não retorna nada?  
Em C++, um return em uma função void (que não retorna um valor) é usado principalmente para encerrar a função antecipadamente.

- Em uma função, melhor criar vários ifs, elses ou múltiplos pontos de return?  
A escolha entre múltiplos return e estruturas if-else depende da simplicidade ou complexidade da função. Múltiplos return são úteis para funções curtas, permitindo saídas antecipadas e tornando o fluxo mais claro sem aninhamento excessivo. Já if-else é mais adequado para decisões complexas, onde é necessário manter um fluxo lógico claro e organizado.

- A passagem de parâmetros em C++ pode ser cópia, ponteiro ou referência. Qual a diferença entre cada uma delas?  
Em C++, a passagem de parâmetros pode ser feita por cópia, ponteiro ou referência, cada uma com características distintas. Passagem por cópia cria uma cópia do valor do parâmetro, ou seja, a variável original não é afetada. Isso é seguro, mas pode ser ineficiente para tipos grandes, como objetos ou grandes estruturas de dados, já que envolve cópias de memória.
Passagem por ponteiro passa o endereço de memória da variável, permitindo que a função modifique diretamente o valor da variável original. Isso pode ser útil para manipulação de grandes estruturas, mas exige cuidado para evitar erros como acesso a ponteiros nulos. Passagem por referência é semelhante à passagem por ponteiro, mas sem a necessidade de usar o operador * ou & explicitamente; as alterações afetam a variável original, oferecendo a eficiência da passagem por ponteiro com a simplicidade da cópia.

- O que é um parâmetro default em uma função?  
Um parâmetro default em uma função é um valor atribuído ao parâmetro caso o chamador não forneça um argumento para ele. Esse valor é especificado na declaração da função e permite que o código seja mais flexível, permitindo chamadas de função com menos argumentos. Se o argumento não for fornecido durante a chamada, o valor default é usado; caso contrário, o valor passado pelo chamador substitui o default. Esse recurso facilita a criação de funções com múltiplas opções de uso sem sobrecarregar a assinatura da função com diversas versões.

- O que é uma função inline? Quando vale a pena usar uma função inline?  
Uma função **inline** em C++ é uma função que o compilador tenta substituir diretamente no ponto de chamada, em vez de realizar uma chamada de função normal, o que pode reduzir a sobrecarga de chamadas. Isso é feito para funções pequenas e de execução rápida, como funções de acesso a dados ou operações simples. Vale a pena usar uma função inline quando o custo de chamada for significativo em relação à operação que a função realiza, especialmente em funções que são chamadas frequentemente, como em loops, mas deve-se evitar em funções grandes, pois a substituição do código pode aumentar o tamanho do binário e prejudicar o desempenho.

- O que seria uma sobrecarga de função? Como o compilador diferencia duas funções com o mesmo nome?  
A **sobrecarga de função** ocorre quando várias funções têm o mesmo nome, mas diferentes parâmetros (quantidade ou tipo), permitindo que o compilador escolha a função correta com base na chamada. O compilador diferencia as funções pela **assinatura da função**, que inclui o nome, tipo e número de parâmetros, mas não o tipo de retorno. A sobrecarga permite que o código seja mais legível e reutilizável, mas deve ser usada com cautela para evitar ambiguidades e facilitar a manutenção do código.

- Qual a diferença entre passar um parâmetro por cópia ou por referência constante? Quando usar cada um?  
Passar um parâmetro por **cópia** cria uma cópia do valor da variável, o que pode ser ineficiente para tipos grandes, pois implica em duplicação de memória, e a função não pode modificar o valor original. Já passar um parâmetro por **referência constante** (`const &`) evita a cópia, passando o endereço da variável original, mas impede modificações no valor dentro da função, o que é eficiente para grandes objetos e garante segurança. Use passagem por cópia para tipos simples ou quando for necessário modificar o parâmetro, e referência constante quando não for necessário modificar o valor, mas se deseja evitar cópias desnecessárias, especialmente com objetos ou estruturas grandes.

- Qual a diferença entre declaração e definição de uma função?  
A **declaração** de uma função especifica seu nome, tipo de retorno e parâmetros, permitindo que o compilador saiba sobre sua existência, mas sem fornecer a implementação; ela é usada para informar ao compilador sobre a função antes de seu uso. A **definição**, por outro lado, fornece a implementação completa da função, ou seja, o corpo da função com o código que será executado. A declaração é necessária para garantir que o código possa chamar a função antes de sua definição, enquanto a definição é necessária para que a função tenha efeito no programa.

- O que é a tabela de símbolos de um programa? Como ela é usada pelo compilador?  
A **tabela de símbolos** é uma estrutura de dados usada pelo compilador para armazenar informações sobre as variáveis, funções, classes e outros identificadores utilizados no programa, como seu tipo, escopo e local na memória. Ela é construída durante o processo de compilação e é usada pelo compilador para realizar verificações semânticas, como verificar o uso correto de variáveis e funções, além de auxiliar na geração de código. Durante a compilação, a tabela de símbolos ajuda o compilador a resolver referências e otimizar o código, associando os identificadores aos seus valores ou endereços correspondentes.

- Qual o tipo padrão de um texto "Hello World" em C++?  
Em C++, o tipo padrão de um texto como "Hello World" é `const char[]`, ou seja, um array de caracteres constantes (também chamado de string literal). Literalmente, a string "Hello World" é representada como um conjunto de caracteres, terminados por um caractere nulo (`'\0'`), que indica o final da string. Se você precisar manipulá-la como um tipo mais flexível e moderno, pode usar a classe `std::string` da biblioteca padrão, que oferece funcionalidades adicionais para trabalhar com textos de maneira mais eficiente e prática.

- Quais as formas de se criar um laço de repetição em C++?  
Em C++, as formas mais comuns de criar laços de repetição são o **`for`**, **`while`** e **`do-while`**. O laço **`for`** é usado quando o número de iterações é conhecido de antemão, como em contagens ou iterações sobre coleções. O **`while`** é utilizado quando a condição de repetição é verificada antes de cada iteração e a quantidade de iterações não é necessariamente conhecida. Já o **`do-while`** garante que o código dentro do laço seja executado pelo menos uma vez, já que a condição é verificada após a execução do corpo do laço. Esses laços permitem um controle flexível de repetição dependendo da lógica do programa.

- O que faz o continue e o break em um laço de repetição?  
Em um laço de repetição, o **`continue`** faz com que a execução pule diretamente para a próxima iteração do laço, ignorando o restante do código dentro do laço para aquela iteração específica. Já o **`break`** encerra completamente o laço, interrompendo sua execução, independentemente de sua condição de repetição. Ambos são úteis para controlar o fluxo de execução dentro de laços de maneira mais flexível, permitindo pular etapas ou sair prematuramente do laço quando necessário.

- Pesquise onde o C++ é mais utilizado e quais as vantagens de se usar essa linguagem em relação a outras.  
C++ é amplamente utilizado em áreas que exigem alto desempenho, como desenvolvimento de jogos, sistemas embarcados, software de tempo real e simulações científicas. Sua capacidade de trabalhar com controle de baixo nível e otimizações de memória o torna ideal para sistemas operacionais, aplicativos de gráficos 3D e até mesmo em finanças, onde a performance é crítica. As principais vantagens do C++ em comparação com outras linguagens são sua portabilidade, permitindo que o código seja executado em diferentes sistemas sem grandes alterações, e a eficiência em termos de velocidade e uso de memória.

- Quais são as principais linguagens com concorrem com C++ e quais as vantagens de cada uma delas?  
O C++ compete com várias outras linguagens de programação, cada uma com suas próprias vantagens. Por exemplo, o Rust está ganhando destaque como uma linguagem para programação de sistemas, devido ao seu forte foco em segurança de memória e concorrência, sem sacrificar o desempenho.
O Go (Golang) se destaca pela simplicidade e eficiência na concorrência, sendo ideal para serviços de backend e sistemas distribuídos.
## Corrija

```cpp
int a = 5;
int b = a++;
int c = ++a + --b;
std::cout << a << " " << b << " " << c << '\n';
```
