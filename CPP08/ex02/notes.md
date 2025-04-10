Docs
https://www.cppreference.com/Cpp_STL_ReferenceManual.pdf

**adaptador de container

we basically override the stack by referring to its underlying container
using type alias to sideline its lack of iterator 

### O que é typedef em C++?

O typedef em C++ é usado para criar aliases (apelidos) para tipos de dados. Isso pode tornar o código mais legível e fácil de modificar. A partir do C++11, o typedef pode ser substituído por using, que é uma forma mais moderna e legível.
Exemplo básico de typedef:

typedef unsigned int uint;
uint idade = 25; // Agora uint é um alias para unsigned int

Aqui, uint é apenas um novo nome para unsigned int, facilitando a escrita e leitura do código.


---

typedef typename std::stack<T>::container_type under_ctr;

std::stack<T> é uma pilha baseada em um container subjacente (por padrão, std::deque<T>).
O container_type é um tipo interno da std::stack<T>, que representa o container usado para armazenar os elementos.
Esse typedef cria um alias chamado under_ctr para esse tipo.

---

### **`typedef typename` é sempre obrigatório?**
Depende da situação! Vamos entender quando **precisamos** usar `typename` junto com `typedef` e quando podemos usar apenas `typedef`.

---

## **1. Quando usar apenas `typedef`?**
Se estivermos criando um alias para um **tipo comum** que não depende de um parâmetro de template, podemos simplesmente usar `typedef`.

✅ **Exemplo sem templates (não precisa de `typename`)**
```cpp
typedef unsigned int uint; // Apenas um alias normal
typedef std::deque<int> IntDeque; // Criando um alias para std::deque<int>
```
Neste caso, `typedef` funciona sozinho porque `unsigned int` e `std::deque<int>` já são **tipos concretos conhecidos pelo compilador**.

---

## **2. Quando usar `typedef typename`?**
Se estivermos criando um alias dentro de **uma classe template**, onde o tipo ainda **não é completamente conhecido** pelo compilador, precisamos usar `typename` junto com `typedef`.

### **Por quê?**
O compilador C++ não sabe antecipadamente se algo dentro de um tipo de template é um **tipo (type)** ou um **atributo (member)**. Então, usamos `typename` para dizer explicitamente ao compilador que aquilo é um **tipo**.

---

✅ **Exemplo onde `typename` é necessário**
```cpp
template <typename T>
class MyClass {
public:
    typedef typename std::vector<T>::iterator Iterator;
};
```
**Explicação**:
- `std::vector<T>::iterator` é um **tipo dependente de template** (`T` ainda não é conhecido).
- O compilador pode se confundir e achar que `iterator` é um atributo (variável) em vez de um tipo.
- Então, **precisamos** de `typename` para indicar que `iterator` é um **tipo**.

---

## **3. O caso do `MutantStack`**
No seu código, temos:

```cpp
typedef typename std::stack<T>::container_type under_ctr;
typedef typename under_ctr::iterator iterator;
typedef typename under_ctr::const_iterator const_iterator;
```
- `std::stack<T>::container_type` é **um tipo dependente de template**, então **precisamos** de `typename`.
- `under_ctr::iterator` e `under_ctr::const_iterator` **também são tipos dependentes**, então **precisamos** de `typename`.

Se **removêssemos `typename`**, o compilador daria erro, porque ele não teria certeza de que `container_type` e `iterator` são **tipos**.

---

## **Conclusão**
- ✅ Se for um **tipo normal e conhecido** → **Use apenas `typedef`**.
- ✅ Se for um **tipo dependente de template** → **Use `typedef typename`**.

🚀 **Regra prática:** Sempre que estiver dentro de um **template** e for referenciar um **tipo que depende de `T`**, use `typename` para evitar erros do compilador!


### **O que é um container subjacente?**
Em C++, um **container subjacente** (**underlying container**) é o container interno utilizado por certos adaptadores de containers da STL (**Standard Template Library**) para armazenar seus elementos.  
Isso ocorre porque alguns containers não gerenciam diretamente os elementos, mas utilizam outro container internamente para isso.

---

## **Exemplo: `std::stack<T>` e seu container subjacente**
O `std::stack<T>` é um adaptador de container. Isso significa que ele **não armazena os elementos diretamente**, mas usa outro container (como `std::deque<T>` por padrão) para armazená-los.

