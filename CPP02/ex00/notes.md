## Orthodox Canonical Form - Convention
Eh uma convencao criada para criacao de classese em C++,
que seguem um conjunto bem definido de metodos, garantindo que a classe seja gerenciada corretamente em situacoes como copia, atribuicao e destruicao.
- Default Constructor - Inicializa o objeto sem parametros
- Copy Constructor - Cria um novo objeto como copia de outro
- Copy assignment operator - Permite atribuir o conteudo de um objeto a outro ja existente
- Destructor - Limpa os recursos alocados pelo objeto.

**Por que usar?**

Alem de ser obrigatorio pelo subject, ela garante que:
- Recursos alocados dinamicamente sejam gerenciados corretamente.
- Evite problemas como double delete ou leaks.

## Resumo artigo
>> https://www.cprogramming.com/tutorial/floating_point/understanding_floating_point.html

Este texto explora as complexidades e nuances de trabalhar com números de ponto flutuante em programação, desmistificando conceitos e desafios comuns. Aqui estão os principais pontos abordados:

1. Diferenças Conceituais entre Inteiros e Ponto Flutuante:
- Inteiros: São precisos e exatos para operações aritméticas, desde que não haja estouro de valores. No entanto, perdem informações quando lidam com frações (ex.: 5/2 = 2, descartando o restante).
- Ponto Flutuante (floats): Oferecem boa precisão para representar frações e números muito grandes ou pequenos, mas sofrem com falta de exatidão. Nem todos os números podem ser representados com total fidelidade, devido à limitação do formato binário.

2. A Ilusão dos Números de Ponto Flutuante:
- Eles parecem "números reais" com casas decimais, mas sua representação interna é complexa e menos direta que a dos inteiros. Como resultado, podem conter menos valores distintos do que o equivalente em inteiros para o mesmo número de bits.

3. Problemas de Igualdade e Exatidão:
- Comparações diretas (usando ==) frequentemente falham porque números que parecem iguais visualmente podem diferir ligeiramente em sua representação interna.
- Fórmulas matematicamente corretas podem gerar resultados inesperados ou imprecisos devido a erros de arredondamento e limitações de representação.

4. Analogia: Tijolos vs. Massa de Modelar:
- Inteiros são comparados a tijolos: podem construir formas exatas (como um cubo), mas têm dificuldade com formas suaves ou fracionárias (como uma esfera).
- Floats são como massa de modelar: podem criar curvas complexas, mas nunca alcançar uma forma perfeita e precisa.

5. Erros Inerentes à Representação Binária:
- Nem todas as frações podem ser representadas exatamente em qualquer base numérica (exemplo: 1/3 não tem representação exata em decimal ou binário). Isso implica que os resultados com floats sempre terão algum grau de erro.

**Conclusão**

Números de ponto flutuante são ferramentas poderosas, mas suas limitações exigem cuidado. Entender como funcionam internamente e aceitar as imprecisões inerentes ajuda a utilizá-los de forma produtiva e evitar erros em programas.

---

>> https://www.cprogramming.com/tutorial/floating_point/understanding_floating_point_representation.html

Representação em IEEE-754

O padrão IEEE-754 é amplamente usado para representação de números em ponto flutuante. Ele define que um número é composto por três partes:

    Bit de sinal: Indica se o número é positivo ou negativo.
    Expoente: Define a ordem de magnitude.
    Mantissa: Contém os dígitos significativos.

Cálculo do valor:
O número é dado por mantissa × 2expoente. Para evitar redundâncias, assume-se um "1" implícito na mantissa (formato "1.m"), exceto em casos especiais como o zero.

Casos Especiais

    Zero: Representado quando todos os bits são 0 (sinal irrelevante).
    1.0: Requer um ajuste no expoente; o valor armazenado é expoente − 127expoente − 127 (para floats).
    Infinitos e NaN: Representados por valores específicos do expoente e da mantissa. Por exemplo, +∞ ocorre quando o expoente é máximo e a mantissa é zero.

Propriedades Importantes

    Maior número representável: 3.402823466 × 10^38 (float) e 1.7976931348623157 × 10^308 (double).
    Menor número sem perda de precisão: 1.175494351 × 10^−38.(float).
    Menor número representável: 1.401298464 × 10^−45 (float).

Operações Numéricas

    Igualdade: Comparar floats diretamente é problemático devido a imprecisões. Em vez disso, verifica-se se a diferença entre dois números é menor que uma constante (EPSILONEPSILON).
    Overflow: Floats lidam bem com overflow retornando +∞ ou −∞. Entretanto, conversões entre tipos numéricos podem causar perda de precisão.
    Perda de Significância: Subtrair números próximos ou somar números de magnitudes muito diferentes pode resultar em perda de precisão. Estratégias incluem reordenar cálculos ou usar aproximações.

Dicas para Programação Efetiva

    Evite cálculos que envolvam retroalimentação excessiva (feedback loops).
    Prefira fórmulas estáveis e reescreva operações para minimizar erros.
    Use inteiros para armazenar frações racionais quando apropriado, evitando problemas com ponto flutuante.

Conclusão

Embora o ponto flutuante seja poderoso, exige cuidado em sua manipulação devido às limitações de precisão e representação. Entender suas nuances é essencial para evitar erros numéricos em cálculos complexos.

---

https://www.cprogramming.com/tutorial/floating_point/understanding_floating_point_printing.html

---

### Fixed-point arithmetic

