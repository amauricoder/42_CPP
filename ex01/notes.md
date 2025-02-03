O método `std::vector::insert()` insere elementos no `vector` a partir de um determinado local, deslocando os elementos existentes para a direita para dar espaço aos novos.

### Sintaxe relevante para o seu caso:
```cpp
iterator insert (iterator position, InputIterator first, InputIterator last);
```
Este método insere no `vector` todos os elementos do intervalo `[first, last)` na posição indicada por `position`.

---

### Como aplicar no seu código:
Você quer inserir elementos de outro range dentro do `_data`. Então, a chamada correta dentro da sua função seria:
```cpp
_data.insert(_data.end(), start, end);
```
Aqui está o que acontece:
1. `_data.end()` → Insere os novos elementos no final do vetor.
2. `start` e `end` → Representam o intervalo que você quer adicionar.

---

### Código corrigido:
```cpp
void Span::addRange(std::vector<int>::iterator start, std::vector<int>::iterator end)
{
    if (_data.size() + std::distance(start, end) > this->_maxqt)
        throw MaxElementsStored();

    _data.insert(_data.end(), start, end);
}
```
Isso adiciona todos os elementos do range `[start, end)` no final do `_data`.

---
### **Iteradores em `std::vector<int>`: Como posicioná-los?**  

Diferente de `std::stack<T>`, o `std::vector<T>` **possui iteradores** e permite acesso direto aos elementos. Você pode usar iteradores para percorrer o `vector` e até posicioná-los em locais específicos.  

---

## **🔹 Criando um `std::vector<int>` e iterando sobre ele**  

```cpp
#include <iostream>
#include <vector>

int main() {
    std::vector<int> vec = {10, 20, 30, 40, 50};

    // Criando um iterador que aponta para o início do vetor
    std::vector<int>::iterator it = vec.begin();

    std::cout << "Elementos do vetor: ";
    for (; it != vec.end(); ++it) {
        std::cout << *it << " ";
    }

    return 0;
}
```
✔ **Saída:**  
```
Elementos do vetor: 10 20 30 40 50
```
💡 Aqui, o iterador percorre `vec` do **primeiro ao último elemento**.

---

## **🔹 Posicionando um iterador em uma posição específica**  
Você pode mover o iterador para uma posição específica no `vector`.  

```cpp
#include <iostream>
#include <vector>

int main() {
    std::vector<int> vec = {10, 20, 30, 40, 50};

    // Posiciona o iterador no terceiro elemento (índice 2)
    std::vector<int>::iterator it = vec.begin() + 2;

    std::cout << "O terceiro elemento é: " << *it << std::endl;

    return 0;
}
```
✔ **Saída:**  
```
O terceiro elemento é: 30
```
🛠 Aqui, usamos `vec.begin() + 2` para avançar **duas posições** e chegar ao terceiro elemento.

---

## **🔹 Usando `std::advance()` para mover o iterador**  
O `std::advance(it, n)` é uma forma segura de **mover um iterador `n` posições à frente**.

```cpp
#include <iostream>
#include <vector>
#include <iterator>  // Necessário para std::advance

int main() {
    std::vector<int> vec = {10, 20, 30, 40, 50};
    std::vector<int>::iterator it = vec.begin();

    std::advance(it, 3);  // Move 3 posições à frente

    std::cout << "O quarto elemento é: " << *it << std::endl;

    return 0;
}
```
✔ **Saída:**  
```
O quarto elemento é: 40
```
🛠 O `std::advance(it, 3)` **desloca o iterador três posições para frente**, posicionando-o no **quarto elemento**.

---

## **🔹 Movendo iteradores para o final do `vector`**
Além de `begin()`, podemos usar `end()` para obter um iterador **apontando logo após o último elemento**.  

```cpp
#include <iostream>
#include <vector>

int main() {
    std::vector<int> vec = {10, 20, 30, 40, 50};

    std::vector<int>::iterator it = vec.end() - 1;  // Último elemento

    std::cout << "O último elemento é: " << *it << std::endl;

    return 0;
}
```
✔ **Saída:**  
```
O último elemento é: 50
```
🛠 Aqui, usamos `vec.end() - 1` para apontar para o último elemento do `vector`.

---

## **🔹 Conclusão**
- **Diferente de `std::stack<T>`, `std::vector<T>` possui iteradores (`begin()`, `end()`)**.  
- Podemos **posicionar um iterador em qualquer posição**, seja usando `vec.begin() + N` ou `std::advance(it, N)`.  
- **O iterador `begin()` aponta para o primeiro elemento**, e **`end()` aponta para um local depois do último elemento**.  
- Podemos também usar **`vec.end() - 1` para acessar o último elemento do `vector`**.

Isso faz com que `std::vector<T>` seja **muito mais flexível que `std::stack<T>`** no que se refere a iteração! 🚀