### **Como o `std::stack<T>` funciona internamente?**
Por padrão, o `std::stack<T>` usa um `std::deque<T>` como seu **container subjacente**.

```cpp
std::stack<int> s;  // Internamente, isso usa std::deque<int> por padrão
```

Podemos mudar o container subjacente para outro compatível, como `std::vector<T>` ou `std::list<T>`:

```cpp
std::stack<int, std::vector<int>> s; // Agora o stack usa um vector internamente
std::stack<int, std::list<int>> s;   // Agora o stack usa uma list internamente
```

Esse container subjacente é acessível pelo tipo `container_type`, como veremos a seguir.

---

## **Acessando o container subjacente**
Embora o `std::stack<T>` **não forneça iteradores**, o container subjacente sim. Podemos acessá-lo usando `container_type`:

```cpp
#include <iostream>
#include <stack>
#include <vector>

int main() {
    std::stack<int, std::vector<int>> s; // Usando um vector como container interno

    s.push(1);
    s.push(2);
    s.push(3);

    // Acessando o container subjacente
    std::vector<int> &vec = s.*c;  // NÃO FUNCIONA! `c` é protegido.

    return 0;
}
```

A variável `c` que contém o container subjacente é **protegida (`protected`)**, então não podemos acessá-la diretamente. Mas podemos **criar um wrapper para expor esse comportamento**, como na `MutantStack`:

---

## **Usando o container subjacente na `MutantStack`**
Na sua `MutantStack`, estamos acessando diretamente o container subjacente para permitir **iterações**.

```cpp
typedef typename std::stack<T>::container_type under_ctr;
```
Aqui, `under_ctr` é um **alias para o container subjacente** (`std::deque<T>` por padrão).

Depois, criamos iteradores baseados nesse container:
```cpp
typedef typename under_ctr::iterator iterator;
typedef typename under_ctr::const_iterator const_iterator;
```

E finalmente, implementamos os métodos `begin()` e `end()` para expor esses iteradores:

```cpp
iterator begin() { return this->c.begin(); }
iterator end() { return this->c.end(); }
```

Agora, conseguimos iterar sobre a pilha (`MutantStack`), algo que **não é possível com um `std::stack<T>` normal**.

---

## **Resumo**
- O **container subjacente** é o container interno usado por adaptadores de container, como `std::stack<T>`.
- Por padrão, `std::stack<T>` usa `std::deque<T>` como container subjacente, mas podemos mudar para `std::vector<T>` ou `std::list<T>`.
- O container subjacente pode ser acessado pelo tipo `container_type`, mas sua variável interna `c` é protegida (`protected`).
- A `MutantStack` usa o container subjacente para adicionar iteradores, permitindo percorrer seus elementos.

Agora sua `MutantStack` funciona como uma pilha, mas também permite iteração como um `std::deque<T>`! 🚀

### Membro protegido chamado C ###

No código fornecido, o `c` representa o **container subjacente** da classe `MutantStack`. Esse é um membro protegido da classe `std::stack` da biblioteca padrão do C++.  

### Explicação:  

A classe `std::stack` em C++ é um contêiner adaptador, o que significa que ela é construída sobre outro contêiner (como `std::deque`, `std::vector` ou `std::list`). Esse contêiner interno pode ser acessado através do membro protegido chamado **`c`**.  

No trecho do código:  

```cpp
template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin()
{
	return (this->c.begin());
}
```
- `this->c` acessa o contêiner subjacente da `std::stack`.
- `.begin()` retorna um iterador apontando para o primeiro elemento desse contêiner.

### Observação Importante  

A classe `std::stack` **não fornece iteradores por padrão** porque é uma estrutura baseada no conceito de **Pilha (LIFO)**. No entanto, ao expor o iterador do container subjacente (`c`), a `MutantStack` permite a iteração sobre seus elementos, algo que não é possível diretamente com `std::stack`.

Se precisar de mais detalhes, posso explicar com um código completo! 🚀

---

### **Como saber se uma estrutura usa um container subjacente?**  
Uma **estrutura utiliza um container subjacente** quando é um **adaptador de container** (**container adapter**).  

📌 **O que é um adaptador de container?**  
- Um adaptador de container **não armazena elementos diretamente**, mas usa outro container internamente para fazer isso.  
- Ele apenas **restringe ou modifica** a interface desse container interno, fornecendo uma funcionalidade específica.  
- Exemplos: `std::stack<T>`, `std::queue<T>`, `std::priority_queue<T>`  

---