A aritmética de ponto fixo (fixed-point arithmetic) em C++ é uma alternativa à aritmética de ponto flutuante, sendo útil em aplicações que exigem desempenho em hardware com recursos limitados ou maior controle sobre precisão. Em vez de representar números com mantissa e expoente (como ponto flutuante), os números de ponto fixo são armazenados como inteiros, com um deslocamento fixo para representar frações.

1. Conceitos Básicos

Um número de ponto fixo é representado como um número inteiro escalado por um fator 2n (em binário) ou 10n (em decimal).
Por exemplo:

    Com uma escala de 2^8 (n=8), o número inteiro 256 representa 256/2^8=1.0.
    Uma escala maior permite mais precisão, mas com maior risco de overflow.


# Copy assignment operator

O Copy Assignment Operator (Operador de Atribuição por Cópia) é um operador especial em C++ que permite atribuir os valores de um objeto a outro objeto já existente do mesmo tipo. Ele é chamado quando você usa o operador de atribuição (=) para copiar os valores de um objeto para outro, após ambos já terem sido inicializados.
Quando o Copy Assignment Operator é chamado?

O Copy Assignment Operator é chamado quando um objeto já existente recebe os valores de outro objeto. Por exemplo:

FixedPoint obj1;
FixedPoint obj2;
obj2 = obj1;  // Copy Assignment Operator é chamado aqui

Nesse exemplo, o operador de atribuição por cópia (operator=) é invocado quando obj2 = obj1; é executado. Isso ocorre após os dois objetos já terem sido criados. O objetivo do operador é copiar o estado de obj1 para obj2, mas sem destruir o conteúdo anterior de obj2.
O que o Copy Assignment Operator faz?

O objetivo do Copy Assignment Operator é copiar o estado de um objeto para outro já existente. Isso envolve:

    Liberar quaisquer recursos já alocados pelo objeto de destino (se necessário).
    Copiar os dados do objeto fonte (o que está à direita do operador =) para o objeto de destino (o que está à esquerda).
    Garantir que o objeto de destino seja atribuído corretamente, sem causar problemas como auto-atribuição (quando o objeto é atribuído a ele mesmo).

Exemplo de implementação do Copy Assignment Operator

Vamos considerar a classe FixedPoint com membros simples, como int _number_value e um membro static (que não precisa ser copiado). Aqui está como você pode implementar o Copy Assignment Operator para essa classe:

class FixedPoint
{
	private:
		int _number_value;
		static const int _fractional_bits;

	public:
		FixedPoint() : _number_value(0) {}  // Construtor padrão
		FixedPoint(const FixedPoint &obj) : _number_value(obj._number_value) {}  // Copy constructor
		~FixedPoint() {}

		// Getter
		int GetNumberValue() const { return _number_value; }

		// Atribuição por cópia
		FixedPoint& operator=(const FixedPoint &obj)
		{
			std::cout << "Copy assignment operator called" << std::endl;

			if (this != &obj)  // Verifique se não é uma auto-atribuição
			{
				_number_value = obj._number_value;  // Copiar o valor de _number_value
				// Não é necessário copiar _fractional_bits, pois é estático
			}
			return *this;  // Retorna o objeto atual para permitir atribuições encadeadas
		}
};

Explicação do código:

    Verificação de auto-atribuição (if (this != &obj)):
        Essa verificação impede que o objeto seja copiado para ele mesmo. Se a atribuição for entre o mesmo objeto (ou seja, obj1 = obj1), não há necessidade de realizar qualquer operação.
        Caso contrário, se a verificação falhar, significa que estamos tentando copiar os dados de um objeto para ele mesmo, o que pode causar erros de comportamento inesperado.

    Atribuição dos membros (_number_value = obj._number_value):
        Depois de garantir que não há auto-atribuição, copiamos os dados do objeto fonte (obj) para o objeto de destino (this).
        Membro static: O membro _fractional_bits não precisa ser copiado, pois ele é estático e compartilha o mesmo valor para todas as instâncias da classe.

    Retorno de *this:
        O operador de atribuição por cópia deve retornar o próprio objeto (*this), o que permite a atribuição encadeada. Isso significa que você pode fazer algo como:

    obj1 = obj2 = obj3;

Quando você precisa implementar o Copy Assignment Operator?

Você precisa implementar o Copy Assignment Operator nas seguintes situações:

    Quando sua classe aloca recursos dinamicamente (como memória ou arquivos), e você precisa garantir que a cópia de um objeto libere corretamente os recursos do objeto de destino e copie os dados de forma segura.
    Quando sua classe possui membros que não podem ser copiados diretamente (por exemplo, ponteiros para recursos dinâmicos) e você precisa gerenciar a cópia desses recursos manualmente.

Quando o Copy Assignment Operator é automaticamente gerado?

Se você não definir explicitamente um Copy Assignment Operator em sua classe, o compilador pode gerar um Copy Assignment Operator padrão. Este operador faz uma cópia simples dos membros da classe de um objeto para outro, membro por membro.

Contudo, se você estiver trabalhando com recursos dinâmicos, você precisa escrever seu próprio operador de atribuição para gerenciar a cópia corretamente, a fim de evitar problemas como vazamentos de memória ou duplicaçãode recursos.
Resumo:

    O Copy Assignment Operator é usado para copiar os dados de um objeto para outro já existente.
    Ele é chamado quando você usa o operador de atribuição = em objetos já existentes.
    O operador deve ser implementado manualmente se você estiver lidando com recursos que precisam de uma cópia personalizada (por exemplo, alocação dinâmica de memória).
    Sempre verifique a auto-atribuição com if (this != &obj) para evitar cópias desnecessárias e erradas.

