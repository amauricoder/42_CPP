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