## **🔍 Como descobrir se uma estrutura usa um container subjacente?**  

### **1️⃣ Pela documentação da STL**  
A documentação oficial do C++ geralmente menciona que a estrutura é um **adaptador de container** e usa um **container subjacente padrão**.  

Exemplo da documentação do `std::stack<T>`:
> "std::stack is a container adaptor that gives the programmer the functionality of a stack — specifically, a LIFO (last-in, first-out) data structure. The class template acts as a wrapper to the underlying container."

🔎 A palavra **"container adaptor"** já indica que `std::stack<T>` usa um container interno.

---

### **2️⃣ Pela definição da estrutura na STL**  
Se olharmos a definição de `std::stack<T>` no código-fonte da STL, veremos que ele usa um **template** para o container subjacente:

```cpp
template <typename T, typename Container = std::deque<T>>
class stack {
protected:
    Container c;  // O container subjacente que realmente armazena os elementos
public:
    void push(const T& val) { c.push_back(val); }
    void pop() { c.pop_back(); }
    T& top() { return c.back(); }
};
```
🔍 O `std::stack<T>` **não implementa diretamente o armazenamento de elementos**. Ele **depende de um container interno** (`c`) para isso.

---

### **3️⃣ Pela ausência de iteradores (`begin()`, `end()`)**  
Adaptadores de container geralmente **não fornecem iteradores** porque **não expõem diretamente seus elementos internos**.  

Exemplo:
```cpp
std::stack<int> s;
s.push(1);
s.push(2);

// ❌ ERRO! std::stack<T> não tem iteradores:
for (std::stack<int>::iterator it = s.begin(); it != s.end(); ++it) {
    std::cout << *it;
}
```
❌ O código acima **não compila**, pois `std::stack<T>` **não fornece iteradores**!  
Isso ocorre porque ele **esconde o container interno** e só permite acesso controlado via `push()`, `pop()` e `top()`.

📌 **Conclusão**: Se uma estrutura da STL **não fornece iteradores**, pode ser um adaptador de container.

---

## **📌 Estruturas que utilizam container subjacente**  
As principais estruturas da STL que utilizam **containers subjacentes** são:

| Estrutura | Tipo de Adaptação | Container Padrão |
|-----------|-----------------|----------------|
| `std::stack<T>` | **Pilha (LIFO)** | `std::deque<T>` |
| `std::queue<T>` | **Fila (FIFO)** | `std::deque<T>` |
| `std::priority_queue<T>` | **Fila de prioridade (heap máximo)** | `std::vector<T>` |

### **🔹 `std::queue<T>` (Fila FIFO)**
```cpp
std::queue<int> q;  // Internamente usa std::deque<int>
```
- Usa `std::deque<T>` por padrão.
- **Permite acesso apenas ao início e ao fim**.
- **Não tem iteradores**.

---

### **🔹 `std::priority_queue<T>` (Fila de prioridade)**
```cpp
std::priority_queue<int> pq;  // Internamente usa std::vector<int>
```
- Usa `std::vector<T>` por padrão.
- **Ordena os elementos internamente** com um heap.
- **Não tem iteradores**.

---

## **🛠 Como acessar o container subjacente?**  
Por padrão, o container interno (`c`) de `std::stack<T>`, `std::queue<T>` e `std::priority_queue<T>` é **protegido** (`protected`).  
Mas podemos acessar ele em uma classe derivada:

```cpp
#include <iostream>
#include <stack>

template <typename T>
class MyStack : public std::stack<T> {
public:
    void print() {
        typename std::stack<T>::container_type& container = this->c;
        for (auto it = container.begin(); it != container.end(); ++it) {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    MyStack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    
    s.print();  // Saída: 1 2 3
}
```
👉 **Aqui, conseguimos acessar `c` e iterar sobre o container subjacente!** 🚀

---

## **📌 Resumo**
- **Containers adaptadores** (como `std::stack<T>`, `std::queue<T>`, `std::priority_queue<T>`) **usam um container subjacente** para armazenar elementos.  
- **O container subjacente padrão varia** (`std::deque<T>` para `std::stack<T>` e `std::queue<T>`, `std::vector<T>` para `std::priority_queue<T>`).  
- **Eles não possuem iteradores (`begin()`, `end()`)**, pois escondem o container interno.  
- **Podemos acessar o container subjacente (`c`) em uma classe derivada**.

Isso explica **como identificar e manipular containers subjacentes**! 🚀