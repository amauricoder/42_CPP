## More than 1 paramether

We can also define function templates that accept more than one type parameter, simply by specifying more template parameters between the angle brackets. For example:

``` C++
template <class T, class U> <br>
T GetMin (T a, U b) { <br>
	return (a<b?a:b); <br>
}
```

## instantiate function templates

Em C++, uma função de template é uma função que é definida com um ou mais parâmetros de tipo genérico. Por exemplo:

``` C++
template <typename T> <br>
void print(T value) { <br>
    std::cout << value << std::endl; <br>
}
```

Aqui, print é uma função de template que pode aceitar qualquer tipo T como parâmetro. Porém, essa função ainda não foi criada para um tipo específico, ela é apenas uma definição genérica.

**Quando a função de template é instanciada?**

Quando você chama uma função de template com um tipo específico, o compilador cria (ou instancia) uma versão dessa função para o tipo fornecido. Ou seja, ele gera uma função específica para aquele tipo.

Por exemplo:

``` C++
int main() { 
    print(10);      // Instancia a função print para o tipo int
    print(3.14);    // Instancia a função print para o tipo double
}
```

- Quando você chama print(10), o compilador instancia a função print com o tipo T substituído por int. Ou seja, ele gera uma função print<int>(int value).

- Quando você chama print(3.14), o compilador instancia a função print com o tipo T substituído por double, gerando a função print<double>(double value).

O que acontece na instância?

Quando a função é chamada, o compilador gera código para aquela versão específica do tipo. Então, em vez de ter uma função genérica, você passa a ter uma função totalmente especializada para o tipo que você passou como argumento. Isso é o que significa "instanciar" uma função de template.
Resumo:

Instanciar uma função de template é o processo pelo qual o compilador cria uma versão concreta dessa função para um tipo específico, substituindo os parâmetros de tipo genérico pela instância do tipo concreto que você passou na chamada da função.

