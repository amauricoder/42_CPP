## static_cast

O operador static_cast é o operador de conversão mais comumente usado em C++. 
Ele realiza conversão de tipo em tempo de compilação e é usado principalmente 
para conversões explícitas que são consideradas seguras pelo compilador.

static_cast < new_type > (expression);
onde
- expressao: Dados a serem convertidos.
- new_type: tipo de expressao desejado.

exemplo de static cast:

``` C++
	int main()
	{

	    int num = 10;

	    // converting int to double
	    double numDouble = static_cast<double>(num);

	    // printing data type
	    cout << typeid(num).name() << endl;

	    // typecasting
	    cout << typeid(static_cast<double>(num)).name() << endl;

	    // printing double type t
	    cout << typeid(numDouble).name() << endl;

	    return 0;
	}
``` 
Neste exemplo, incluímos a biblioteca “typeinfo” para que possamos usar a função typeid() para verificar o tipo de dados. Definimos uma variável inteira 'num' e a convertemos em um double usando static_cast. Depois disso, imprimimos os tipos de dados das variáveis ​​e passamos static_cast<double>(num) na função typeid() para verificar seu tipo de dados. Podemos ver a saída “i, d, d” impressa, onde 'i' denota inteiro e 'd' denota double .



Double literals (default for floating-point numbers in C++):
	0.0, -4.2, 4.2, +inf, -inf, nan.

Float literals (use f suffix):
	0.0f, -4.2f, 4.2f, +inff, -inff, nanf.

Convert them into actual floating-point representations:
	Use std::numeric_limits<float>::infinity() for +inff -std::numeric_limits<float>::infinity() for -inff.
	Use std::nan("") for nan or std::nanf("") for nanf.