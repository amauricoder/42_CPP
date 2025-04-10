### **STL Containers no C++98**  

A **STL (Standard Template Library)** no C++98 fornece uma coleção de **containers genéricos** que armazenam e gerenciam dados de maneira eficiente. Eles fazem parte do namespace `std` e são projetados para serem flexíveis, eficientes e reutilizáveis.

---

### **Tipos de Containers na STL (C++98)**  

Os containers da STL podem ser classificados em três grupos principais:

#### **1. Containers Sequenciais**
Armazenam elementos em uma sequência linear e permitem acesso ordenado.
- **`std::vector<T>`** → Array dinâmico redimensionável. (Acesso rápido O(1) por índice)
- **`std::deque<T>`** → Lista de dupla extremidade eficiente para push/pop em ambas as extremidades.
- **`std::list<T>`** → Lista duplamente ligada (eficiente para inserções/remoções em qualquer ponto, mas acesso sequencial O(n)).
  
#### **2. Containers Associativos**  
Armazenam elementos organizados por chaves para acesso rápido.
- **`std::set<T>`** → Conjunto ordenado de elementos únicos. (Baseado em árvore balanceada, O(log n) para busca/inserção)
- **`std::multiset<T>`** → Similar ao `set`, mas permite elementos duplicados.
- **`std::map<K, V>`** → Dicionário de pares chave-valor, ordenado por chave.
- **`std::multimap<K, V>`** → Similar ao `map`, mas permite múltiplos valores para a mesma chave.

#### **3. Containers Adaptadores**  
Fornecem uma in### **STL Containers no C++98**  

A **STL (Standard Template Library)** no C++98 fornece uma coleção de **containers genéricos** que armazenam e gerenciam dados de maneira eficiente. Eles fazem parte do namespace `std` e são projetados para serem flexíveis, eficientes e reutilizáveis.

---

### **Tipos de Containers na STL (C++98)**  

Os containers da STL podem ser classificados em três grupos principais:

#### **1. Containers Sequenciais**
Armazenam elementos em uma sequência linear e permitem acesso ordenado.
- **`std::vector<T>`** → Array dinâmico redimensionável. (Acesso rápido O(1) por índice)
- **`std::deque<T>`** → Lista de dupla extremidade eficiente para push/pop em ambas as extremidades.
- **`std::list<T>`** → Lista duplamente ligada (eficiente para inserções/remoções em qualquer ponto, mas acesso sequencial O(n)).
  
#### **2. Containers Associativos**  
Armazenam elementos organizados por chaves para acesso rápido.
- **`std::set<T>`** → Conjunto ordenado de elementos únicos. (Baseado em árvore balanceada, O(log n) para busca/inserção)
- **`std::multiset<T>`** → Similar ao `set`, mas permite elementos duplicados.
- **`std::map<K, V>`** → Dicionário de pares chave-valor, ordenado por chave.
- **`std::multimap<K, V>`** → Similar ao `map`, mas permite múltiplos valores para a mesma chave.

#### **3. Containers Adaptadores**  
Fornecem uma interface diferente sobre outros containers.
- **`std::stack<T>`** → Pilha (LIFO) baseada em `deque` ou `list`.
- **`std::queue<T>`** → Fila (FIFO) baseada em `deque` ou `list`.
- **`std::priority_queue<T>`** → Fila de prioridade baseada em heap binário.

---

### **Características dos Containers da STL**
- **Genéricos** → Podem armazenar qualquer tipo de dado (`T` é um tipo template).
- **Baseados em Iteradores** → Acesso eficiente aos elementos.
- **Gerenciados Automaticamente** → Memória e redimensionamento internos.

O C++98 introduziu a STL como um dos primeiros grandes avanços da linguagem, fornecendo containers e algoritmos genéricos, tornando o desenvolvimento mais eficiente e reutilizável.

Quer um exemplo prático de uso? 😊terface diferente sobre outros containers.
- **`std::stack<T>`** → Pilha (LIFO) baseada em `deque` ou `list`.
- **`std::queue<T>`** → Fila (FIFO) baseada em `deque` ou `list`.
- **`std::priority_queue<T>`** → Fila de prioridade baseada em heap binário.

---

### **Características dos Containers da STL**
- **Genéricos** → Podem armazenar qualquer tipo de dado (`T` é um tipo template).
- **Baseados em Iteradores** → Acesso eficiente aos elementos.
- **Gerenciados Automaticamente** → Memória e redimensionamento internos.

O C++98 introduziu a STL como um dos primeiros grandes avanços da linguagem, fornecendo containers e algoritmos genéricos, tornando o desenvolvimento mais eficiente e reutilizável.

Quer um exemplo prático de uso? 😊